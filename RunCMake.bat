REM
REM RunCMake.bat
REM
REM Build Xerces C with CMake


if '%1' == '' goto usage
if '%2' == '' goto usage
SET A5XERCESVERSION=%1
SET A5XERCESCOMPILERVERSION=%2

SET A5CMAKE=c:\dev\3rdparty\cmake\3.21.4\bin\cmake.exe
SET A5XERCESPATH=C:\dev\3rdParty\Xerces\%A5XERCESVERSION%
SET A5XERCESUNIXPATH=C:/dev/3rdParty/Xerces/%A5XERCESVERSION%

SET A5XERCESBUILDPATH=%A5XERCESPATH%\Build\%A5XERCESCOMPILERVERSION%

REM Create BuildDirectories
mkdir %A5XERCESPATH%\Build
mkdir %A5XERCESBUILDPATH%

REM
REM Build with Visual Studio 
REM
cd c:\dev\a5v12\src
call SetBuildEnvironment.bat
SET A5COMPILERVERSIONSAVE=%A5COMPILERVERSION%

call SetCompilerEnvironment.bat %A5XERCESCOMPILERVERSION%
call SetBuildEnvironment.bat
call SetBuildEnvironment.bat display

ECHO Configure for Win32
REM
cd %A5XERCESBUILDPATH%
"%A5CMAKE%" %A5XERCESPATH% -G "%A5CMAKEGENERATOR%" -A Win32


REM *****************************************************************************
REM **** Do Release
REM **** Do Release
REM *****************************************************************************
REM Clean any previous build
cd %A5XERCESBUILDPATH%
devenv xerces-c.sln /clean

REM Do the build
cd %A5XERCESBUILDPATH%
devenv xerces-c.sln /build Release

REM *****************************************************************************
REM **** Do Debug
REM **** Do Debug
REM *****************************************************************************
REM Clean any previous build
cd %A5XERCESBUILDPATH%
devenv xerces-c.sln /clean

REM Do the build
cd %A5XERCESBUILDPATH%
devenv xerces-c.sln /build Debug

REM *****************************************************************************
REM *****************************************************************************



echo Build of XERCES version %A5XERCESVERSION% with compiler version %A5XERCESCOMPILERVERSION% completed.

if '%A5COMPILERVERSIONSAVE%' == '%A5COMPILERVERSION%' goto done

echo Setting Compiler version back to %A5COMPILERVERSIONSAVE%
cd c:\dev\a5v12\src
call SetCompilerEnvironment.bat %A5COMPILERVERSIONSAVE%
call SetBuildEnvironment.bat display
echo ----------------------------------------------------------------------------
echo NOTE! Compiler version has been changed from %A5COMPILERVERSIONSAVE% to %A5XERCESCOMPILERVERSION% and back to %A5COMPILERVERSION%
echo Please make sure this matches your expectations.
echo ----------------------------------------------------------------------------
cd %A5XERCESPATH%

goto done 

:usage

echo Usage: %0 version compilerversion
echo For example:  %0 3.2.2 VS16

:done

