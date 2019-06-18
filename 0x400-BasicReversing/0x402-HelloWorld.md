# Hello World
I don't think there is a better way to start reversing than a classic "Hello World" program. There are many ways to make program print "Hello World!" in C++, I will be showing the two main ways. One with `printf()` and another with `std::cout`.

## Source Code
I usually won't be giving you the source code, but since we are just starting out here it is.
#### Using `printf()`:
<p>
  <img height="100" src="[ignore]/HelloWorldPrintf.png">
</p>

#### Using `std::cout`:
<p>
  <img height="100" src="[ignore]/HelloWorldCout.png">
</p>

## Reversing the `printf()` Version
Let's view the compiled version of the programs in a disassembler. **We'll start with the `printf()` version.**  
x64dbg does a great job at presenting these programs so let's use that. To disassemble a program in x64dbg you can go to File > Open then select the program. You can also just drag and drop the program onto the GUI of x64dbg.

When you first throw the binary into x64dbg you may notice that we aren't in the `main` function. It turns out there are many things added to our program when it's compiled. Depending on how you have x64dbg setup it may start somewhere different. It might start at then "entry point" or near some security cookie thing. 
* **Entry Point** - The entry point is the true beginning of the program. There are a few things that a binary will do before it starts running the code written by the developer.
* **Security Cookies** - The security cookie is used to make sure that the return address of a function hasn't been corrupted before following it. This is done to help mitigate buffer overflows. For us, we can ignore anything to do with security cookies.

#### Finding `main`
We want to find the main function because that's where the code we want to reverse is at. So how do we get there? The easiest way is by going to the symbol. Go the the "Symbols" tab and click on the executable. 
<p align="center">
  <img height="400" src="[ignore]/PrintfSymbols.png">
</p>

There doesn't appear to be a `main()` function so we will have to find it some other way. One option we have is looking for the string that is going to be printed. We know that our program is going to print "Hello World!" so let's see if we can find where that string is used. We can do this in x64dbg by right clicking in the CPU view and going to Search for > All modules > String references. You should see something similar to what is shown in the image below.

<p align="center">
  <img src="[ignore]/StringReferences.png">
</p>

As you can see there are quite a few strings. Most of these strings aren't important. Let's search for our "Hello World!" string using the search bar at the bottom. Go ahead and double click on the "Hello Word!" string. If there are more than one just choose the first one. This will bring you into the function where the string is used.
<p align="center">
  <img src="[ignore]/PrintfMain.png">
</p>

> Quick Tip: If you expand the address column you can see the function name. Functions are also marked with a dollar sign ("$") at the start of them.

The function this string is used in is `sub_7FF7F6171070`. This is probably different for you. You can see this next to the address (you might have to resize the column). This name is weird because the decompiler couldn't figure out it's name so it just gave it a random name. So how do we know that this is the `main()` function? We don't. That's why reversing can be so difficult. Because we know what the code does and we have access to the source code we know that this is most likely the main function. In a realistic scenario we wouldn't actually know for sure.

Just so we don't have to keep doing this let's change its label to `main` by right clicking the first instruction in the function (the one with the `sub_7FF7F6171070` next to it) and choose Label > Label current address. Now we can get back to it by going to the functions tab and searching for `main`. You can get to the functions tab by going to View > Functions or by clicking the "fx" button on the tool bar above the "Memory Map" tab. The tool bar also has the debug buttons (blue arrows).

#### Analyzing Main
Let's figure out what `main` is doing by looking at it in Assembly. 
* `SUB RSP, 0x28` - On the first line we can see `RSP` is subtracted by 0x28. This is part of the function prologue. The function prologue sets up a function and you can usually ignore them.
* `LEA RCX, QWORD PTR DS:[0x7FF7F6189D90]` - `LEA` is short for **Load Effective Address** which will load an address into the destination operand (RCX in this case). What is the QWORD PTR part? This is simply stating that the value is a QWORD (8 bytes) and it's a pointer. The DS portion is short for data segment which can store data that doesn't fit in a register. You can ignore this and just know that it's some data from somewhere in memory. In our case this address is the address of our string. If you want to view the string in memory you can do so by right clicking the instruction and going to Follow in Dump > Constant: (Address). Notice that the value is being put into RCX which is the first register used to pass parameters to functions. Sure enough, the next line is a function call.
* `CALL <helloworld_printf.sub_7FF7F6171010>` This will call the function at `sub_7FF7F6171010`. As we previously discovered, this function will receive one parameter which is the address of our string. Thanks to xAnalyzer a comment was added that this function is `printf()`. If xAnalyzer didn't figure this out then how would we know this was `printf`? Typically I would use multiple tools and one of them would probably find out. The next easiest way would be to debug the program and see what happens after the call. We would see that the call has something to do with the text being printed out on the screen. Finally, we could reverse `printf()` and figure it out that way.

Now we get to the function epilogue which is the end of the function. This portion will clean everything up before returning execution back to where it was called from.

* `XOR EAX, EAX` - This is zeroing out the return value. I'm not sure why it's zeroing EAX instead of RAX, maybe it's because RAX was never needed and only EAX was. I could dig into this but there really isn't any need to.
* `ADD RSP, 0x28` - This is setting the stack to what is was before the function call. Notice that this is opposite to the `SUB RSP, 0x28` at the start.
* `RET` - Returns execution to the caller. This is the end of the function.

I want to touch on the fact that we passed the *address* of the string to `printf()`. In C/C++ the end of a string is denoted by a null character (0x00). This is known as the string terminator. This is important because something like `printf` will use this to know where the end of the string is so it doesn't print past it. A string is really a character array with the last character being a null terminator.

Hopefully that wasn't too difficult to do. Finding the `main()` function is always annoying and doesn't make getting started easier, but it's what we have to do. Feel free to explore a little bit!

## Reversing the `std::cout` Version