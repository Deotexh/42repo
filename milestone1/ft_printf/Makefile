CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a

HEADER = ft_printf.h
LIBFT = libft/libft.a

BONUS_DIR = bonus

SOURCES = ft_printf.c helpers_print.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_UNBONUS = print_hex.c print_ptr.c print_str.c print_char.c print_int.c\
				  print_uint.c format_specs.c
OBJECTS_UNBONUS = $(SOURCES_UNBONUS:.c=.o)

SOURCES_BONUS = print_hex_bonus.c print_ptr_bonus.c print_str_bonus.c\
				print_char_bonus.c print_int_bonus.c print_uint_bonus.c\
				helpers_print_bonus.c format_specs_bonus.c helpers_bonus.c
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_UNBONUS) $(HEADER)
	make -C libft/ all
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_UNBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJECTS) $(OBJECTS_UNBONUS) $(OBJECTS_BONUS:%=$(BONUS_DIR)/%)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS) $(OBJECTS_BONUS:%=$(BONUS_DIR)/%)
	make -C libft/ all
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS:%=$(BONUS_DIR)/%)

.PHONY: clean fclean all re bonus
