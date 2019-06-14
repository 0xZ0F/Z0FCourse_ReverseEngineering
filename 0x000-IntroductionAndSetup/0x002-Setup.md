# Setup
This course will focus on 64 bit Windows, but we will talk about 32 bit and Linux as well. Note: x32 and x86 are the same.

## Reversing Tools:
Most of the software can be replaced with anything you like. The software I will be using is listed (all of it's free):  
#### Required:
* **Ghidra** (Needs Java JRE and JDK).
* **x64dbg** (Comes with x32dbg as well).
* **dnSpy** (preferred) or ILSpy (Used for .NET reversing towards the end).
* **Visual Studio** with "Desktop development with C++" installed. I would also recommend installing ".NET desktop development."

#### Optional:
* **HxD** (Hex editor)
* **Sysinternals Suite** (Various tools to analyze Windows).
* **Dependency Walker** (Can be used as a GUI alternative of "DUMPBIN" which comes with Visual Studio).

As you can see there is no IDA Pro! With the release of Ghidra there isn't really a reason to use IDA Freeware or Pro. Although IDA Pro is better (in my opinion), it's not free like Ghidra is. In fact, it's quite expensive. If you prefer IDA you can use it. I'm cheap so I won't be.

Some other good software you may want to take a look at some time is Hopper, Radare, and Binary Ninja. Of those, only Radare is free. Hopper has a free version but you can only use it for a certain amount of time.

## Target Software:
All files we will be reversing are in [FilesNeeded](FilesNeeded). I'm unable to distribute all software due to legal restrictions. Any programs that I didn't provide directly are listed in [@ExternalResources](FilesNeeded/@ExternalResources.txt).