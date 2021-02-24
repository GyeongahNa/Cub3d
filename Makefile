NAME = cub3D.out

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = exit/destroywindow.c keyinput/keyinput.c memory/cpymap.c memory/free.c\
	  memory/malloc.c presetting/load_texture.c presetting/setmap.c presetting/setup.c\
	  raycast/horzwallhit.c raycast/raycast.c raycast/vertwallhit.c render/getspriteinfo.c\
	  render/renderfloorceiling.c render/renderminimap.c render/rendersprite.c\
	  render/rendersprite2.c render/renderwall.c savingbmp/save_bmp.c update/update.c\
	  utils/raycast_utils.c validitycheck/checkmap.c validitycheck/checkmap2.c\
	  validitycheck/checkspecifiers.c validitycheck/checkspecifiers2.c validitycheck/collectinfos.c\
	  validitycheck/collectinfos2.c validitycheck/free.c validitycheck/get_next_line.c\
	  validitycheck/get_next_line_utils.c validitycheck/importcubfile.c validitycheck/importmap.c\
	  validitycheck/validitycheck.c validitycheck/validitycheck2.c validitycheck/validitycheck_utils.c\
	  validitycheck/validitycheck_utils2.c main.c

OBJ = exit/destroywindow.o keyinput/keyinput.o memory/cpymap.o memory/free.o\
	  memory/malloc.o presetting/load_texture.o presetting/setmap.o presetting/setup.o\
	  raycast/horzwallhit.o raycast/raycast.o raycast/vertwallhit.o render/getspriteinfo.o\
	  render/renderfloorceiling.o render/renderminimap.o render/rendersprite.o\
	  render/rendersprite2.o render/renderwall.o savingbmp/save_bmp.o update/update.o\
	  utils/raycast_utils.o validitycheck/checkmap.o validitycheck/checkmap2.o\
	  validitycheck/checkspecifiers.o validitycheck/checkspecifiers2.o validitycheck/collectinfos.o\
	  validitycheck/collectinfos2.o validitycheck/free.o validitycheck/get_next_line.o\
	  validitycheck/get_next_line_utils.o validitycheck/importcubfile.o validitycheck/importmap.o\
	  validitycheck/validitycheck.o validitycheck/validitycheck2.o validitycheck/validitycheck_utils.o\
	validitycheck/validitycheck_utils2.o main.o

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)  $(SRC) -o cub3D.out -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

clean :
	/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	/bin/rm -f $(NAME) ./bonus/cub3D.out

re : fclean all

.PHONY : all bonus clean flean re
