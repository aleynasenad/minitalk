# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldurmaz <aldurmaz@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 18:43:03 by aldurmaz          #+#    #+#              #
#    Updated: 2025/02/26 21:10:22 by aldurmaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c funcs.c
	$(CC) $(CFLAGS) -o $(SERVER) server.c funcs.c

$(CLIENT): client.c funcs.c
	$(CC) $(CFLAGS) -o $(CLIENT) client.c funcs.c

$(SERVER_BONUS): server_bonus.c $(SRC_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) server_bonus.c funcs_bonus.c

$(CLIENT_BONUS): client_bonus.c $(SRC_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) client_bonus.c funcs_bonus.c

clean:
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re