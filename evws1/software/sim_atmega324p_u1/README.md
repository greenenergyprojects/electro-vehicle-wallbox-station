
(GCC)Options    | Description
--------- | ------
`-MMD`   | Like `-MD` except mention only user header files, not system header files. <br> `-MD` ... is equivalent to `-M -MF file`, except that `-E` is not implied. The driver determines file based on whether an `-o` option is given. If it is, the driver uses its argument but with a suffix of `.d`, otherwise it takes the name of the input file, removes any directory components and suffix, and applies a `.d` suffix. <br> `-M` ... Instead of outputting the result of preprocessing, output a rule suitable for make describing the dependencies of the main source file. <br> 
`-O2` | Optimize even more. GCC performs nearly all supported optimizations that do not involve a space-speed tradeoff. <br>See [https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#Optimize-Options)
`-Wall` | This enables all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros.
`-Wextra` | This enables some extra warning flags that are not enabled by `-Wall`.
`-Wno-unused-parameter` | 
`-Wno-unused-result` | 
`-Wno-missing-field-initializers ` | 
`-Wno-sign-compare` | ??? not documented
`-g` | Produce debugging information in the operating system’s native format (stabs, COFF, XCOFF, or DWARF). GDB can work with this debugging information.
`-fPIC` | If supported for the target machine, emit position-independent code, suitable for dynamic linking and avoiding any limit on the size of the global offset table. This option makes a difference on AArch64, m68k, PowerPC and SPARC.
`-Wl,-rpath,/home/steiner/Private/work/simavr/examples/board_evws1/../../simavr/obj-x86_64-linux-gnu` | Pass option `-rpath,...` as an option to the linker.<br> `-rpath` ... Add a directory to the runtime library search path
`-o obj-x86_64-linux-gnu/evws1.elf` | Place the primary output in file `obj-x86_64-linux-gnu/evws1.elf`.
`../parts/obj-x86_64-linux-gnu/button.o` |
`obj-x86_64-linux-gnu/evws1.o` | 
`-lpthread` | Link with the POSIX threads library.
`-lGLU` | Search the library named `GLU` when linking.
`-lGL` | Search the library named `GL` when linking.
`-lglut` | Search the library named `glut` when linking.
`-L/home/steiner/Private/work/simavr/examples/board_evws1/../../simavr/obj-x86_64-linux-gnu` | Add directory `simavr/obj-x86_64-linux-gnu`  to the list of directories to be searched for -l.when linking.
`-lsimavr` | Search the library named `simavr` when linking.
`-lm` | Search the library named `m` when linking (math).
`-lel` | Search the library named `el` when linking.
