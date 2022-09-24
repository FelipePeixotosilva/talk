# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpeixoto <fpeixoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 15:06:05 by fpeixoto          #+#    #+#              #
#    Updated: 2022/09/24 15:18:51 by fpeixoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c
OBJS	= $(SRCS:.c=.o)
NAME	= minitalk.a
CC		= cc 
RM		= rm -f 
CFLAGS	= -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
all: $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
