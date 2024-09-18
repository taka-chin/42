NAME = ex00

CXX = c++ 

CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98
CXXFLAGS += -g

SRCS	:=	main.cpp \
			ClapTrap.cpp \

OBJS	:=	${SRCS:.cpp=.o}

RM    =    rm -rf

ROOT_DIR			= $(shell pwd)

DOCKERFILE_FORMATTER	= Dockerfile

FORMATTER_IMG_NAME	= formatter-image

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

format:
	docker build -t $(FORMATTER_IMG_NAME) . -f $(DOCKERFILE_FORMATTER)
	docker run --rm -v "$(ROOT_DIR):$(ROOT_DIR)" -w "$(ROOT_DIR)" $(FORMATTER_IMG_NAME)

.PHONY:
	all clean fclean re 
