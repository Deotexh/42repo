*This project has been created as part of the 42 curriculum by vitruong.*

# Description
This project is aiming to make us better understand the highly useful standard functions of the C programming language by implementing them ourselves and learning to use them effectively. To do so, we need to create our own library called libft.a which will be valuable for our future C school assignments. 

The project was built in 3 parts: the first one was about implementing already existing functions from glibc or BSD libc, the second was about developing a set of functions that were either not included in libc or existed in a different form, and the third was about developing functions to manipulate linked lists. \
All functions starts with the prefix "ft_", and depending on their usage they may start with a certain word after the prefix, here's a list of the those:
- `ft_is...`: used to get a true/false about a conditions eg. `ft_isalpha` tests if an ASCII char is in the alphabet.
- `ft_str...`: used for string operations eg. `ft_len` gets the length of a true C-string.
- `ft_put...`: used to print things (here the functions have to be specified the file description in which to print) eg. `ft_putchar_fd` prints a char.
- `ft_lst...`: used for linked list operations eg. `ft_lstclear` clears a node and its successor.
- `ft_mem...`: used for operations on memory zone eg. `ft_memset` sets n bytes of memory at an address to a specific value.

# Instructions
To install the library, you have to clone the github repository, then compile it by source.

The library libft.a can be built using the build system Make. To compile it, you will need to open a terminal in the root folder then type commands.
Here are the different commands available for make:
- `make`, `make all` or `make libft.a`: create object files in the directory then compile them to output libft.a
- `make clean`: removes the object files
- `make fclean`: removes the object files AND libft.a
- `make re`: recompiles everything by first cleaning everything then compiling everything again

In order to use the library, you will have to move `libft.a` and `libft.h` and put them together somewhere into your project tree. \
Then you will need to add in your code `#include "relative/path/to/libft.h"`.
And finally, assuming you're using `gcc` or `cc` to compile, add `relative/path/to/libft.a` next to your .c files in the command.

# Resources
Using the `man` command can be useful for some functions since they are replicates of glibc/BSD libc functions.
- BSD libc - https://en.wikipedia.org/wiki/C_standard_library#BSD_libc
- Glibc - https://fr.wikipedia.org/wiki/GNU_C_Library
- Linked list - https://en.wikipedia.org/wiki/Linked_list
- Make - https://www.gnu.org/software/make/, https://en.wikipedia.org/wiki/Make_(software)

### NO AI WAS USED TO GENERATE CODE OR TEXT.
