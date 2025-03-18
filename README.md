<div style="text-align:center">
    <img src="documents/images/logo_256x256.png" , alt="logo" />
    <h1>Ultimate WebAssembly Virtual Machine</h1>
    <a href="https://github.com/UltiELF/uwvm/actions?query=workflow%3Auwvm-build">
      <img src="https://img.shields.io/github/actions/workflow/status/UltiELF/uwvm/uwvm.yml?branch=dev&logo=linux" alt="github-ci" />
    </a>
    <a href="LICENSE.md">
        <img src="https://img.shields.io/badge/License-Apache%202.0-green.svg" , alt="License" />
    </a>
    <a href="https://en.cppreference.com">
        <img src="https://img.shields.io/badge/language-c++23-blue.svg" ,alt="cppreference" />
    </a>
    <a
        href="http://qm.qq.com/cgi-bin/qm/qr?_wv=1027&k=ZC_7qjkJTPdDT1-mjefD-a8X5V30A_ql&authKey=CJ41sGDX5Oyut4IccWrKUdsqSfbgJztM7OiJ4etn7ruTJRpYbgi%2FIrfEEJxHOZew&noverify=0&group_code=909035408">
        <img src="https://img.shields.io/badge/chat-on%20QQ-red.svg" , alt="QQ" />
    </a>
    <a
        href="https://discord.gg/xkvGy79e">
        <img src="https://img.shields.io/badge/chat-on%20Discord-7289da.svg" , alt="Discord" />
    </a>
    <a
        href="https://kook.top/L7rWIo">
        <img src="https://img.shields.io/badge/chat-on%20KOOK-6bff1d.svg" , alt="KOOK" />
    </a>
</div>

