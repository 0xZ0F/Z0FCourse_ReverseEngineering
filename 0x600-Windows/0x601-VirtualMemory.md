# Virtual Memory - WIP
You're probably aware that a computer has physical memory, also known as RAM. But how is this memory accessed? Well, with addresses of course! Unfortunately it's not that simple. 
* If there are multiple processes running on the system, you now need some way to specify regions in memory for each process. 
* You also start to run into the issue of space. What do you do if you only have 4GB of physical memory but the processes running take up 6GB?
* If programs aren't loaded into the same address space every time they run, then hard-coded addresses won't work.
* What about fragmentation? If a small program exits and there isn't enough room for a new process, that's just wasted space. Even if a process is small enough to fit in that space unless it's the same exact size, there will still be unused memory.

To solve these issues, and many others, what if we could treat every process as if it was the only process on the system. This is where virtual memory comes in. 

For example, let's say every process thought it was at 0x10000000 in memory. Using a some tricks, when that program is loaded into memory, the OS could translate those addresses into physical memory. Let's say the program is actually loaded at 0xB0004500. If the program needs to access data that is at an offset of +0x40 it would do it via 0x10000040 (0x10000000 + 0x40). Whenever the process tries to access that data, the OS could translate that into 0xB0004540 (0xB0004500 + 0x40). By doing this the program could be loaded anywhere into memory and it could try to use memory as if it was the only process.

Another fancy thing about virtual memory is that it can map processes in chunks. For example, part of the process could be at 0xB0004500 to 0xB000F000 and another part could be at 0xD0100000 to 0xD010C000. Another process could be between those two chunks, such as from 0xC0000000 to 0xD0000000.

# How Virtual Memory Works
The previous examples explained the idea of virtual memory. Now let's discuss how virtual memory actually works and how it's implemented.

Mapping every physical memory address to a virtual memory address individually would, ironically, take up too much memory. Instead, the physical memory in a computer is usually into 4KB chunks called ***pages***. There can be pages of a different size, but that's beyond the scope of this chapter.

The mapping of these pages from physical addresses to virtual addresses is done by the Memory Management Unit (MMU). The MMU is a physical piece of hardware which, on conventional desktop computers, resides in the processor.