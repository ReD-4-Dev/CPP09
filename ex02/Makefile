
NAME = PmergeMe

OBJ_P = ./obj/

SRCS =  main.cpp \
		PmergeMe.cpp

OBJS = $(addprefix $(OBJ_P), $(SRCS:.cpp=.o))

CXX = c++

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -std=c++98

all : $(NAME)

${OBJ_P}%.o : %.cpp
	@mkdir -p ${OBJ_P}
	$(CXX) ${CFLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf ${OBJ_P}
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all