﻿#pragma once
#include <fast_io.h>
#include <fast_io_freestanding.h>

#include <io_device.h>

#include <cmdline/parameter.h>
#include "../../vm/interpreter/ast.h"
#if UWVM_ENABLE_UNCHECKED_INTERPRETER &&                                                                                                                       \
    ((defined(_WIN32) || defined(__CYGWIN__)) ||                                                                                                               \
     (!defined(__NEWLIB__) && !defined(__MSDOS__) && (!defined(__wasm__) || (defined(__wasi__) && defined(_WASI_EMULATED_MMAN))) && __has_include(<sys/mman.h>)))
    #include "../../vm/unchecked_interpreter/stack/stack.h"
#endif
namespace uwvm::parameter
{
    namespace details
    {
        inline bool default_int_stack_size_is_exist{};
        inline constexpr ::fast_io::string_view default_int_stack_size_alias{"-dssz"};

        inline ::uwvm::cmdline::parameter_return_type
            default_int_stack_size_callback(::uwvm::cmdline::parameter_parsing_results* sres,
                                            ::fast_io::vector<::uwvm::cmdline::parameter_parsing_results>& pres) noexcept
        {
            auto sresp1{sres + 1};
            if(sresp1 == pres.cend() || sresp1->type != ::uwvm::cmdline::parameter_parsing_results_type::arg) [[unlikely]]
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
                            u8"[error] "
#ifdef __MSDOS__
                            u8"\033[37m"
#else
                            u8"\033[97m"
#endif
                            u8"Usage: "
                            u8"\033[36m"
                            u8"[--default-stack-size|-dssz] "
                            u8"\033[32m"
                            u8"<size_t>"
                            u8"\033[0m"
                            u8"\n\n");
                return ::uwvm::cmdline::parameter_return_type::return_m1_imme;
            }

            sresp1->type = ::uwvm::cmdline::parameter_parsing_results_type::occupied_arg;

            auto const s1s{sresp1->str};

            ::std::size_t diss{};
            auto const [next, err]{::fast_io::parse_by_scan(s1s.cbegin(), s1s.cend(), diss)};

            if(err != ::fast_io::parse_code::ok || next != s1s.cend()) [[unlikely]]
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
                            u8"[error] "
#ifdef __MSDOS__
                            u8"\033[37m"
#else
                            u8"\033[97m"
#endif
                            u8"Usage: "
                            u8"\033[36m"
                            u8"[--default-stack-size|-dssz] "
                            u8"\033[32m"
                            u8"<size_t>"
                            u8"\033[0m"
                            u8"\n\n");
                return ::uwvm::cmdline::parameter_return_type::return_m1_imme;
            }

            if(diss == 0) [[unlikely]]
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
                            u8"[error] "
#ifdef __MSDOS__
                            u8"\033[37m"
#else
                            u8"\033[97m"
#endif
                            u8"Stack size cannot be zero."
                            u8"\n\n");
                return ::uwvm::cmdline::parameter_return_type::return_m1_imme;
            }

            ::uwvm::vm::interpreter::stack_machine::default_int_stack_size = diss;
#if UWVM_ENABLE_UNCHECKED_INTERPRETER &&                                                                                                                       \
    ((defined(_WIN32) || defined(__CYGWIN__)) ||                                                                                                               \
     (!defined(__NEWLIB__) && !defined(__MSDOS__) && (!defined(__wasm__) || (defined(__wasi__) && defined(_WASI_EMULATED_MMAN))) && __has_include(<sys/mman.h>)))
            ::uwvm::vm::unchecked_interpreter::stack::stack_t::default_stack_size = diss;
#endif
            return ::uwvm::cmdline::parameter_return_type::def;
        }
    }  // namespace details

    inline constexpr ::uwvm::cmdline::parameter default_int_stack_size{
        .name{::fast_io::string_view{"--default-stack-size"}},
        .describe{::fast_io::u8string_view{u8"Set the initial stack and local size of the interpreter (unit stack, default="
                                           u8"1024"
                                           u8"). Usage: [--default-stack-size|-dssz] <size_t>"}},
        .alias{::uwvm::cmdline::kns_str_scatter_t{__builtin_addressof(details::default_int_stack_size_alias), 1}},
        .callback{__builtin_addressof(details::default_int_stack_size_callback)},
        .is_exist{__builtin_addressof(details::default_int_stack_size_is_exist)},
    };
}  // namespace uwvm::parameter
