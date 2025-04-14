# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 17:46:13 by isahmed           #+#    #+#              #
#    Updated: 2025/04/14 21:05:55 by isahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -I. -fsanitize=address
CC = gcc
ODIR = objs
SDIR = srcs

VPATH = $(SDIR)

BINARY = philo

CFILES = philo.c utils.c init.c routine.c

OBJECTS = $(CFILES:%.c=$(ODIR)/%.o)

DIRS = $(ODIR)

all: $(BINARY)

$(DIRS):
	@mkdir -p $@

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: %.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(OBJECTS)
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re
