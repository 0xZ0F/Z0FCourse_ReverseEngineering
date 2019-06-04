# Instructions
Now it's time to learn some assembly instructions. The instructions guide the program in the right direction. There are three different terms you should know: **immediate**, **register**, and **memory**. An immediate value is something like the number 12 (the kind of number we humans use). A register is referring to something like EAX, RBX, etc. Memory refers to a memory address such as 0x7FFF842B.

### Common Instructions
It's important to know the format of instructions which is as follows:  
(mnemonic) \<destination\>, \<source\>  
Example:
```asm
mov RAX, 5
```
"mov" is the mnemonic, RAX is the destination, and 5 is the source.  
This will move 5 into RAX. It's the same as RAX = 5.
#### Data
"mov" is used to move/store data in a destination.
```asm
mov RAX, 5
```
"push" is used to push data onto the stack. In this case whatever is in RAX is put onto the stack. RAX will still contain the value it had.
```asm
push RAX
```
"pop" is used to take whatever is on the top of the stack and store it in a destination. In this case whatever is ontop of the stack will be put into RAX.
```asm
pop RAX
```

#### Arithmetic
"inc" will increment data by one. In this case RAX is set to 8, then incremented. RAX will be 9.
```asm
mov RAX, 8
inc RAX
```
"dec" decrements a value. RAX is now 7.
```asm
mov RAX, 8
dec RAX
```
"add" adds a source to a destination and stores the result in the destination. This will move 2 into RAX, 3 into RBX, then add the two together. The result (5) is then stored in RAX.  
Same as RAX = RAX + RBX.
```asm
mov RAX, 2
mov RBX, 3
add RAX, RBX
```
"sub" subtracts a source from a destination and stores the result in the destination. RAX will be 2.  
Same as RAX = RAX - RBX.
```asm
mov RAX, 5
mov RBX, 3
add RAX, RBX
```
"mul" or "imul" multiplies the destination by the source. The result is stored in the destination. RAX will be 15. imul is used for signed and mul is used for unsigned.
```asm
mov RAX, 5
mov RBX, 3
mul RAX, RBX
```
"div" or "idiv" divides the destination by the source. The result is stored in the destination. RAX will be 15. imul is used for signed and mul is used for unsigned.
```asm
mov RAX, 5
mov RBX, 3
mul RAX, RBX
```