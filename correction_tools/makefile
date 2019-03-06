# ************************************************************************** */
#                                                                            */
#                                                        :::      ::::::::   */
#   makefile                                           :+:      :+:    :+:   */
#                                                    +:+ +:+         +:+     */
#   By: jprunel <jprunel@student.42.fr>            +#+  +:+       +#+        */
#                                                +#+#+#+#+#+   +#+           */
#   Created: 2019/01/31 14:25:02 by jprunel           #+#    #+#             */
#   Updated: 2019/01/31 14:25:02 by jprunel          ###   ########.fr       */
#                                                                            */
# ************************************************************************** */

FILE = gnl
FCT = get_next_line.c
NAME = gnl_main.c
OUTPUT = gnl_main
LIB = libft
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: test

test : lib
	$(CC) $(FLAGS) $(NAME) -o $(OUTPUT) $(FILE)/$(FCT) -I $(FILE) -L./$(FILE)/libft -lft -I.$(FILE)/libft

lib:
	make -C $(FILE)/libft/

clean:
	rm -rf $(OUTPUT)

fclean: clean
	make fclean -C $(FILE)/libft

re : clean all

libre: fclean all
