# Windows x64 Calling Convention
When a function is called you could, theoretically, pass parameters via registers, the stack, or even on disk. You just need to be sure that the function you are calling knows how you are calling it. This isn't too big of a problem if you are using your own functions, but things would get messy when you start using libraries. To solve this problem we have **calling conventions** that define how parameters are passed to a function, who allocates space for local variables, and who cleans up the stack.

> **Callee** refers to the function being called, and the **caller** is the function making the call.

There are several different calling conventions including cdecl, syscall, stdcall, fastcall, and many more. Because we are going to be reverse engineering on x64 Windows we should only have to focus on x64 fastcall. If you do plan on reversing on other platforms, be sure to learn the calling convention(s).

## Fastcall
Fastcall is *the* calling convention for x64 Windows. Windows uses a four-register fastcall calling convention by default. I'm not sure if this calling convention is the only one used on x64, but I hope it is. Differing calling conventions can be extremely annoying to deal with as is the case in x32.  When talking about calling conventions you will hear about something called the "Application Binary Interface" (ABI). The ABI defines various rules for programs such as calling conventions, parameter handling, and more.

#### So how does the x64 Windows calling convention work?
* The first four arguments/parameters are passed in registers. Parameters that are *not* floating point values (floats or doubles) will be passed via RCX, RDX, R8, and R9 (in that order). Non-floating point values include pointers, integers, booleans, chars, etc. Floating point parameters will be passed via XMM0, XMM1, XMM2, and XMM3 (in that order). Floating point values include floats and doubles. If the parameter being passed is too big to fit in a register then it is passed by reference. Parameters are never spread across multiple registers. Any other parameters are put on the stack.

> All parameters, even ones passed through registers, have space reserved on the stack for them. Also, there is always space made for 4 parameters on the stack even if there are no parameters passed. This space isn't completely wasted because the compiler can, and often will, use it.

* A function's return value is passed via RAX if it's an integer, bool, char, etc., or XMM0 if it's a float or double.
* Member functions (functions that are part of a class/struct) have an implicit first parameter for the "this" pointer. Because it's a pointer it will be passed via RCX.[[1]](https://www.gamasutra.com/view/news/171088/x64_ABI_Intro_to_the_Windows_x64_calling_convention.php)
* The *caller* is responsible for allocating space for parameters for the *callee*. The caller must always allocate space for 4 parameters even if no parameters are passed.

That's the x64 Windows fastcall calling convention for you. Learning your first calling convention is like learning your first programming language. It seems complex and daunting at first, but it's really quite simple. It's typically harder to learn you first calling convention than it is your second or third.

If you want to learn more about this calling convention you can here:  
https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention?view=vs-2019  
https://docs.microsoft.com/en-us/cpp/build/x64-software-conventions?view=vs-2019  

> If this section was confusing, read through [0x203-Instructions.md](0x203-Instructions.md) then re-read this section. After you re-read this section you might want to read 0x203-Instructions.md again. I apologize for this but there really isn't a good order to teach this stuff in since it all goes together.

<br />
<br />
<br />
<br />

##### Sources
https://docs.microsoft.com/en-us/cpp/build/x64-software-conventions?view=vs-2019
https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention?view=vs-2019
https://docs.microsoft.com/en-us/cpp/build/prolog-and-epilog?view=vs-2019
https://www.gamasutra.com/view/news/171088/x64_ABI_Intro_to_the_Windows_x64_calling_convention.php