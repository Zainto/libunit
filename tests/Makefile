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

NAME = UnitTest
LIBFT = $(PATHL)libft.a
LIBUT = $(PATHU)libunit.a
CLEANUP =rm -rf
MKDIR = mkdir -p

PATHO =objs/
PATHI =includes/
PATHL =../libft/
PATHU =../
PATHILIBFT =../libft/includes/
PATHILIBUT =../includes/

PATHSTRLEN = strlen/
INCS += libft.h
INCS += libunit.h
INCS += unittest.h

SRCS += main.c
_SRCSTRLEN += $(PATHSTRLEN)00_launcher.c
_SRCSTRLEN += $(PATHSTRLEN)01_basic_test.c

_OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))
_OBJSTRLEN = $(patsubst $(PATHSTRLEN)%.c, $(PATHO)%.o, $(_SRCSTRLEN))
OBJS = $(_OBJS) $(_OBJSTRLEN)

WFLAGS +=-Wall
WFLAGS +=-Werror
WFLAGS +=-Wextra
IFLAGS =-I$(PATHI) -I$(PATHILIBFT) -I$(PATHILIBUT)
CFLAGS =$(WFLAGS)

.PHONY: all clean fclean

vpath %.c strlen
vpath %.h includes
vpath %.h ../includes 
vpath %.h ../libft/includes

all : $(PATHO) $(NAME)

$(NAME): $(LIBFT) $(LIBUT) $(OBJS)
	$(CC) -o $@ $^
	@printf "$(GREEN)$@ is ready.\n$(NC)"

$(LIBFT) : 
	$(MAKE) -C $(PATHL) 

$(LIBUT) : 
	$(MAKE) -C $(PATHU) 

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $(IFLAGS) $< -o $@
	@printf "$(BLUE)Compiling $<\n$(NC)"

$(PATHO) :
	$(MKDIR) $(PATHO)

clean:
	@$(CLEANUP) $(PATHO)*.o
	@printf "$(RED)All *.o files removed\n$(NC)"
	$(MAKE) -C $(PATHL) clean
	@$(CLEANUP) $(EXEC)
	@printf "$(RED)Test exec removed\n$(NC)"

fclean: clean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	@printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all
