# 0x103 - Bits and Bytes
Computers "understand" binary (Ex. 10110010).

* **Bit is one binary digit**. So a bit can either be 0 or 1. 
* **Byte is 8 bits**.
* **Nibble is 4 bits** or half a byte.
* **Word is 2 bytes**. This isn't the case for all architectures, but Windows declares words as 2 bytes so that's what we will go with.
* **Double Word (DWORD) is 4 bytes**, twice the size of a word.
* **Quad Word (QWORD) is 8 bytes**, or four times the size of a word.

Before we get into other data types, let's talk about signed vs unsigned. Signed numbers can be positive or negative. Unsigned is only positive numbers. You can remember this by thinking about how you would normally write positive and negative numbers. If you are using both positive and negative then you should put a sign in front of the negative number so you can tell them apart. If you are using only positive number then no sign is needed.

### Some Data Type Sizes
* **Char** - 1 byte (8 bits).
* ***Signed* int** - there are 16-bit, 32-bit, and 64-bit integers. 
  * 16 bit is -32,768 to 32,767. 
  * 32 bit is -2,147,483,648 to 2,147,483,647. 
  * 64-bit is -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807.
* ***Unsigned* int** - All bits can be used to represent a positive number meaning they go up to twice the number a signed int can but only down to zero. For example: unsigned 32-bit int goes from 0 to 4,294,967,295. That is twice the signed maximum of 2,147,483,647 however its minimum value is 0.
* **Bool** - 1 byte. This may surprise you since a bool only needs 1 bit because it's either 1 or 0. The reason why it's a byte is because computers don't tend to work with individual bits because of alignment (talked about later). This is done to keep everything clean and eliminate as much confusion as possible.

For more data types go here: https://www.tutorialspoint.com/cprogramming/c_data_types.htm

## Significance
The least significant digit is the lowest value. The most significant digit is the highest value. The least significant digit in 124 is 4. The most significant is 1 (100).

[<- Previous Lesson](0x102-ASCII.md)  
[Next Lesson ->](0x104-ProgrammingLanguages.md)  


[Chapter Home](0x100-BinaryBasics.md)  
