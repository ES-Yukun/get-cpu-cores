NAME	:= getcpu
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
SRCS	:= main.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME)

re: clean all