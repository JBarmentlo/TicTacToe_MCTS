NAME=TicTacToe
SOURCES=main.c maths.c moves.c print.c UTC.c utils.c VM.c eval_test.c
INCLUDES=head.h maths.h
OUT= $(addprefix out/, $(SOURCES:.c=.o))
SRCS= $(addprefix srcs/, $(SOURCES))


all: $(NAME)

$(NAME): $(OUT)
	gcc -I includes -o $(NAME) $(OUT) -lm

out/%.o: srcs/%.c
	mkdir -p out
	gcc -I includes -o $@ -c $<

clean:
	rm -rf out

fclean: clean
	rm -rf $(NAME)

re: fclean all