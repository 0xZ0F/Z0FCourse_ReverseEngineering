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

## Disassemble
Let's view the compiled version of the programs in a disassembler. **We'll start with the `printf()` version.**  
x64dbg does a great job at presenting these programs so let's use that. To disassemble a program in x64dbg you can go to File > Open then select the program. You can also just drag and drop the program onto the GUI of x64dbg.