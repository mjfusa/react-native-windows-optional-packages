if "%2" NEQ "" goto release
REM Debug
MakeAppx.exe bundle  /o /p AppPackages\out.appxbundle /f Bundle.Mapping2.txt
goto sign
:release
REM Release
MakeAppx.exe bundle  /o /p AppPackages\out.appxbundle /f Release.Bundle.Mapping.txt
:sign
signtool.exe sign -p a -f myrnProject\myrnProject_TemporaryKey.pfx -fd SHA256 -v AppPackages\out.appxbundle
powershell -f .\installApp.ps1