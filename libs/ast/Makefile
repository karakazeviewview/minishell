# Compile variables
NAME := libast.a
CC := gcc

SRCS := \
	astree_create.c \
	astree_delete.c \
	astree_set.c \
	astree_get.c

SRC_DIR := srcs/
OBJ_DIR := objs/

ALL_SRCS := ${addprefix ${SRC_DIR},${SRCS}}
ALL_OBJS := ${addprefix ${OBJ_DIR},${SRCS:.c=.o}}

INCS := -I./incs
CFLAGS := -Wall -Wextra -Werror
AR := ar rc

# Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K
CR := \033[1G

# Progress variables
SRC_TOT := ${shell expr ${words ${ALL_SRCS}} - $(shell ls -l ${OBJ_DIR} | grep .o$ | wc -l)}
ifndef SRC_TOT
	SRC_TOT := ${words ${ALL_SRCS}}
endif
SRC_CNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_CNT) / $(SRC_TOT))
PROGRESS = $(eval SRC_CNT = $(shell expr ${SRC_CNT} + 1)) \
	${PRINTF} "${DEL}${GREEN}[ %d/%d (%d%%) ] ${CC} ${CFLAGS} $< ...${DEFAULT}${CR}" $(SRC_CNT) $(SRC_TOT) $(SRC_PCT)

# Command
${NAME}: ${ALL_OBJS}
	@echo "\n${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"
	@${AR} ${NAME} ${ALL_OBJS}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${PROGRESS}
	@${CC} ${CFLAGS} ${INCS} -c $< -o $@

all: ${NAME}

clean:
	@${RM} ${ALL_OBJS}
	@${PRINTF} "${RED}Cleaned up object files in ${basename ${NAME}}${DEFAULT}\n"

fclean: clean
	@${RM} ${NAME}
	@${PRINTF} "${RED}Removed object and executable files in ${basename ${NAME}}${DEFAULT}\n"

re: fclean
	@${MAKE} -s all

git:
	git add .
	git commit
	git push

.PHONY: all bonus clean fclean re git
