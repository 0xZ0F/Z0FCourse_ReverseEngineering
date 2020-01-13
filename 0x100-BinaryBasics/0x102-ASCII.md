# 0x102 - ASCII
Computers only understand numbers. So how are you seeing this text on your screen? It's simple, and it's a technique used constantly. It all depends on how it's interpreted. The letter "AAAA" (capitalization matters) is 0x41414141 or 1000001010000010100000101000001b. 0x41414141 could be a memory address, or it could be a series of four A's. In this case "AAAA" is presented as four letters because the software has decided to present them that way.

## How Does It Work?
In order for 0x41414141 to be "AAAA" we need to have some sort of standard. This standard is called ASCII. When you interpret something as ASCII you are assigning values to some other form. For example, in ASCII 0x41 is "A", 0x42 is "B", etc. This standard allows all of us to see the same thing. There are of course many different standards, and some are used in different scenarios.

Here's a full ASCII table: http://www.asciitable.com/

[<- Previous Lesson](0x101-NumberSystems.md)  
[Next Lesson ->](0x103-BitsAndBytes.md)  


[Chapter Home](0x100-BinaryBasics.md)  
