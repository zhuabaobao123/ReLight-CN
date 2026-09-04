@echo off
set SRC_DIR=E:\ReLight-src-7.1
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
set COMMONLIB_SSE_FOLDER=E:\CommonLibSSE-NG-alandtse
set VCPKG_ROOT=E:\vcpkg
cmake -S %SRC_DIR% -B %SRC_DIR%\build\release -G Ninja -DCMAKE_BUILD_TYPE=Release -DVCPKG_TARGET_TRIPLET=x64-windows-static -DVCPKG_OVERLAY_PORTS=%SRC_DIR%\cmake\ports -DVCPKG_OVERLAY_TRIPLETS=%SRC_DIR%\cmake -DCMAKE_TOOLCHAIN_FILE=E:\vcpkg\scripts\buildsystems\vcpkg.cmake -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreaded "-DCMAKE_CXX_FLAGS=/utf-8 -DNOMINMAX -DUNICODE -D_UNICODE"
cmake --build %SRC_DIR%\build\release -j 8
