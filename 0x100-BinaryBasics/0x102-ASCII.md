# ASCII
Computers only understand numbers. So how are you seeing this text on your screen? It's simple, and it's a technique used constantly. It all depends on how it's interpreted. The letter "AAAA" (capitalization matters) is 0x41414141 or 1000001010000010100000101000001b. 0x41414141 could be a memory address, or it could be a series of four A's. Your web browser is currently representing these A's as text so that's what you see. This will become an important concept to understand and we will touch on it more later.

## How Does It Work?
In order for 0x41414141 to be "AAAA" we need to have some sort of standard. This standard is called ASCII. When you interpret something as ASCII you are assigning values to some other form. For example, in ASCII 0x41 is "A", 0x42 is "B", etc. This standard allows all of us to see the same thing.

Here's a full ASCII table: http://www.asciitable.com/