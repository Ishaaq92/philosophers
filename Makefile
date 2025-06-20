# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 16:37:25 by ishaaq            #+#    #+#              #
#    Updated: 2025/06/20 12:16:39 by ishaaq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra  -I. -g
ODIR = objs
CC = gcc
CFILES = main.c init.c utils.c routine.c monitoring.c mutexes.c precision.c edge.c
BINARY = philo
OBJECTS = $(CFILES:%.c=$(ODIR)/%.o)

all: $(ODIR) $(BINARY)

$(ODIR):
	mkdir -p $(ODIR)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BINARY)
$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(ODIR)/$(OBJECTS)
	rm -rf $(ODIR)/

fclean:
	rm -rf $(ODIR)/$(OBJECTS)
	rm -rf $(ODIR)/
	rm -rf $(BINARY)
