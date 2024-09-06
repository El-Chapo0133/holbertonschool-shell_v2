# holbertonschool-shell_v2
## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What are a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?
- How to redirect the content of a file into another file
- What is a pipeline
- How to setup a pipe
- How to setup a pipe between two processes

## Requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS
- Your C programs and functions will be compiled with gcc 9.4.0
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- A AUTHORS.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- There shouldn’t be any error nor memory leak upon execution of your shell

## Compilation
- You have to provide a Makefile in order to compile your program
- Your Makefile must define the all rule: The all rule should compile and link the source code to generate the executable hsh
- Make sure your program compiles on Ubuntu 14.04 LTS, with gcc 4.8.4
- You must compile using the flags -Wall -Werror -Wextra and -pedantic
- Your executable must be named: hsh

## Output
- Your shell will be auto-reviewed in non-interactive mode (commands will be piped to it). Thereby, the prompt you print in interactive mode will not be taken into account, so you are free to have the prompt of your choice.
- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0]
