##
## Makefile for 42 in /home/thomps_j//42-true
## 
## Made by julien thompson
## Login   <thomps_j@epitech.net>
## 
## Started on  Tue May 14 22:50:24 2013 julien thompson
## Last update Sun Jun  9 21:57:57 2013 elliot kersale
##

NAME		=	raytracer

INCL		=	includes

SRC_PARSEUR	=	sources/parseur/free.c			\
			sources/parseur/get_input.c		\
			sources/parseur/get_next_line.c		\
			sources/parseur/get_obj_and_light.c	\
			sources/parseur/get_str_value.c		\
			sources/parseur/get_val.c		\
			sources/parseur/get_win_and_eye.c	\
			sources/parseur/my_strncmp.c		\
			sources/parseur/pars.c			\
			sources/parseur/check_and_parse.c	\
			sources/parseur/put_in_list.c		\
			sources/parseur/set_type.c		\
			sources/parseur/skip_char.c		\
			sources/parseur/stock.c			\
			sources/parseur/str.c			\
			sources/parseur/str_to_wordtab.c	\
			sources/parseur/my_getnbr.c		\
			sources/parseur/test_file.c		\
			sources/parseur/xfunc.c

SRC_EFFECT	=	sources/effects/calculate_normal.c	\
			sources/effects/light_diffusion.c	\
			sources/effects/calc_norme.c		\
			sources/effects/calc_norme_2.c

SRC_EXE		=	sources/exe_rt/main.c			\
			sources/exe_rt/initialisation.c		\
			sources/exe_rt/traverse_pixel.c		\
			sources/exe_rt/render.c

SRC_OBJ		=	sources/obj_rt/check_intersection.c	\
			sources/obj_rt/obj_cone.c		\
			sources/obj_rt/obj_cylindre.c		\
			sources/obj_rt/obj_plan.c		\
			sources/obj_rt/obj_sphere.c		\
			sources/obj_rt/vector.c			\
			sources/obj_rt/obj_para.c		\
			sources/obj_rt/rotation.c

SRC_RESOLVE	=	sources/resolve/deg2.c

OBJ		=	$(SRC_EFFECT:.c=.o)  $(SRC_PARSEUR:.c=.o)

OBJ_2		=	$(SRC_RESOLVE:.c=.o) $(SRC_EXE:.c=.o) $(SRC_OBJ:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -W -Wshadow -Werror -I $(INCL)

FLAGS		=	-lm -lXext -lX11 -lmlx

all		:	$(NAME)

$(NAME)		:	$(OBJ) $(OBJ_2)
			@cc -o $(NAME) $(OBJ) $(OBJ_2) $(FLAGS)

clean		:
			@rm -f $(OBJ)
			@rm -f $(OBJ_2)

fclean		:	clean
			@rm -f $(NAME)

re		:	fclean all

check-syntax	:
			$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)