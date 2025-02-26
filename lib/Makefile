NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj
INCLUDES = -Iinclude
HEADER = libft.h

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_toupper.c ft_tolower.c

SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			 ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

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

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME) $(OBJS_BONUS)
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(YELLOW)Adding bonus$(RESET) functions\n" $(NAME)
	@ar rcs $(NAME) $(OBJS_BONUS)

clean:
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
