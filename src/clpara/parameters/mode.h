﻿#pragma once

#include <fast_io.h>

#include <io_device.h>

#include <cmdline/parameter.h>

namespace uwvm::parameter
{
    namespace details
    {
        inline bool mode_is_exist{};
        inline constexpr ::fast_io::string_view mode_alias{"-m"};
        extern ::uwvm::cmdline::parameter_return_type mode_callback(::uwvm::cmdline::parameter_parsing_results*,
                                                                    ::fast_io::vector<::uwvm::cmdline::parameter_parsing_results>&) noexcept;
    }  // namespace details

    inline constexpr ::uwvm::cmdline::parameter mode{
        .name{::fast_io::string_view{"--mode"}},
        .describe{::fast_io::u8string_view{u8"Select operation mode. Usage: [--mode|-m] [objdump, int(default)"
#if UWVM_ENABLE_UNCHECKED_INTERPRETER &&                                                                                                                                                   \
    ((defined(_WIN32) || defined(__CYGWIN__)) ||                                                                                                               \
     (!defined(__NEWLIB__) && !defined(__MSDOS__) && (!defined(__wasm__) || (defined(__wasi__) && defined(_WASI_EMULATED_MMAN))) && __has_include(<sys/mman.h>)))
                                           u8", ucint"
#endif
                                           u8"]"}},
        .alias{::uwvm::cmdline::kns_str_scatter_t{__builtin_addressof(details::mode_alias), 1}},
        .callback{__builtin_addressof(details::mode_callback)},
        .is_exist{__builtin_addressof(details::mode_is_exist)},
    };
}  // namespace uwvm::parameter
