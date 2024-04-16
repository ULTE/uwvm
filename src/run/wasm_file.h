﻿#pragma once
#include <cstddef>
#include <fast_io.h>
#include <fast_io_dsal/cstring_view.h>
#include <fast_io_dsal/string.h>
#include "../wasm/abi.h"
#include "../wasm/module.h"
#include "mode.h"

namespace uwvm
{
    inline ::fast_io::native_file_loader wasm_file_loader{};

    inline ::uwvm::mode running_mode{::uwvm::mode::objdump};

    inline ::uwvm::wasm::abi wasm_abi{::uwvm::wasm::abi::detect};
    inline ::uwvm::wasm::wasm_module global_wasm_module{};
    inline ::fast_io::u8string global_wasm_module_name_storge{};

}  // namespace uwvm
