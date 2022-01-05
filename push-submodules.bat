:: push-submodules.bat v1.0
@echo off

cd "%~dp0"
for %%a in ("%~dp0\.") do set "parentfolder=%%~nxa"

echo.
echo Pushing all submodules of %parentfolder%...

:: Call the script in all submodules recursively
for /D %%i in (modules/*) do (
    if exist "%~dp0modules/%%i/push-to-master.bat" (
        call "%~dp0modules/%%i/push-to-master.bat" nopause
    )
)

echo Done

if [%~1] == [] (
    Pause
)