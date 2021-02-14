/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:43:29 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 11:26:21 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

# define KEYPRESSMASK 1
# define KEYRELEASEMASK 2
# define KEYPRESS 2
# define KEYRELEASE 3
# define REDCROSS 17
# define MINIMAP_SCALE_FACTOR 0.17
# define TEXHEIGHT 64
# define TEXWIDTH 64
# define FOV_ANGLE 1.0472

# include <stddef.h>

typedef struct			s_dir
{
	int	israyfacingdown;
	int	israyfacingup;
	int	israyfacingright;
	int	israyfacingleft;
}						t_dir;

typedef struct			s_horzcoordinate
{
	int		washit;
	double	x;
	double	y;
	int		texture;
	int		map_x;
	int		map_y;
}						t_horzcoord;

typedef struct			s_vertcoordinate
{
	int		washit;
	double	x;
	double	y;
	int		texture;
	int		map_x;
	int		map_y;
}						t_vertcoord;

typedef	struct			s_rayinfo
{
	t_dir			dir;
	t_horzcoord		horzcoord;
	t_vertcoord		vertcoord;
	int				washorzhit;
	double			rayangle;
	double			wallhitx;
	double			wallhity;
	double			raydistance;
	double			wallheight;
	int				texnum;
	int				wassprite;
	int				map_x;
	int				map_y;
}						t_rayinfo;

typedef struct			s_spriteinfo
{
	int			map_x;
	int			map_y;
	double		node_x;
	double		node_y;
	double		wallheight;
	int			start;
	double		s_rayangle;
	double		s_wallhitx;
	double		s_wallhity;
	int			end;
	double		e_rayangle;
	double		e_wallhitx;
	double		e_wallhity;
}						t_spriteinfo;

extern char				**g_map;
extern int				**g_imap;
extern void				*g_mlx_ptr;
extern void				*g_win_ptr;
extern void				*g_image_ptr;
extern int				*g_image_data;
extern void				*g_xpm_image_ptr;
extern int				*g_xpm_image_data;
extern int				**g_texture;
extern t_rayinfo		**g_rayinfo;
extern t_spriteinfo		**g_sprtinfo;
extern int				**g_cpmap;
extern int				**g_emptmap;
extern double			g_turndirection;
extern double			g_walkdirection;
extern double			g_lrwalkdirection;
extern double			g_movespeed;
extern double			g_rotationspeed;
extern int				g_argc;
extern int				g_tile_size;
extern int				g_map_num_rows;
extern int				g_map_num_cols;
extern int				g_window_width;
extern int				g_window_height;
extern int				g_num_rays;
extern double			g_middleline;
extern double			g_player_x;
extern double			g_player_y;
extern double			g_rotationangle;
extern double			g_life;
extern int				g_cnt;
int						getmapwidth(void);
int						getmapheight(void);
void					typecastmap();
void					getwindowsize();
void					getfirstposition();
double					matchangle(char dir);
void					getrotationangle();
void					setup(int argc);
t_rayinfo				**setstructure();
t_spriteinfo			**setsprite();
int						**setcpymap(void);
int						**setemptymap(int i);
void					cpymap(void);
void					cpyemptymap(void);
void					freestructure();
void					freesprtinfo(int cnt);
void					freetexture();
void					freeintmap(int **tmap);
void					load_texture();
int						*load_image(char *path,
						int s, int b, int e);
int						ft_keypress(int ke);
int						ft_keyrelease(int key);
int						processinput();
double					calyintercept(int columnid);
double					calxstep(int columnid);
void					horzwallhit(int columnid,
						int **map, int start, int end);
double					calxintercept(int columnid);
double					calystep(int columnid);
void					vertwallhit(int col,
						int **map, int start, int end);
void					direction(int columnid);
void					findwallhit(int columnid);
void					findwallhit2(int columnid,
double horzhitidistance, double verthitdistance);
void					raycast(int **map, int start, int end);
void					renderblock(int i, int j, int color);
void					rendermap();
void					renderrays(int i, int j, double k);
void					renderfloor();
void					renderceiling();
int						caltexx(int columnid);
int						shadow(int color, double dist);
int						gettexture(int columnid);
void					wallrendering(double dist,
int col, int k, int start);
int						checksprite();
int						findnearest(double mindistance, int mincol);
void					getbasicinfo(int nearest, int cnt);
void					getinfo(int nearest, int cnt);
int						savespriteinfo();
int						getcenter(int num);
void					renderpart(int columnid, double dist,
int color);
void					renderfrontwall(void);
void					renderwidth(int colstart,
int colend, int num);
void					renderheight(int i, int rowstart,
int num, int texx);
void					rendersprite(int num);
int						update();
int						destroywindow();
void					freeall();
double					normalizeangle(double angle);
double					distancepoints(double x1,
double y1, double x2, double y2);
int						clearimage();
void					*ft_memset(void *s, int c, size_t n);
void					renderhud(void);
void					lifecheck();
void					renderlifebar(double wstart, double wend,
						double hstart, double hend);

#endif
