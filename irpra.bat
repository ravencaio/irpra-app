@echo off

if /i "%~1" == "-e" (
    for /f %%i in ('irpra_handler.exe %2') do (
	cd /d %%i
    explorer.exe %%i
)
) else (
    for /f %%i in ('irpra_handler.exe %1') do cd /d %%i
)