@echo off

echo   _____            ____           ____             
echo  ^|       ^|        /        /\    ^|    \  ^|  ^|\  /^| 
echo  ^|_____  ^|       ^|        /  \   ^|____/  ^|  ^| \/ ^| 
echo  ^|       ^|       ^|       ^|----^|  ^|   \   ^|  ^|    ^| 
echo  ^|_____  ^|_____   \____  ^|    ^|  ^|    \  ^|  ^|    ^| 
echo.
echo ----------------- Project Setup -------------------
echo -------------------- Windows ----------------------
echo.
echo.
echo ------------------------------
echo ----- Cloning submodules -----
echo ------------------------------
echo.
git submodule init
git submodule update
echo.
pause
echo.
echo.
echo ----------------------------
echo ----- Setting up vcpkg -----
echo ----------------------------
echo.
call vcpkg\bootstrap-vcpkg.bat
echo.
pause
echo.
echo.
echo -----------------------------------
echo ----- Installing dependencies -----
echo -----------------------------------
echo.
echo ----- GLFW3 -----
.\vcpkg\vcpkg install glfw3:x64-windows
echo.
echo ----- GLM -----
.\vcpkg\vcpkg install glm:x64-windows
echo.
echo ----- GLAD -----
.\vcpkg\vcpkg install glad[gl-api-32]:x64-windows
echo.
echo ----- STB -----
.\vcpkg\vcpkg install stb:x64-windows
echo.
pause
