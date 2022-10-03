# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:14:50 by fpeixoto          #+#    #+#              #
#    Updated: 2022/09/27 20:27:08 by fpeixoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

CLIENT    = client
SERVER    = server
CLIENT_BONUS	= client_bonus
SERVER_BONUS	= server_bonus

LIBFT    =    ./libs/libft/libft.a
LIBFT_DIR    =    ./libs/libft

PRINTF    = ./libs/ft_printf/libftprintf.a
PRINTF_DIR = ./libs/ft_printf

SRC_C = client.c
SRC_S = server.c
SRC_C_B	= client_bonus.c 
SRC_S_B = server_bonus.c

all:    $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

$(NAME): all


$(CLIENT): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_C) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(SERVER): $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC_S) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT_BONUS): $(LIBFT) $(PRINTF)
$(SERVER_BONUS): $(LIBFT) $(PRINTF) 
$(LIBFT):
	$(MAKE) -C ./libs/libft

$(PRINTF):
	$(MAKE) -C ./libs/ft_printf

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
