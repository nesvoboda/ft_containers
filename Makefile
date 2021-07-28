SRCS = tests/main.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = run_tests
CXXFLAGS = -Wall -Wextra -Werror
CXX = clang++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean re all