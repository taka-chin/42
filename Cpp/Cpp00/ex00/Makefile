NAME = megaphone

CXX = c++ 

CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
# CFLAGS += -std=c++11

SRCS	:=	megaphone.cpp \

OBJS	:=	${SRCS:.cpp=.o}

RM    =    rm -rf

all:${NAME}

$(NAME):$(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY:
	all clean fclean re 
