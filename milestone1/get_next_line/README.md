*This project has been created as part of the 42 curriculum by vitruong.*

# Description
This project is called get_next_line, and its goal is create a function that returns one line read from a file descriptor and the next one with each subsequent calls, with its bonus version being able to do so on multiple ones.\
It is a mean to teach us about static variables and create a complexe function with a limit amount of functions authorized.

# Instructions
To use get_next_line, you have to clone the github repository, then compile it with your files.

You will need to add in your code `#include "relative/path/to/get_next_line.h"` and you'll be able to use the function `get_next_line`.
And assuming you're using `gcc` or `cc` to compile, add `relative/path/to/get_next_line.c` and `relative/path/to/get_next_line_utils.c`  next to your .c files in the command.

A line is defined as a group of multiples bytes, ending at a newline or at the EOF.\
The non-bonus version of get_next_line only takes a file descriptor as an argument and returns a line, subsequent calls returning the next ones. It only handles one file descriptor during the whole program.\
If an error occurs (e.g. due to a bad file descriptor), it would return `NULL`.
Please remember to `free()` the result of each calls of `get_next_line()`.

The bonus version is the same as the non-bonus, but it can handles multiple file descriptor during the whole program.

# Resources
- `read` function (used to read bytes inside file descriptors) - https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html
- About static variables - https://en.wikipedia.org/wiki/Static_variable

# Details
The whole system is based on multiples functions each handling a specific part of the process.\ 
Due to the constraint of having to give a specific number of bytes defined to the `read` function, everything that would come after a newline has to be extracted and put aside to be used at the next call.\
At the next call of get_next_line, it will add read bytes to the excess and check if a line is formed after each `read` call. If the excess already had a line in it, the function directly processes it and returns the line without calling the checkread function.

A system of reallocation is used to make sure to have enough space for reading the bytes without losing what is stored.

**Main functions**:
- One is for setting up things at each get_next_line call, to be ready for the next steps.
- One is to handle the reading of the bytes and putting it at the right place, and making sure the buffer used to store the bytes is big enough for a read.
- And one is to extract the excess after a new line and preparing the line to be returned.

Add to that in the bonus version, a function which manage a struct used as an array to keep track of which excess belongs to the appropriate file descriptor and reallocate the array when needing more space to handle a new file descriptor.

**Data structures**:

A struct in the non-bonus version is used to keep track of our read bytes string, its size, and how many bytes are filled in it.

The same struct is used in the bonus version, with the slight modification of adding a property to track the file descriptor it belongs to. And another struct is created and used as an array that stores multiples instances of the first struct, allowing us to handle multiple file descriptors.

**NO AI WAS USED TO GENERATE CODE OR TEXT. IT MAY HAVE BEEN USED DURING RESEARCH**
