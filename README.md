# <a href="url"><img src="https://images.assetsdelivery.com/compings_v2/dmstudio/dmstudio1606/dmstudio160600030.jpg" align="middle" width="100" height="100"></a> simple_shell


## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Installation](#installation)
* [Usage](#usage)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)

## Description
This is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. This was made as a project for Holberton School. In this project we apply the knowledge that we have learned in C programming language.
Standard functions and system calls employed in simple_shell include:
   ```sh
   access, execve, exit, fork, free, malloc, read, signal, wait, write.
   ```
   
## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [shell.h](shell.h) - program header file
* [coincidence.c](coincidence.c) - 
  * `coincidence` - looks for coincidence
  * `ext` - free and exit buffer
  * `env` - prints environ
  * `compare_path` - compare PATH in environ
  * `str_concate` - concates two strings
* [free.c](free.c) - function related to free
  * `freeAll` - frees a buffer
  * `checks` - writes to standar error
* [exit.c](exit.c) - fuction related to exit
  * `sigintHandler` - signal error
  * `free_env` - frees the shell's environment
* [getargs.c](getargs.c) - funtion creates an array of pointers
  * `count` - counts the buffer
  * `getargs` - creates arrays of ponters with all the arguments
* [get_env.c](get_env.c) - enviromental variables related function
  * `get_env` - gets an environ char
  * `get_pwd` - creates a pointer of the path
  * `get_env1` - get a specific pointer from env
* [_strtok.c](_strtok.c) - custom strtok
  * `_strtok` - checks if a character matches in a string and breaks it into tokens
* [getline1.c](getline1.c) - functions related to get a line
  * `store_lineptr` - aasigns the line 
  * `getline1` - reads imput from a stream
* [prompt.c](prompt.c) - essential functions to the shell
  * `prompt` - prints a prompt
* [spaces.c](spaces.c) - functions related to string manipulation
  * `spaces` - compare size of string
  * `cpstring` - duplicates a string
  * `cd_fun` - cd function
  * `changepwd` - change pwd and old pwd
  * `oldpwd` - get oldpwd
* [shell.c](shell.c) - main function of the shell
  * `main` - the main function of the program
  * `ret` - return function
  * `extstatus` - return status
  * `writeexe` - writes to standar error
  * `writes0` - writes to standar error
* [calloc.c](calloc.c) - allocates memory
  * `calloc` - allocates memory and return a pointers
* [realloc.c](realloc.c) - reallocates memory
  * `calloc` - reallocates memory and return a pointers
* [strcpy.c](strcpy.c) - copies string to buffer
  * `strcpy` - copies string to buffer
* [aux.c](strcpy.c) - auxiliar functions to print
  * `strlen` - returns the length of a string
  * `_puts` - writes a string to standard output
  * `_puts2` - writes a string to standard erro
  * `unatoi` - converts an unsigned int to a string
  * `writes3` - writes to estandar error
  
 

## Requirements

simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

## Installation

   - Clone this repository: `git clone "https://github.com/zamu5/simple_shell.git"`
   - Change directories into the repository: `cd simple_shell`
   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Or run the shell in non-interactive mode: example `echo "pwd" | ./hsh`

## Usage

The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality. The development of this shell is ongoing. The below features will be checked as they become available (see man page for complete information on usage):

### Features
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [x] handles comments (#)
- [x] handles **;**
- [x] custom getline type function
- [ ] handles **&&** and **||**
- [ ] aliases
- [ ] variable replacement


### Builtins

- [x] exit
- [x] env
- [ ] setenv
- [ ] unsetenv
- [x] cd
- [ ] help
- [ ] history

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./hsh
$ ls -la
total 116
drwxrwxr-x  3 vagrant vagrant  4096 Aug 25 20:21 .
drwxr-xr-x 14 vagrant vagrant  4096 Aug 25 20:27 ..
drwxrwxr-x  8 vagrant vagrant  4096 Aug 25 20:27 .git
-rw-rw-r--  1 vagrant vagrant   160 Aug 25 00:09 AUTHORS
-rw-rw-r--  1 vagrant vagrant  2828 Jul 31 01:52 README.md
-rw-rw-r--  1 vagrant vagrant   823 Aug 23 16:54 _strtok.c
-rw-rw-r--  1 vagrant vagrant  1967 Aug 24 16:46 coincidence.c
-rw-rw-r--  1 vagrant vagrant   216 Aug 23 16:54 concidence.c~
-rw-rw-r--  1 vagrant vagrant   241 Aug 23 16:54 exit.c
-rw-rw-r--  1 vagrant vagrant   189 Aug 23 16:54 free.c
-rw-rw-r--  1 vagrant vagrant   338 Aug 24 16:46 get_env.c
-rw-rw-r--  1 vagrant vagrant  1117 Aug 23 18:42 getargs.c
-rw-rw-r--  1 vagrant vagrant  1477 Aug 25 20:21 getline1.c
-rw-rw-r--  1 vagrant vagrant  1302 Aug 24 16:46 holberton.h
-rwxrwxr-x  1 vagrant vagrant 29371 Aug 24 16:56 hsh
-rw-rw-r--  1 vagrant vagrant  2271 Aug 25 02:52 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   167 Aug 23 16:54 prompt.c
-rw-rw-r--  1 vagrant vagrant   789 Aug 23 18:47 realloc.c
-rw-rw-r--  1 vagrant vagrant   973 Aug 24 16:51 shell.c
-rw-rw-r--  1 vagrant vagrant   527 Aug 24 16:46 spaces.c
-rw-rw-r--  1 vagrant vagrant   270 Aug 23 18:48 strcpy.c
-rw-rw-r--  1 vagrant vagrant    46 Aug 23 16:54 test
```
## Bugs

## Authors

Nkwuda Theophilus | [GitHub](https://github.com/ONtio-js) | [Twitter](https://twitter.com/theophilusonye9)

