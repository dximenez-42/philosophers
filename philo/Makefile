NAME	= philo

CC = gcc
CFLAGS= # -Wall -Werror -Wextra

SRC =	philo.c\
		input.c\
		errors.c\
		init_philo.c\
		utils/ft_atoi.c\

SRCS = $(addprefix ./, $(SRC))

NORMAL_OBJS	= $(SRCS:.c=.o)

PRINTF	= 

LIBS = 

all: $(NAME)


$(NAME): $(NORMAL_OBJS)
	# make -C printf
	$(CC) $(NORMAL_OBJS) $(PRINTF) $(LIBS) -I philo.h -o $(NAME) -v

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(NORMAL_OBJS)
	# make clean -C printf

fclean: clean
	rm -f $(NAME)
	# make fclean -C printf

re: fclean all

.PHONY: fclean clean