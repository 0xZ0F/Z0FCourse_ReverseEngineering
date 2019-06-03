# Bits and Bytes
Computers understand numbers in binary (Ex. 10110010).

One bit is one digit of binary. So a bit can either be 0 or 1. 

One byte is 8 bits.

One nibble is 4 bits or half a byte.

One word is the size of... umm. Okay, words are a bit weird. Historically words were 2 bytes, now however words are the size of the architecture. So a word on a 32 bit system is 4 bytes, and 8 bytes on a 64 bit system. You'll see conflicting answers on how big a word is, but let's just go with it's as large as the architecture.

A double word (DWORD) is twice the size of a word. A quad word (QWORD) is four times the size of a word.

Before we get into other data types, let's talk about signed vs unsigned. Signed numbers can be positive or negative. Unsigned is only positive numbers. Here's how you can remember this: **If you are talking about negative numbers you need a sign to specify so, if not, then no sign is needed.** By default, data types are signed.

* Char (signed or unsigned) - 1 byte.
* Signed int - there are 16 bit, 32 bit, and 64 bit integers. 16 bit is -32,768 to 32,767 32 bit is -2,147,483,648 to 2,147,483,647 and 64 bit is -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807.
* Unsigned int - All bits can be used to represent a positive number meaning they go up to twice the number but only down to zero. For example: unsigned 32 bit int goes from 0 to 4,294,967,295. That is twice the signed maximum of 2,147,483,647 however it only goes down to 0.

For more data types go here: https://www.tutorialspoint.com/cprogramming/c_data_types.htm
