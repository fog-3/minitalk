SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft
	@$(CC) -o $@ $< -Llibft -lft
	@echo "\n -------------- ✅ Server is ready ✅ -------------- \n"

client: client.o libft
	@$(CC) -o $@ $< -Llibft -lft
	@echo "\n -------------- ✅ Client is ready ✅ -------------- \n"

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

libft:
	@make -C libft
	@echo "\n -------------- ✅ Libft Compiled ✅ -------------- \n"

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re