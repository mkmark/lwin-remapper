"C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
cl /EHsc /I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um" /O2 lwin-remapper.cpp /link /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um" User32.lib /SUBSYSTEM:WINDOWS
