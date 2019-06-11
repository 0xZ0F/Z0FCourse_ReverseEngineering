# Memory Layout - WIP
The systems memory is divided into several sections. I prefer to imagine the stack with low address at the top and high addresses at the bottom. The reason for this is because it's more like a normal numeric list and it's how you'll most often see it being represented. Also, I'm pretty sure that's how your computer sees it. Be warned though, you will see people represent the memory layout as starting from higher addresses.

## Assembly Segments
Before we get into memory sections, we need to talk about Assembly segments. There are three main segments.
* **.data** - Contains global and static variables. This segment is a fixed size.
* **.bss** - Contains variables that are not explicitly initialized to any value. These variables are often zeroed out when the program starts.
* **.text** - Contains the code of the program. It should be called .code but I don't make the rules. The start of the program code is declared with "global _start".

## Overview of Memory Sections
* **Stack** - Area in memory that can be used quickly for static data allocation. Data is read and written as "last-in-first-out" (LIFO). The LIFO structure of the stack is often represented with a stack of plates. You can't simply take out the third plate from the top, you have to take off one plate at a time to get to it. The way I see it is that only the piece of data on the very top of the stack is accessible, so to access other data you need to move what's on the top out of the way. The static data allocation refers to data that has a known length. An integer will only be 4 bytes so we can through that on the stack. Unless a maximum length is specified, user input should be stored on the heap because of it's variable size.
* **Heap** - Similar to the stack but used for dynamic allocation and it's slower. The heap is typically used for data that is more dynamic (changing or unpredictable). This includes structures, user input, etc. If the size of the data isn't known at compile-time, it's usually stored on the heap.
* **Program Image** - This is the program loaded into memory. On Windows this is typically a **Portable Executable (PE)**.
* **DLL** - **Dynamic Link Library (DLL)**. These can be used by programs.
* **TEB** - The **Thread Environment Block (TEB)** stores information about the currently running thread(s).
* **PEB** - The Process Environment Block (PEB) stores information about the process and the loaded modules such as "BeingDebugged" which can be used to determine if the current process is being debugged.  
MSDN: https://docs.microsoft.com/en-us/windows/desktop/api/winternl/ns-winternl-_peb

Here is a general overview of how memory is laid out in Windows. **This is extremely simplified.**
<p align="center">
  <img src="[ignore]/WindowsMemoryLayout.png">
</p>

## Stack Frames
Stack frames are basically chunks of data for functions. This data includes local variables, saved base pointer, the return address of the caller, and function parameters. Consider the following example:
```c
int Square(int x){
    return x^2;
}
int main(){
    int num = 5;
    Square(5);
}
```
In this example the `main` function is called first. When `main` is called a stack frame is created for it. This stack frame includes local variables, the saved (old) base pointer, the return address, and the parameters passed to the function. The base pointer is saved so it can later be restored when the function returns. This ensures that the stacks don't get all wonky. The return address is the address of the instruction after the instruction that called the function. That may sound confusing, hopefully this can clear it up:
```asm
mov RAX, 15
call func   ;Instruction that calls func
mov RBX, 23 ;Instruction after the call which is the saved return address for the previous call.
```
It's simply telling the computer where to go (what instruction to execute) when the function returns. You don't want it to execute the instruction that called the function because that will cause an infinite loop. This is why the next instruction is used as the return address instead.  
Here is the layout:
<p align="center">
  <img src="[ignore]/StackFrameLayout.png">
</p>

## Windows x64 Calling Convention