> [!IMPORTANT]
> This version has been deprecated. See [uwvm2](https://github.com/Ulte/uwvm2) for the new version.
>

|[简体中文](README.zh_CN.md)|

## Contact Us

- [Discord](https://discord.gg/xkvGy79e)
- [KOOK](https://kook.top/L7rWIo)
- QQ: [909035408](http://qm.qq.com/cgi-bin/qm/qr?_wv=1027&k=ZC_7qjkJTPdDT1-mjefD-a8X5V30A_ql&authKey=CJ41sGDX5Oyut4IccWrKUdsqSfbgJztM7OiJ4etn7ruTJRpYbgi%2FIrfEEJxHOZew&noverify=0&group_code=909035408)
- repositories: [Gitee](https://gitee.com/UltiELF/uwvm), [GitCode](https://gitcode.com/MacroModel/uwvm), [GitHub](https://github.com/Ulte/uwvm)

## Introduce
Ultimate WebAssembly Virtual Machine

## Commandline interface
* Get version information
```bash
$ uwvm --version
```
* Get a list of commands
```bash
$ uwvm --help
```
* Running uwvm virtual machine
```bash
$ uwvm <param1> <param2> ... --run <file> <argv1> <argv2> ...
```
* Running mode
```bash
--mode [objdump, int(default), ucint]
# int: interpreter, wasm data stack and local data stack can be expanded and checked; Memory operation check; and so on
# ucint: Some do not check the interpreter, and the size of the wasm data stack is fixed without checking. Virtual machine security is protected by setting the leftmost and rightmost pages of the data stack with no read/write execution permissions; The local data stack uses the thread's own stack; Memory operation check; And so on; 125% faster performance than interpreter
```
* Loading WASM ABI (default auto detection)
```bash
--abi [bare|emscripten|wasi]
```

## Features
### Feature Extensions
| Standardized features                                                                                                                              |     parameters                       |
|----------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------|
| [MVP](https://github.com/WebAssembly/design/blob/main/BinaryEncoding.md)                                                                           |  V1.0.0                              |
| [JS BigInt to Wasm i64 integration](https://github.com/WebAssembly/JS-BigInt-integration)                                                          |  N/A                                 |
| [Bulk memory operations](https://github.com/WebAssembly/bulk-memory-operations/blob/master/proposals/bulk-memory-operations/Overview.md)           |  V1.0.1                              |
| [Extended constant expressions](https://github.com/WebAssembly/extended-const/blob/master/proposals/extended-const/Overview.md)                    |  :x:                                 |
| [Garbage collection](https://github.com/WebAssembly/gc)                                                                                            |  :x:                                 |
| [Multiple memories](https://github.com/WebAssembly/multi-memory/blob/master/proposals/multi-memory/Overview.md)                                    |  ```--enable-multi-memory```         |
| [Multi-value](https://github.com/WebAssembly/spec/blob/master/proposals/multi-value/Overview.md)                                                   |  V1.0.1                              |
| [Mutable globals](https://github.com/WebAssembly/mutable-global/blob/master/proposals/mutable-global/Overview.md)                                  |  V1.0.1                              |
| [Reference types](https://github.com/WebAssembly/reference-types/blob/master/proposals/reference-types/Overview.md)                                |  V1.0.1                              |
| [Relaxed SIMD](https://github.com/WebAssembly/relaxed-simd/tree/main/proposals/relaxed-simd)                                                       |  ```--enable-relaxed-simd```         |
| [Non-trapping float-to-int conversions](https://github.com/WebAssembly/spec/blob/master/proposals/nontrapping-float-to-int-conversion/Overview.md) |  V1.0.1                              |
| [Sign-extension operations](https://github.com/WebAssembly/spec/blob/master/proposals/sign-extension-ops/Overview.md)                              |  :x:                                 |
| [Fixed-width SIMD](https://github.com/WebAssembly/simd/blob/master/proposals/simd/SIMD.md)                                                         |  ```--enable-fixed-width-simd```     |
| [Extended constant expressions](https://github.com/WebAssembly/extended-const/blob/master/proposals/extended-const/Overview.md)                    |  :x:                                 |
| [Tail calls](https://github.com/WebAssembly/tail-call/blob/master/proposals/tail-call/Overview.md)                                                 |  :x:                                 |
| [Threads and atomics](https://github.com/WebAssembly/threads/blob/master/proposals/threads/Overview.md)                                            |  ```--enable-thread```               |
| [Exception handling](https://github.com/WebAssembly/exception-handling/blob/master/proposals/exception-handling/Exceptions.md)                     |  ```--enable-exception-handling```   |
| [JS Promise Integration](https://github.com/WebAssembly/js-promise-integration)                                                                    |  N/A                                 |
| [Memory64](https://github.com/WebAssembly/memory64/blob/master/proposals/memory64/Overview.md)                                                     |  ```--enable-memory64```             |
| [Custom Page Sizes](https://github.com/WebAssembly/custom-page-sizes/blob/main/proposals/custom-page-sizes/Overview.md)                            |  ```--enable-custom-page-sizes```    |
| [Type reflection](https://github.com/WebAssembly/js-types/blob/main/proposals/js-types/Overview.md)                                                |  :x:                                 |
| [Sign-extension operators](https://github.com/WebAssembly/sign-extension-ops/blob/master/proposals/sign-extension-ops/Overview.md)                 |  V1.0.1                              |
| [WASI](https://github.com/WebAssembly/WASI)                                                                                                        |  V1.0.1                              |
| [WASI Preview 2](https://github.com/WebAssembly/WASI/blob/main/preview2/README.md)                                                                 |  :x:                                 |
| [WASIX](https://wasix.org/)                                                                                                                        |  :x:                                 |

### Supports multiple platforms
* (x86\_64, i386, aarch64, arm)-windows-(gnu, msvc) (support UCRT and MSVCRT)
* (x86\_64, i386, aarch64, arm, loongarch64, riscv64, mips64, powerpc64, etc.)-linux-(gnu, musl, llvm, mlibc, uclibc, avrlibc, etc.)
* (x86\_64, i386, aarch64, arm)-linux-android
* (x86\_64, i386, aarch64, arm, powerpc, powerpc64, powerpc64le, powerpcspe, riscv64)-freebsd
* unknown-dragonflybsd
* unknown-netbsd
* unknown-openbsd
* unknown-bsd
* unknown-sun
* unknwon-apple-darwin
* i386-msdosdjgpp
* wasm32-wasip1, wasm32-wasip2, wasm64-wasip1, wasm64-wasip2, wasm32-wasip1-threads, wasm32-wasip2-threads, wasm64-wasip1-threads, wasm64-wasip2-threads (bootstrap)
* etc.

## How to build
1. Install [[xmake]](https://github.com/xmake-io/xmake/)
```bash
$ sudo apt install xmake
```
2. Install [[gcc13+]](https://github.com/gcc-mirror/gcc) or [[llvm17+]](https://github.com/llvm/llvm-project)
```bash
$ sudo apt install gcc g++
```
3. Build
```bash
$ xmake 
$ xmake install -o OutputPath 
```
4. Build parameters
```bash
$ xmake f -m [release|releasedbg|debug] -p [windows|mingw|macosx|linux|iphoneos ..] -a [x86_64|i386|arm|aarch64 ..] --cppstdlib=[default|libstdc++|libc++] ..
```
* Currently, only MSVC 14.30+ GCC 14+ and LLVM 18+ are supported.
* It is recommended to use llvm or msvc on Windows. The results of gcc's libgcc have problems with the implementation of tls, resulting in 10 times slower efficiency.
* Please add the parameter ``` --static=n ``` when compiling on Android. Android cannot statically link libc。

* To compile systems compatible with Win10 (default) or below, please add parameters
```bash 
--min-win32-sys=[WIN10|WINBLUE|WIN8|WIN7|WS08|VISTA|WS03|WINXP|WIN2K] 
```
* For Windows 9x (i386-windows-gnu)
```bash 
--min-win32-sys=[WINME|WIN98|WIN95]
```
* Using the llvm toolchain (This option must be added to some platforms that use gcc soft connection to clang, such as macos and android)
```bash 
--use-llvm=y|n(default)
```
* Use ucint (c++ exceptions will be automatically disabled at the same time)
```bash 
--uwvm-enable-ucint=y|n(default)
```
* Compile using local instruction sets
```bash 
--native=y|n(default)
```
* Select toolchain
```bash 
--sdk=ToolchainPath
```
* Static linking
```bash 
--static=y(defalut)|n
```
* Set sysroot
```bash 
--sysroot=<path>
```
* Record the time of each step
```bash 
--timer=y|n(default)
```
* Use mimalloc as the default allocator
```bash 
--use-mimalloc=y|n(default)
```
* Disable c++ exceptions (some WASIs cannot be used)
```bash
--fno-exceptions=y|n(default)
```
* Enable Sanitizer
```bash 
--policies=build.sanitizer.address --policies=build.sanitizer.leak
```

