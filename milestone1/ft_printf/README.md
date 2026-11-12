*This project has been created as part of the 42 curriculum by vitruong.*

# Description
This project is called ft_printf, and its goal is to recode printf and mainly learning about the use of variable numbers of arguments in functions: the **variadic functions**.\
It also incites to learn about correctly structuring code and making it extendable.

# Instructions
To use ft_printf, you have to clone the github repository, then compile it by source.

libftprintf.a can be built using the build system Make. To compile it, you will need to open a terminal in the root folder then type commands.
Here are the different commands available for make:
- `make`, `make all` or `make libftprintf.a`: create object files in the directory then compile them to output libftprintf.a
- `make bonus`: compiles ft_printf with the management of the flags `+-0 #.` and width depending on the type.
- `make clean`: removes the object files
- `make fclean`: removes the object files AND libftprintf.a
- `make re`: recompiles everything by first cleaning everything then compiling everything again

In order to use ft_printf, you will have to move `libftprintf.a` and `ft_printf.h` and put them together somewhere into your project tree. \
Then you will need to add in your code `#include "relative/path/to/ft_printf.h"`.
And finally, assuming you're using `gcc` or `cc` to compile, add `relative/path/to/libftprintf.a` next to your .c files in the command.

The first argument of printf is a string that will be the main body of your text, and probably some '%' sign which would serve as placeholder to be replaced in order by the next arguments after the string.
Depending on what follows the percent sign '%', a specific type will be expected and a specific display of the value will be done.\
Here are the supported type specifiers:
- 'c' => displays a char
- 'd' OR 'i' => displays a signed integer
- 'x' OR 'X' => displays an unsigned integer in hexadecimal format, with the letters being lowercase or uppercase respectively
- 's'=> displays a C-string
- 'u'=> displays an unsigned integer
- 'p'=> displays a pointer in hexadecimal format prefixed with "0x"

The bonus flags and width can be learned more about with the resources available in the `Resources` section.
Please take note that some combinasons of flags and type specifier are causing undefined behavior.

ft_printf returns the number of bytes printed, or -1 if an error was to occur.

# Resources
- Printf - https://en.cppreference.com/c/io/fprintf, https://www.ibm.com/docs/fr/i/7.5.0?topic=p-print-formatted-characters-printf
- Make - https://www.gnu.org/software/make/, https://en.wikipedia.org/wiki/Make_(software)
- About varying arguments - https://learn.microsoft.com/fr-fr/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170, https://koor.fr/C/cstdarg/version.wp

# Details
In the non-bonus version, I used a simple loop that would iterate over the characters and call a function that would handle the conversions if a '%' was to be encountered. I used no buffer-management and just printed every character one by one.
In the bonus version, the handling of the '%' is much more complex with a section about checking, one about getting informations crucial to the correct display of the value, and a last one about handling the printing of it.

A struct containing informations used by the bonus part is present in the non-bonus version due to the structure of the code relying on swapping the implementations of the functions depending on which version is used.

**NO AI WAS USED TO GENERATE CODE OR TEXT. IT MAY HAVE BEEN USED DURING RESEARCH**
