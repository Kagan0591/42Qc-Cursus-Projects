SRCS_FILES =	ft_atoi.c\
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

BONUS_SRCS_FILES = 	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

NAME = libft.a
OBJS = $(SRCS_FILES:.c=.o)
BONUS_OBJS = $(BONUS_SRCS_FILES:.c=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
ARCHIVE = ar -crs
REMOVE = rm -rf
SRCS_DIR = ./
### Colour variables ###
END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
BEIGE		= \033[36m
WHITE		= \033[37m

all: ${NAME}

${NAME}: ${OBJS}
	@${ARCHIVE} ${NAME} ${OBJS}
	@echo "${OBJS} ${GREEN}${BOLD}\n\nObjects files are added to the archive libft.a correctly\n${END}"

bonus: ${NAME} ${BONUS_OBJS}
	@${ARCHIVE} ${NAME} ${BONUS_OBJS}
	@echo "${BONUS_OBJS} ${GREEN} ${BOLD}\n\nObjects files And bonus objects files are added to the archive libft.a correctly\n${END}"

.c.o:
	$(CC) ${FLAGS} -o $@ -c $<
	@echo "${GREEN}Compilation OK!${END}"

clean:
	$(REMOVE) ${OBJS} ${BONUS_OBJS}
	@echo "\n${GREEN}${BOLD}Objects files are deleted correcly\n${END}"

fclean: clean
	@${REMOVE} ${NAME}
	@echo "\n${GREEN}${BOLD}Library are deleted too\n${END}"

re: fclean all
	@echo "${GREEN}${BOLD}Library are remaked correcly${END}"

.PHONY: clean fclean all re bonus
