# Instructions - TODO
Let's talk about some Assembly instructions. Before we get started there are three different terms you should know: **immediate**, **register**, and **memory**. 
* An **immediate value** is something like the number 12 (the kind of number we humans use). An immediate value is not a memeory address or register, instead it's some sort of constant. 
* A **register** is referring to something like RAX, RBX, R12, AL, etc. 
* **Memory** or a **memory address** refers to a location in memory (a memory address) such as 0x7FFF842B.

> You may see a semicolon at the end of, or in-between, a few Assembly instructions. This is because the semicolon (;) is used to write a comment in Assembly.

It's important to know the format of instructions which is as follows:  
**(Instruction/Opcode/Mnemonic) \<Destination Operand\>, \<Source Operand\>**  
> I will be referring to Instructions/Opcodes/Mnemonics as instructions. They all mean the same thing in Assembly.

Example:
```asm
mov RAX, 5
```
**MOV** is the instruction, RAX is the destination operand, and 5 is the source operand. Capitalization of instructions or operands does not matter. You will see me use a mixture of all letters capitalized and all letters lowercase.

# Common Instructions
## Data:
**MOV** is used to move/store the source operand into the destination. The source doesn't have to be an immediate value like it is in the following example. In the following example the immediate value of 5 is being moved into RAX.  
This is equalivilant to RAX = 5.
```asm
mov RAX, 5
```

**PUSH** is used to push data onto the stack. Pushing refers to putting something on the top of the stack. In the following example RAX is pushed onto the stack. Pushing will act like a copy so RAX will still contain the value it had before it was pushed.
```asm
push RAX
```

**POP** is used to take whatever is on the top of the stack and store it in the destination. In the following example whatever is on the top of the stack will be put into RAX.
```asm
pop RAX
```

### Arithmetic:
**INC** will increment data by one. In the following example RAX is set to 8, then incremented. RAX will be 9 by the end.
```asm
mov RAX, 8
inc RAX
```
**DEC** decrements a value. In the following example RAX ends with a value of 7.
```asm
mov RAX, 8
dec RAX
```
**ADD** adds a source to a destination and stores the result in the destination. In the following example 2 is moved into RAX, 3 into RBX, then they are added together. The result (5) is then stored in RAX.  
Same as RAX = RAX + RBX or RAX += RBX.
```asm
mov RAX, 2
mov RBX, 3
add RAX, RBX
```
**SUB** subtracts a source from a destination and stores the result in the destination. In the following example RAX will end with a value of 2.  
Same as RAX = RAX - RBX or RAX -= RBX.
```asm
mov RAX, 5
mov RBX, 3
add RAX, RBX
```
**MUL** (unsigned) or **IMUL** (signed) multiplies the destination by the source. The result is stored in the destination. IMUL is used for signed and MUL is used for unsigned. In the following example RAX will end with a value of 15.
```asm
mov RAX, 5
mov RBX, 3
mul RAX, RBX
```
**DIV** (unsigned) or **IDIV** (signed). - I'll put my own explanation here eventually (maybe). For now just follow these links:
* **DIV**: https://www.felixcloutier.com/x86/div
* **IDIV**: https://www.felixcloutier.com/x86/idiv

### Flow:
**CMP** compares two operands and sets the appropriate flags depending on the result. The following would set the Zero Flag (ZF) to 1 which means the comparison determined that RAX was equal to five. Flags are talked about in the next section [0x204-Flags.md](0x204-Flags.md).
```asm
mov RAX, 5
cmp RAX, 5
```
**JCC** instructions are conditional jumps that jump based on the flags that are currently set. JCC is not an instruction, but a set of instructions that includes JNE, JLE, JNZ, and many more. JNE is jump if not equal, and JLE is jump if less than or equal. This is often used in if statements. The following example will quit immediately if RAX isn't equal to 5. If it is equal to 5 then it will set RBX to 10, then quit.
```asm
mov RAX, 5
cmp RAX, 5
jne 5       ; Jump to line 5 (ret) if not equal.
mov RBX, 10
ret
```
**RET** is short for return. This will return execution to the previous function. The following example sets RAX to 10 then returns.
```asm
mov RAX, 10
ret
```

## Back To The Example In 0x201
Remember the example from 0x201? Here it is:
```c
if(x == 4){
    func1();
}else{
    return;
}
```
is the same as
```assembly
mov RAX, x
cmp RAX, 4
jne 5       ; Line 5 (ret)
call func1
ret
```

Hopefully you can now work out the assembly version on it's own. It moves the variable `x` into RAX, then it compares `x` to 4. If they *are not equal* then it will return, if they *are equal* then it calls "func1".
## Flipping Out
You may also notice that the comparison is flipped.  
Instead of
```c
if(x == 4){
    func1();
}else{
    return;
}
```
the Assembly version is:
```c
if(x != 4){
    return;
}else{
    func1();
}
```
You could easily make the Assembly version match the original C version. The Assembly given in the example is what you will typically see in "the real world ". Although it may not seem like it, the reason for this is efficiency. Basically the compiler can make the program look one of two main ways:
```assembly
mov RAX, x
cmp RAX, 4
je 5       ; Line 5 (call func1)
ret
call func1
ret
```
```assembly
mov RAX, x
cmp RAX, 4
jne 5       ; Line 5 (ret)
call func1
ret
```
This code wants to return once `func1` has returned, and/or if RAX is not equal to 4. In other words, it's returning either way. To reduce the amount of instructions the compiler will choose the second option. You may have seen some programmers write if-statements that are more similar to `if(x != 4)` instead of `if(x == 4)`, and this is probably why. Although it really doesn't matter how the programmer writes it because the compiler will most likely choose the best option anyways.

## Final Note
There are many more Assembly instructions that I haven't covered. As we continue I will introduce more instructions as they come. Don't be afraid to look up instructions, because like I said, there are quite a few (hundreds or thousands).