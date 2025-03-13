CFLAGS = -I. -fsanitize=address
CC = gcc
ODIR = objs
SDIR = srcs

VPATH = $(SDIR)

BINARY = philo

CFILES = philo.c utils.c init.c actions.c

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
	rm -rf $(OBJECTS)/*
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re
