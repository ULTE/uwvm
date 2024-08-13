﻿__builtin_addressof(::uwvm::parameter::version), __builtin_addressof(::uwvm::parameter::help), __builtin_addressof(::uwvm::parameter::abi),
    __builtin_addressof(::uwvm::parameter::run), __builtin_addressof(::uwvm::parameter::enable_memory64), __builtin_addressof(::uwvm::parameter::mode),
    __builtin_addressof(::uwvm::parameter::load), __builtin_addressof(::uwvm::parameter::default_int_stack_size),
    __builtin_addressof(::uwvm::parameter::default_local_size), __builtin_addressof(::uwvm::parameter::wasi_mount_root),
    __builtin_addressof(::uwvm::parameter::wasi_fd_limit), __builtin_addressof(::uwvm::parameter::start_func),

    // features
    __builtin_addressof(::uwvm::parameter::enable_relaxed_simd), __builtin_addressof(::uwvm::parameter::enable_exception_handling),
    __builtin_addressof(::uwvm::parameter::enable_multi_memory), __builtin_addressof(::uwvm::parameter::enable_fixed_width_simd),
    __builtin_addressof(::uwvm::parameter::enable_thread), __builtin_addressof(::uwvm::parameter::enable_custom_page_sizes),

#ifdef UWVM_DEFAULT_MVP
    __builtin_addressof(::uwvm::parameter::enable_multi_value), __builtin_addressof(::uwvm::parameter::enable_sign_extension_ops),
    __builtin_addressof(::uwvm::parameter::enable_mutable_globals), __builtin_addressof(::uwvm::parameter::enable_reference_types),
    __builtin_addressof(::uwvm::parameter::enable_bulk_memory_operations), __builtin_addressof(::uwvm::parameter::enable_non_trapping_float_to_int_conversion),

    // features collection
    __builtin_addressof(::uwvm::parameter::enable_regular_extension),
#endif
