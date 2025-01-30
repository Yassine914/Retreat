@echo off

REM Call the function with the header text
call:write_header "BUILDING PROJECT: Retreat"

REM clean the build directory if specified
if "%1" == "clean" (
      call :write_text "cleaning build directory"
      if exist build rmdir /s /q build
)

if "%1" == "c" (
      call :write_text "cleaning build directory"
      if exist build rmdir /s /q build
)

REM Create a build directory if it doesn't exist
if not exist build mkdir build
pushd build

REM Run cmake if cleaning
if "%1" == "clean" (
      call :write_text "running cmake"
      cmake ../ -B . -G "Unix Makefiles"
      echo.
) else if "%1" == "c" (
      call :write_text "running cmake"
      cmake ../ -B . -G "Unix Makefiles"
      echo.
)

call :exit_if_error "CMAKE FAILED"


call :write_text "running make"
make
echo.
call :exit_if_error "MAKE FAILED"

call :write_header "RUNNING PROJECT"
.\bin\retreat

popd
exit

REM ---------------------------------------------

REM functions section

:write_header
setlocal enabledelayedexpansion
set txt=%~1
set "header_text=------ !txt! ------"
echo !header_text!

set "x="
:strlen
if defined header_text (
      set "header_text=!header_text:~1!"
      set "x=!x!-"
      goto:strlen
)
echo !x!
echo.

endlocal
goto:eof

:write_text
setlocal enableDelayedExpansion
set txt=%~1
set "header_text=------ !txt! ------"
echo !header_text!
endlocal
goto:eof


:exit_if_error
setlocal enableDelayedExpansion
if %errorlevel% neq 0 (
   echo.
   echo ERROR: %~1
   echo.
   exit /b %errorlevel%
)