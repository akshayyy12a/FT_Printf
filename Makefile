NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj
INCLUDES = -Ilib
HEADER = ft_printf.h
LIBFT = lib/libft.a

SRCS = ft_printf.c ft_printf_s.c ft_printf_u.c ft_printf_c.c ft_printf_i.c ft_printf_p.c ft_printf_x.c ft_printf_X.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

RED        = \033[0;31m
GREEN      = \033[0;32m
YELLOW     = \033[0;33m
BLUE       = \033[0;34m
MAGENTA    = \033[0;35m
CYAN       = \033[0;36m
BOLD       = \033[1m
RESET      = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(BOLD)$(GREEN)%12s$(RESET): Library created successfully!\n" $(NAME)

$(OBJ_DIR)/%.o: ./%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@printf "$(BOLD)$(BLUE)Building libft...$(RESET)\n"
	@$(MAKE) -C lib

clean:
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)
	@$(MAKE)

fclean: clean
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) library\n" $(NAME)
	@rm -f $(NAME)
	@$(MAKE)

re: fclean all

.PHONY: all clean fclean re
