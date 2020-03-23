DLL.dll is the DLL to be reversed.

RunDLL.exe is a program which will call the exported functions of DLL.dll.
DLL.dll needs to be in the same folder as RunDLL.exe.

DLLLib.exe is a program that runs DLL.dll however it uses a .lib and .h file. If you're debugging with RunDLL.exe you may encounter access violation issues due to how it works. If that is the case then use DLLLib.exe instead. To use DLLLib.exe the .h and .lib files need to be in the same location as DLLLib.exe.

The SourceCode folder contains the source code for the programs.

The DebugFiles folder contains debug files that can be used to resolve symbols if you want.
Place the debug files in the same folder as RunDLL.exe and DLL.dll.
