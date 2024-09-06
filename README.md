# Shell v2 Project

## Overview
Shell v2 is a custom shell implementation developed in C. It aims to replicate key functionalities of a Unix-like shell, including command execution, built-in commands, and environment variable management. This project serves as an advanced exercise in system &algorithm programming.

## Features

**Command Execution**: Execute external programs and commands.

**Built-in Commands**: Support for commands such as cd, exit, and setenv.

**Environment Variable Management**: Custom implementation of setenv and unsetenv for managing environment variables.

**Pipes and Redirection**: Handling of input/output redirection and pipes for inter-process communication.

**Error Handling**: Comprehensive error reporting for various system call failures.

## Getting Started

### Requirements

Simple shell project was compiled on Ubuntu 20.04 LTS using gcc compiler, with following options
```
gcc -Wall -Werror Wextra -pedantic -std=gnu89
```

### Usage
Clone this repository: 
```
git clone https://github.com/El-Chapo0133/holbertonschool-shell_v2.git%60%60%60
```

Switch inside the directory:
```
cd holbertonschool-simple_shell
```

Compile all the files using the Makefile (target all):
```
make all
```

You're all good to use the shell either in Interactive mode, to do so enter in your terminal:
```
./hsh
```

Then a prompt will be displayed, and you can enter commands.

## Authors
The following person worked on this project:

- LEVEQUE Loris <9601@holbertonstudents.com>
- https://github.com/El-Chapo0133

License
This Project is open-source, free to download and use without permissions.
