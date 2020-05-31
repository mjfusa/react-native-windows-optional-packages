#uninstall
Get-AppxPackage *myrnProject* | Remove-AppxPackage
#install main package
Add-AppxPackage .\AppPackages\out.appxbundle
#install optional package
Add-AppxPackage .\OptionalPackage1\AppPackages\OptionalPackage1_1.0.1.0_x64_Debug_Test\OptionalPackage1_1.0.1.0_x64_Debug.appx
