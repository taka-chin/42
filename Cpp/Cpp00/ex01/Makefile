NAME = ex01

CXX = c++ 

CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
CXXFLAGS += -g

SRCS	:=	main.cpp \
			Contact.cpp \
			PhoneBook.cpp \

OBJS	:=	${SRCS:.cpp=.o}

RM    =    rm -rf

all:${NAME}

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

norm:
	norminette | grep -v "OK" || true

.PHONY:
	all clean fclean re 
