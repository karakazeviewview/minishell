# Compile variables
NAME := minishell
NAME_DEV := minishell_dev
CC := gcc -g
CFLAGS := -Wall -Wextra -Werror -MMD -MP -I $(shell brew --prefix readline)/include
LDFLAGS := -lreadline -lhistory -L$(shell brew --prefix readline)/lib
ifdef FOR_DEBUG
NAME := ${NAME_DEV}
DFLAGS := -g -D DEBUG -fsanitize=address
endif
SRCS_DIR := srcs/
SRCS := \
	main.c \
	terminal/terminal.c \
	terminal/environ.c \
	terminal/ft_envs.c \
	terminal/prompt.c \
	terminal/signal.c \
	terminal/error.c \
	lexer/lexer.c \
	lexer/tokenizer.c \
	lexer/formatter.c \
	lexer/lex_general.c \
	lexer/lex_string.c \
	lexer/lex_whitespace.c \
	lexer/lex_quote.c \
	lexer/lex_delimiter.c \
	lexer/lex_redirect.c \
	lexer/lex_end.c \
	lexer/lexer_utils.c \
	parser/parser.c \
	parser/parse_line.c \
	parser/parse_command.c \
	parser/parse_pipeline.c \
	parser/parse_redirect.c \
	parser/parse_argument.c \
	parser/parser_utils.c \
	expansion/expander.c \
	expansion/ft_wordexp.c \
	expansion/ft_wordexp_dollar.c \
	expansion/ft_wordexp_quote.c \
	expansion/ft_wordexp_params.c \
	expansion/ft_wordexp_utils.c \
	execution/executor.c \
	execution/exec_line.c \
	execution/exec_pipeline.c \
	execution/exec_command.c \
	execution/exec_cmd_internal.c \
	execution/exec_cmd_external.c \
	execution/ft_execvpe.c \
	execution/ft_execvpe_utils.c \
	execution/exec_utils.c \
	execution/redirect.c \
	execution/process.c \
	execution/heredoc.c \
	execution/pipeline.c \
	execution/io_utils.c \
	builtin/export.c \
	builtin/unset.c \
	builtin/echo.c \
	builtin/env.c \
	builtin/pwd.c \
	builtin/cd.c \
	builtin/exit.c \
	debug/print_token.c \
	debug/print_tree.c \
	debug/print_command.c \
	debug/print_output.c

OBJS_DIR := objs/
OBJS := ${addprefix ${OBJS_DIR},${SRCS:.c=.o}}
DEPS := ${addprefix ${OBJS_DIR},${SRCS:.c=.d}}

LIBFT_DIR := libs/ft/
LIBFT := ${LIBFT_DIR}libft.a

LIBVECTOR_DIR := libs/vector/
LIBVECTOR := ${LIBVECTOR_DIR}libvector.a

LIBDEQUE_DIR := libs/deque/
LIBDEQUE := ${LIBDEQUE_DIR}libdeque.a

LIBPQUEUE_DIR := libs/priority_queue/
LIBPQUEUE := ${LIBPQUEUE_DIR}libpqueue.a

LIBHASHMAP_DIR := libs/hashmap/
LIBHASHMAP := ${LIBHASHMAP_DIR}libhashmap.a

LIBAST_DIR := libs/ast/
LIBAST := ${LIBAST_DIR}libast.a

INCS := \
	-I./incs/ \
	-I./${LIBFT_DIR}incs/ \
	-I./${LIBDEQUE_DIR}incs/ \
	-I./${LIBVECTOR_DIR}incs/ \
	-I./${LIBPQUEUE_DIR}incs/ \
	-I./${LIBHASHMAP_DIR}incs/ \
	-I./${LIBAST_DIR}incs/

