CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

ARFLAGS = L./libft
ARLIBS = libft.a

SOURCES = 
OBJECTS = $(SOURCES:.c=.o)

SOURCES_UNBONUS = 
OBJECTS_UNBONUS = $(SOURCES_UNBONUS:.c=.o)

SOURCES_BONUS = 
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_UNBONUS)
	make -C libft/ all
	ar rcs $(NAME) $(ARFLAGS) $(ARLIBS) $(OBJECTS) $(OBJECTS_UNBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	make -C libft/ fclean
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	make -C libft/ clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar rcs $(NAME) $(ARFLAGS) $(ARLIBS) $(OBJECTS) $(OBJECTS_BONUS)

.PHONY: clean fclean all re bonus
