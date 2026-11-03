CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES =
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean: clean
	rm $(NAME)

clean:
	rm $(OBJETS)
	
re: fclean
	$(NAME)

.PHONY: all clean fclean re
