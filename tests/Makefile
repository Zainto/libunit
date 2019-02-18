CC = Clang
COMPILE = $(CC) -c
DEBUG = $(CC) -c -g

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
LIBFTDB = $(PATHL)libftdb.a
CLEANUP =rm -rf
MKDIR = mkdir -p

PATHO =objs/
PATHI =includes/
PATHL =../libft/
PATHILIBFT =../libft/includes/

PATHBASIC = basic/
INCS += libft.h
INCS += unittest.h

SRCS += main.c
SRCS += 00_launcher.c
SRCS += 01_basic_test.c
SRCS += 02_ko_test.c
SRCS += 03_segfault_test.c
SRCS += 04_buss_error_test.c

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))
OBJD = $(patsubst %.c, $(PATHO)db%.o, $(SRCS))

WFLAGS +=-Wall
WFLAGS +=-Werror
WFLAGS +=-Wextra
DFLAGS +=-fsanitize=address
IFLAGS =-I$(PATHI) -I$(PATHILIBFT)
CFLAGS =$(WFLAGS)

vpath %.c basic
vpath %.h includes 
vpath %.h ../libft/includes

all : $(PATHO) $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $@ $^
	@printf "$(GREEN)$@ is ready.\n$(NC)"

debug : $(PATHO) $(LIBFTDB) $(OBJD)
	$(CC) $(DFLAGS) $(LIBFTDB) $(OBJD) -o $(NAME)
	./$(NAME)

test : $(PATHO) $(NAME)
	./$(NAME)

$(LIBFT) : FORCE
	$(MAKE) -C $(PATHL) 

$(LIBFTDB) : FORCE
	$(MAKE) -C $(PATHL) debug

$(OBJS): $(PATHO)%.o : %.c $(INCS)
	$(COMPILE) $(CFLAGS) $(IFLAGS) $< -o $@
	@printf "$(BLUE)Compiling for debug $<\n$(NC)"

$(OBJD): $(PATHO)db%.o : %.c $(INCS)
	$(DEBUG) $(CFLAGS) $(DFLAGS) $(IFLAGS) $< -o $@
	@printf "$(BLUE)Compiling $<\n$(NC)"

$(PATHO) :
	$(MKDIR) $(PATHO)

clean:
	$(MAKE) -C $(PATHL) clean
	@$(CLEANUP) $(PATHO)*.o
	@printf "$(RED)All *.o files for UnitTest removed\n$(NC)"

fclean: clean
	$(MAKE) -C $(PATHL) fclean
	$(CLEANUP) $(NAME)
	$(CLEANUP) $(PATHO)
	@printf "$(RED)$(NAME) deleted\n$(NC)"

re : fclean all

FORCE:
.PHONY: all clean fclean
.SILENT: 
