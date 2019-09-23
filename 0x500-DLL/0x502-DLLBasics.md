# 0x502 - DLL
## Dynamic Libraries
A **Dynamic Link Library** (DLL) is a library that is loaded separately from the program that uses it. The advantage of DLLs is that you can load one DLL into memory, and multiple programs can use it. This decreases the size of programs.

## Static Libraries
A **static library** is linked directly to/with the program that uses it. A library that is statically linked cannot be used by multiple programs at once. The library is part of the program it is used in. This makes the program bigger because of the extra code.
___
## Imports vs Exports
* **Import** - Something brought in from an external source. To use a function from a library you import that function from the library.
* **Export** - Something exposed to the outside so other sources can import it. You're able to access a function from a DLL because the DLL has exported that function. Because it's exported, your program can import it.

[<- Previous Lesson](0x501-DLLBasics.md)  
[Next Lesson ->](0x503-Exports.md)  

[Chapter Home](0x500-DLL.md)  
[Course Home](../README.md)  