# Print variab
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K
MOVE := \033[1F
CR := \033[1G

# Progress variables
SRC_TOT := ${shell expr ${words ${SRCS}} - $(shell ls -l ${OBJS_DIR} | grep .o$ | wc -l)}
ifndef SRC_TOT
	SRC_TOT := ${words ${SRCS}}
endif
SRC_CNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_CNT) / $(SRC_TOT))
PROGRESS = $(eval SRC_CNT = $(shell expr ${SRC_CNT} + 1)) \
	${PRINTF} "${DEL}${GREEN}[ %d/%d (%d%%) ] ${CC} ${CFLAGS} $< ...${DEFAULT}${CR}" $(SRC_CNT) $(SRC_TOT) $(SRC_PCT)

# Main commands
${NAME}: ${LIBFT} ${LIBDEQUE} ${LIBVECTOR} ${LIBPQUEUE} ${LIBHASHMAP} ${LIBAST} ${OBJS} echo-character-off
	@${CC} ${CFLAGS} ${DFLAGS} ${INCS} ${OBJS} ${LIBFT} ${LIBDEQUE} ${LIBVECTOR} ${LIBPQUEUE} ${LIBHASHMAP} ${LIBAST} ${LDFLAGS} -o $@
	@echo "\n${BLUE}--- ${NAME} is up to date! ---${DEFAULT}"

${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory

${LIBDEQUE}:
	@${MAKE} -C ${LIBDEQUE_DIR} --no-print-directory

${LIBVECTOR}:
	@${MAKE} -C ${LIBVECTOR_DIR} --no-print-directory

${LIBPQUEUE}:
	@${MAKE} -C ${LIBPQUEUE_DIR} --no-print-directory

${LIBHASHMAP}:
	@${MAKE} -C ${LIBHASHMAP_DIR} --no-print-directory

${LIBAST}:
	@${MAKE} -C ${LIBAST_DIR} --no-print-directory

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@${PROGRESS}
	@${CC} ${CFLAGS} ${DFLAGS} ${INCS} -c $< -o $@

-include ${DEPS}

#: Make executable file.
all: ${NAME}

#: Remove all object files.
clean:
	@${RM} ${OBJS} ${DEPS}
	@${MAKE} clean -C ${LIBFT_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBDEQUE_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBVECTOR_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBPQUEUE_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBHASHMAP_DIR} --no-print-directory
	@${MAKE} clean -C ${LIBAST_DIR} --no-print-directory
	@${PRINTF} "${RED}Cleaned up object files in ${basename ${NAME}} ${DEFAULT}\n"

#: Remove all object and executable files.
fclean:	clean
	@${RM} ${NAME} ${NAME_DEV}
	@${RM} ${LIBFT}
	@${RM} ${LIBDEQUE}
	@${RM} ${LIBVECTOR}
	@${RM} ${LIBPQUEUE}
	@${RM} ${LIBHASHMAP}
	@${RM} ${LIBAST}
	@${PRINTF} "${RED}Removed object and executable files in ${NAME} ${DEFAULT}\n"

#: Remove and recompile all.
re: fclean
	@${MAKE} -s all

#: Make executable file and exexute.
run: ${NAME}
	@./${NAME}

#: [debug] Print debug info.
dev: clean
	@${MAKE} FOR_DEBUG=1 --no-print-directory

#: Push to git repository.
git:
	git add .
	git commit
	git push origin feature

#: Check norminette.
norm:
	@${PRINTF} "${RED}\nChecking norm for ${NAME}...${DEFAULT}\n "
	@norminette ${SRCS_DIR} incs/ libs/

#: Check allowed function.
nm:
	@nm -u ${NAME}

#: Check source files.
echo:
	@echo ${SRCS}

echo-character-off:
	@echo "set echo-control-characters off" >> ~/.inputrc

#: Display all commands.
help:
	@grep -A1 -E "^#:" Makefile \
	| grep -v -- -- \
	| sed 'N;s/\n/###/' \
	| sed -n 's/^#: \(.*\)###\(.*\):.*/\2###\1/p' \
	| sed -e 's/^/make /' \
	| column -t -s '###'

.PHONY:
	all clean fclean re run dev git norm nm help
