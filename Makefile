NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj
HEADER = ft_printf.h

SRCS = ft_printf.c ft_printf_s.c ft_printf_u.c ft_printf_c.c ft_printf_i.c ft_printf_p.c ft_printf_x.c ft_printf_bx.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c
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

$(NAME): $(OBJS)
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(BOLD)$(GREEN)%12s$(RESET): Library created successfully!\n" $(NAME)

$(OBJ_DIR)/%.o: ./%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) library\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
