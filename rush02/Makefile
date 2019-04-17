# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 10:33:28 by jkaplin           #+#    #+#              #
#    Updated: 2018/11/11 19:54:04 by jkaplin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle
NAME00 = colle-00
NAME01 = colle-01
NAME02 = colle-02
NAME03 = colle-03
NAME04 = colle-04
NAME2 = colle-2
RUSH0 = rush00/rush00.c rush00/rush00_str.c
RUSH0_O = rush00.o rush00_str.o
RUSH00 = rush00/main00.c
RUSH01 = rush00/main01.c
RUSH02 = rush00/main02.c
RUSH03 = rush00/main03.c
RUSH04 = rush00/main04.c
RUSHO0 = main00.o
RUSHO1 = main01.o
RUSHO2 = main02.o
RUSHO3 = main03.o
RUSHO4 = main04.o
RUSH2 = rush02/main.c rush02/read.c rush02/dimensions.c rush02/print.c
RUSH2_O = main.o read.o dimensions.o print.o
OBJ = rush00.o rush00_str.o main00.o main01.o main02.o main03.o main04.o \
	  main.o read.o dimensions.o print.o
HDR = headers

all: $(NAME)

$(NAME): $(NAME00) $(NAME01) $(NAME02) $(NAME03) $(NAME04) $(NAME2)
$(NAME00):
	gcc -c -Wall -Werror -Wextra $(RUSH0) $(RUSH00) -I $(HDR)
	gcc -Wall -Werror -Wextra $(RUSH0_O) $(RUSHO0) -o $(NAME00)
$(NAME01):
	gcc -c -Wall -Werror -Wextra $(RUSH0) $(RUSH01) -I $(HDR)
	gcc -Wall -Werror -Wextra $(RUSH0_O) $(RUSHO1) -o $(NAME01)
$(NAME02):
	gcc -c -Wall -Werror -Wextra $(RUSH0) $(RUSH02) -I $(HDR)
	gcc -Wall -Werror -Wextra $(RUSH0_O) $(RUSHO2) -o $(NAME02)
$(NAME03):
	gcc -c -Wall -Werror -Wextra $(RUSH0) $(RUSH03) -I $(HDR)
	gcc -Wall -Werror -Wextra $(RUSH0_O) $(RUSHO3) -o $(NAME03)
$(NAME04):
	gcc -c -Wall -Werror -Wextra $(RUSH0) $(RUSH04) -I $(HDR)
	gcc -Wall -Werror -Wextra $(RUSH0_O) $(RUSHO4) -o $(NAME04)
$(NAME2):
	gcc -c -Wall -Werror -Wextra $(RUSH0) $(RUSH2) -I $(HDR)
	gcc -Wall -Werror -Wextra $(RUSH0_O) $(RUSH2_O) -o $(NAME2)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME00) $(NAME01) $(NAME02) $(NAME03) $(NAME04) $(NAME2)
re: fclean all
