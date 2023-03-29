# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:05:06 by meltremb          #+#    #+#              #
#    Updated: 2023/03/29 14:24:20 by meltremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# flags
RM		=	rm -rf

# Dir and file names
NAME	=	dbl_extension_libft.a
SRCDIR	=	src/
OBJDIR	=	bin/
SRCS	=	src/dbl_lst_add_back.c \
			src/dbl_lst_add_front.c \
			src/dbl_lst_free.c \
			src/dbl_lst_print.c \
			src/dbl_lst_rm.c \
			src/libft_calloc.c \

OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	-@ ar crs $@ $^

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
		-@ $(HIDE)mkdir -p $(OBJDIR)
		-@ $(HIDE)$(CC) $(CFLAGS) -c $< -o $@
	
# Removes objects
clean:
	-@ $(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	-@ $(RM) $(NAME)
	
# Removes objects and executables and remakes
re: fclean all
