CC = Clang
COMPILE = $(CC) -c

# Reset
NC=\033[0m

# Regular Colors
BLACK=\033[0;30m
RED=\033[0;31m
GREEN =\033[32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m

NAME = libunit.a
EXEC = test
LIBFT = $(PATHL)libft.a
CLEANUP =rm -rf
MKDIR = mkdir -p

PATHO =objs/
PATHI =includes/
PATHL = libft/
PATHS = framework/
PATHILIB =libft/includes/

INCS += libft.h
INCS += libunit.h

SRCS += $(PATHS)run_test.c
OBJS = $(patsubst $(PATHS)%.c, $(PATHO)%.o, $(SRCS))

WFLAGS +=-Wall
WFLAGS +=-Werror
WFLAGS +=-Wextra
IFLAGS =-I$(PATHI) -I$(PATHILIB)
CFLAGS =$(WFLAGS)

.PHONY: all clean fclean
.SILENT: 

vpath %.c framework
vpath %.h includes 
vpath %.h libft/includes

all : $(PATHO) $(NAME)

$(NAME): $(OBJS)
	ar rus $@ $(OBJS)
	@printf "$(GREEN)$@ is ready.\n$(NC)"

$(LIBFT) : 
	$(MAKE) -C $(PATHL)

$(OBJS): $(PATHO)%.o : %.c $(INCS) $(LIBFT)
	$(COMPILE) $(CFLAGS) $(IFLAGS) $< -o $@
	@printf "$(BLUE)Compiling $<\n$(NC)"

$(PATHO) :
	$(MKDIR) $(PATHO)

clean:
	@$(CLEANUP) $(PATHO)*.o
	@printf "$(RED)All *.o files from $(NAME) removed\n$(NC)"
	$(MAKE) -C $(PATHL) clean

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	$(MAKE) -C $(PATHL) fclean
	@printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all
