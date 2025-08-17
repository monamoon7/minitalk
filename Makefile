# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
