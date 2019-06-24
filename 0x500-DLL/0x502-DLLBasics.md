# DLL
A **Dynamic Link Library** (DLL) is a library that is loaded separately from the program that uses it. The advantage of DLLs is that you can load one DLL into memory, and multiple programs can use it. This decreases the size of programs.

## Imports vs Exports
* **Import** - Something brought in from an external source. When you use a library you are importing it.
* **Export** - Something exposed to the outside so other sources can import it. You're able to access a function from a DLL because the DLL has exported that function. Because it's exported, your program can use the function.

## Static Libraries
A **static library** is linked directly to/with the program that uses it. A library that is statically linked cannot be used by multiple programs at once. The library is part of the program it is used in. This makes the program bigger because of the extra code.