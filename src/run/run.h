﻿#pragma once
#include <cstddef>
#include <fast_io.h>
#ifdef UWVM_TIMER
    #include <fast_io_driver/timer.h>
#endif
#include <io_device.h>
#include "wasm_file.h"
#include "init.h"
#include "../clpara/parsing_result.h"
#include "../wasm/scan.h"
#include "../wasm/custom.h"
#include "objdump.h"
#include "../vm/interpreter/int.h"
#if UWVM_ENABLE_UNCHECKED_INTERPRETER &&                                                                                                                                                   \
    ((defined(_WIN32) || defined(__CYGWIN__)) ||                                                                                                               \
     (!defined(__NEWLIB__) && !defined(__MSDOS__) && (!defined(__wasm__) || (defined(__wasi__) && defined(_WASI_EMULATED_MMAN))) && __has_include(<sys/mman.h>)))
    #include "../vm/unchecked_interpreter/ucint.h"
#endif

namespace uwvm
{
    inline void run() noexcept
    {
        // no input file

        if(::uwvm::global_wasm_module.module_name.empty()) [[unlikely]]
        {
            ::fast_io::io::perr(::uwvm::u8err,
                                u8"\033[0m"
#ifdef __MSDOS__
                                u8"\033[37m"
#else
                                u8"\033[97m"
#endif
                                u8"uwvm: "
                                u8"\033[31m"
                                u8"[fatal] "
                                u8"\033[0m"
#ifdef __MSDOS__
                                u8"\033[37m"
#else
                                u8"\033[97m"
#endif
                                u8"No input file.\n"
                                u8"\033[0m"
                                u8"Terminate.\n\n");
            ::fast_io::fast_terminate();
        }
#ifdef __cpp_exceptions
        try
#endif
        {
#ifdef UWVM_TIMER
            ::fast_io::timer file_loader_timer{u8"uwvm: [timer] file loader"};
#endif
            ::uwvm::wasm_file_loader = ::fast_io::native_file_loader{
                ::fast_io::mnp::os_c_str_with_known_size(::uwvm::global_wasm_module.module_name.data(), ::uwvm::global_wasm_module.module_name.size())};
        }
#ifdef __cpp_exceptions
        catch(::fast_io::error e)
        {
            ::fast_io::io::perr(::uwvm::u8err,
                                u8"\033[0m"
    #ifdef __MSDOS__
                                u8"\033[37m"
    #else
                                u8"\033[97m"
    #endif
                                u8"uwvm: "
                                u8"\033[31m"
                                u8"[fatal] "
                                u8"\033[0m"
    #ifdef __MSDOS__
                                u8"\033[37m"
    #else
                                u8"\033[97m"
    #endif
                                u8"Unable to open WASM file \"",
                                ::uwvm::global_wasm_module.module_name,
                                u8"\": ",
                                e,
                                u8"\n"
                                u8"\033[0m"
                                u8"Terminate.\n\n");
            ::fast_io::fast_terminate();
        }
#endif

        ::uwvm::init();

        auto const begin{reinterpret_cast<::std::byte const*>(::uwvm::wasm_file_loader.cbegin())};
        auto const end{reinterpret_cast<::std::byte const*>(::uwvm::wasm_file_loader.cend())};

        ::uwvm::wasm::scan_wasm_module(::uwvm::global_wasm_module, ::uwvm::global_wasm_module.module_name, begin, end);

        switch(::uwvm::running_mode)
        {
            case ::uwvm::mode::objdump:
            {
                ::uwvm::u8objdump();
                break;
            }
            case ::uwvm::mode::interpreter:
            {
                ::uwvm::vm::interpreter::interpret();
                break;
            }
#if UWVM_ENABLE_UNCHECKED_INTERPRETER &&                                                                                                                                                   \
    ((defined(_WIN32) || defined(__CYGWIN__)) ||                                                                                                               \
     (!defined(__NEWLIB__) && !defined(__MSDOS__) && (!defined(__wasm__) || (defined(__wasi__) && defined(_WASI_EMULATED_MMAN))) && __has_include(<sys/mman.h>)))
            case ::uwvm::mode::unchecked_interpreter:
            {
                ::uwvm::vm::unchecked_interpreter::unchecked_interpret();
                break;
            }
#endif
            default: ::fast_io::unreachable();
        }
    }
}  // namespace uwvm
