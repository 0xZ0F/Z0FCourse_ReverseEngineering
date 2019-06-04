# Assembly Basics
Depending on whether you are working with 64 bit or 32 bit assembly things may be a little different. I'm going to focus on 64 bit Windows because it's the most popular. After this course, I would recommend learning ARM. There are also two different syntaxes for x64 assembly: Intel and AT&T. AT&T is typically used on *UNIX however the two are functionally the same, so you can translate between the two. We will focus on Intel because I think it's the easiest to understand. 

### What Is Assembly?
When you compile a program, the compiler does various things. The most important thing is that it translates the high level code into a language that the CPU can understand. Assembly is the language the CPU executes. The CPU supports various instructions that all work together doing things such as moving data, performing comparisons, doing things based on comparisons, modifying values, and really anything else that you can think of.

### Assembly Instructions:
This may get really confusing real fast for some people. What you need to remember is that Assembly was written for humans. It's just like higher level languages except less wordy. For example:  
```c
if(x == 4){
    func1();
}else{
    return;
}
```
is the same as
```assembly
cmp eax, 4
jne 4 ; line 4
call func1
ret
```
