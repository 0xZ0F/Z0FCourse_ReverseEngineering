# 0x106 - Mindset
Having the right mindset can be really helpful. Something to understand is that computers are extremely stupid. They operate on "blunt logic" and they don't make any assumptions (note that this only holds true as long as Skynet doesn't become a reality). You can think of computers as trains, they don't stop and only go in a very specific and direct path as designated by the tracks. If there's a child on the tracks it's up to the track people to divert the train. As for a developer, it's up to them to make sure the computer is doing what it's supposed to do and doesn't "derail". This is where binary exploitation comes in. Hackers *want* the train to hit the ch... okay I'll stop myself there ;)

### What is a Protocol?
TCP, UDP, HTTP(s), FTP, and SMTP are all protocols. Why? What are protocols? Protocols are simply templates that are used to specify what data is where. Let's use an example.
> 01011990JohnDoe/0/123MainSt

What is that? Without some sort of guide or template, that just seems like a mess of data. Because we're humans we can probably pick out some information such as a name and a street. But computers can't do that and we humans are still unable to understand all of it. It's actually a bunch of helpful data about someone named "John Doe". It's confusing because it's all packed together in an attempt to make it as small as possible. Here, let me give you the secret formula:
> BIRTHDAY(MMDDYYYY)NAME/NumOfChildren/HomeAddress

See, now it makes sense! The collection of numbers at the start is his birthday. Following his birthday is his name. There is then a forward slash and the number of children he has. Then another forward slash and his home address. Here is another example:
> 03141879AlbertEinstein/3/112MercerSt

This is a great demonstration of what a protocol is. It's simply a template that computers can use to pick apart a series of data that would otherwise seem pointless. 

I also want to point out the delimiters (the forward slashes) used for the number of children and the street they live on. Because those pieces of data have variable lengths, it's a good idea to distinguish between them in some way besides a specific number of characters. Remember, a computer can't make assumptions. We need to be very literal or it won't know what we mean. Assuming the template is filled out correctly the first 8 characters represent the birth date. The characters following the date up to the forward slash are the person's name. Then the next character(s) following that forward slash and up to the next forward slash is the number of children that person had. Finally, the rest of the data after the final forward slash is the persons home address.

### Is It Equal?
Because computers are stupid, they often do things in a very simple way that may not be obvious at first. For example, how does a computer decide if two values are equal? When you start looking at Assembly instructions there is a compare instruction. This instruction can decide if a value is greater than another, less than another, or equal to another. How does this instruction determine all of these things? It's actually quite simple, just subtract them. It's so simple it may not be obvious at first.

[<- Previous Lesson](0x105-BitwiseOperations.md)  
[Next Lesson ->](../0x200-BinaryBasics/0x200-Assembly.md)  

[Chapter Home](0x100-BinaryBasics.md)  
[Course Home](../README.md)  