NAME = TicTacToe
SOURCES = main.c utils.c smallest_value.c db.c
SOURCES_CUDA = main.cu maths.cu moves.cu print.cu UTC.cu utils.cu VM.cu eval_test.cu
INCLUDES = head.h maths.h
OUT = $(addprefix out/, $(SOURCES:.c=.o))
SRCS = $(addprefix srcs/, $(SOURCES))

OUT_CUDA = $(addprefix out_cuda/, $(SOURCES_CUDA:.cu=.o))
SRCS_CUDA = $(addprefix srcs_cuda/, $(SOURCES_CUDA))

all: $(NAME)

$(NAME): $(OUT)
	gcc -I includes -o $(NAME) $(OUT) -lm

cuda: $(OUT_CUDA)
	nvcc -I includes -o CUDA_TicTacToe $(OUT_CUDA) -lm
out_cuda/%.o: srcs_cuda/%.cu
	mkdir -p out_cuda
	nvcc -I includes -o $@ -c $<

out/%.o: srcs/%.c
	mkdir -p out
	gcc -I includes -o $@ -c $<

clean:
	rm -rf out
	rm -rf out_cuda

fclean: clean
	rm -rf $(NAME)
	rm -f CUDA_TicTacToe

re: fclean all