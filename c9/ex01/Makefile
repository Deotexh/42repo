SOURCEDIR = srcs
INCLUDEDIR = includes

TARGET = libft.a
SOURCES = $(SOURCEDIR)/ft_putchar.c $(SOURCEDIR)/ft_swap.c \
		  $(SOURCEDIR)/ft_putstr.c $(SOURCEDIR)/ft_strlen.c
		  $(SOURCEDIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDEDIR)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar rcs libft.a $(OBJECTS)
%.o: %.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@ 

clean:
	rm $(OBJECTS)

fclean: clean
	rm $(TARGET)

re: fclean all

.PHONY: re all fclean clean
