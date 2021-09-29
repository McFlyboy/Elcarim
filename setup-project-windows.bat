@echo off

git submodule init
git submodule update

.\vcpkg\bootstrap-vcpkg.bat

.\vcpkg\vcpkg install glfw3:x64-windows
.\vcpkg\vcpkg install glm:x64-windows
.\vcpkg\vcpkg install glad[gl-api-32]:x64-windows
.\vcpkg\vcpkg install stb:x64-windows
