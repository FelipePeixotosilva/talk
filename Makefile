CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

CLIENT    = client
SERVER    = server

LIBFT    =    ./libs/libft/libft.a
LIBFT_DIR    =    ./libs/libft

PRINTF    = ./libs/ft_printf/libftprintf.a
PRINTF_DIR = ./libs/ft_printf

SRC_C = client.c
SRC_S = server.c

INC_LIBFT    = -I. -I$(LIBFT_DIR)
INC_PRINTF    = -I. -I$(PRINTF_DIR)

all:    $(CLIENT) $(SERVER)

$(NAME): all


$(CLIENT): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(INC_LIBFT) $(PRINTF) $(INC_PRINTF) -o $(CLIENT)

$(SERVER): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) $(INC_LIBFT) $(PRINTF) $(INC_PRINTF) -o $(SERVER)

$(LIBFT):
	$(MAKE) -C ./libs/libft

$(PRINTF):
	$(MAKE) -C ./libs/ft_printf

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER) 

fclean: clean
	$(RM) $(CLIENT) $(SERVER) 

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
