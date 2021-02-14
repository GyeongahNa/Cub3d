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

SRC_BONUS =  bonus/exit/destroywindow_bonus.c bonus/keyinput/keyinput_bonus.c bonus/memory/cpymap_bonus.c bonus/memory/free_bonus.c \
	  bonus/memory/malloc_bonus.c bonus/presetting/load_texture_bonus.c bonus/presetting/setmap_bonus.c bonus/presetting/setup_bonus.c \
	  bonus/raycast/horzwallhit_bonus.c bonus/raycast/raycast_bonus.c bonus/raycast/vertwallhit_bonus.c bonus/render/getspriteinfo_bonus.c  \
	  bonus/render/renderfloorceiling_bonus.c bonus/render/renderminimap_bonus.c bonus/render/rendersprite_bonus.c \
	  bonus/render/rendersprite2_bonus.c bonus/render/renderwall_bonus.c bonus/savingbmp/save_bmp_bonus.c bonus/update/update_bonus.c \
	  bonus/utils/raycast_utils_bonus.c bonus/validitycheck/checkmap_bonus.c bonus/validitycheck/checkmap2_bonus.c \
	  bonus/validitycheck/checkspecifiers_bonus.c bonus/validitycheck/checkspecifiers2_bonus.c bonus/validitycheck/collectinfos_bonus.c \
	  bonus/validitycheck/collectinfos2_bonus.c bonus/validitycheck/free_bonus.c bonus/validitycheck/get_next_line_bonus.c \
	  bonus/validitycheck/get_next_line_utils_bonus.c bonus/validitycheck/importcubfile_bonus.c bonus/validitycheck/importmap_bonus.c \
	  bonus/validitycheck/validitycheck_bonus.c bonus/validitycheck/validitycheck2_bonus.c bonus/validitycheck/validitycheck_utils_bonus.c  \
	  bonus/validitycheck/validitycheck_utils2_bonus.c  bonus/main_bonus.c bonus/render/renderhud_bonus.c bonus/render/renderlifebar_bonus.c 

OBJ_BONUS = bonus/exit/destroywindow_bonus.o bonus/keyinput/keyinput_bonus.o bonus/memory/cpymap_bonus.o bonus/memory/free_bonus.o\
	  bonus/memory/malloc_bonus.o bonus/presetting/load_texture_bonus.o bonus/presetting/setmap_bonus.o bonus/presetting/setup_bonus.o\
	  bonus/raycast/horzwallhit_bonus.o bonus/raycast/raycast_bonus.o bonus/raycast/vertwallhit_bonus.o bonus/render/getspriteinfo_bonus.o\
	  bonus/render/renderfloorceiling_bonus.o bonus/render/renderminimap_bonus.o bonus/render/rendersprite_bonus.o\
	  bonus/render/rendersprite2_bonus.o bonus/render/renderwall_bonus.o bonus/savingbmp/save_bmp_bonus.o bonus/update/update_bonus.o\
	  bonus/utils/raycast_utils_bonus.o bonus/validitycheck/checkmap_bonus.o bonus/validitycheck/checkmap2_bonus.o\
	  bonus/validitycheck/checkspecifiers_bonus.o bonus/validitycheck/checkspecifiers2_bonus.o bonus/validitycheck/collectinfos_bonus.o\
	  bonus/validitycheck/collectinfos2_bonus.o bonus/validitycheck/free_bonus.o bonus/validitycheck/get_next_line_bonus.o\
	  bonus/validitycheck/get_next_line_utils_bonus.o bonus/validitycheck/importcubfile_bonus.o bonus/validitycheck/importmap_bonus.o\
	  bonus/validitycheck/validitycheck_bonus.o bonus/validitycheck/validitycheck2_bonus.o bonus/validitycheck/validitycheck_utils_bonus.o\
	  bonus/validitycheck/validitycheck_utils2_bonus.o bonus/main_bonus.o  bonus/render/renderhud_bonus.o bonus/render/renderlifebar_bonus.o

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)  $(SRC) -o cub3D.out -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

bonus : $(OBJ_BONUS)
	$(CC) $(SRC_BONUS) -o ./bonus/cub3D.out -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

clean :
		/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
		/bin/rm -f $(NAME) ./bonus/cub3D.out

re : fclean all

.PHONY : all bonus clean flean re
