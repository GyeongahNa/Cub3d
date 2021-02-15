/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitycheck.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 08:01:45 by gna               #+#    #+#             */
/*   Updated: 2020/09/04 00:29:12 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDITYCHECK_H
# define VALIDITYCHECK_H

extern int    g_r_width;
extern int    g_r_height;
extern char*  g_so_path;
extern char*  g_no_path;
extern char*  g_we_path;
extern char*  g_ea_path;
extern char*  g_s_path;
extern int    g_f_r;
extern int    g_f_g;
extern int    g_f_b;
extern int    g_c_r;
extern int    g_c_g;
extern int    g_c_b;
extern char   **g_map;
int           cntlines(char *path);
char          **set_input(char *path);
int           isrformat(char *s);
int           isdirformat(char *s, char first, char second);
int           isfcformat(char *s, char fc, int i);
int           issformat(char *s);
int           checkdirinfos(char **input);
int           checkfcinfos(char **input);
int           checkinfos(char **input, int i);
int           onlyallowed(char *s);
int           findfirstmapline(char **input);
int           findfinalmapline(char **input, int firstmapline);
int           getmaxwidth(char **input, int firstmap, int finalmap);
char          **setmap(int height, int width);
char          **getmap(char **input, int firstmap, int finalmap, int i);
int           iswallorb(char **tmap, int y, int x);
int           checkaroundb(char **tmap, int width, int height);
int           checkedge(char **tmap, int width, int height);
int           is4char(char c);
int           checkmapcontent(char **temp, int width, int height);
int           mapvalidationcheck(char **input, int firstmap, int finalmap);
void          freemap(char **tmap);
void          freeinput(char **input);
int           checkmap(char **temp, int width, int height);
int           mapvalidationcheck(char **input, int firstmap, int finalmap);
int           getlen(char *s);
void          writesentence(char *s);
int           endwithcub(char *s);
int           sanity_check(char *str);
int           ft_atoi(char *str);
int           validitycheck(char *cubfile);
int           getwidth(char *s);
int           getheight(char *s);
char          *getpath(char *s);
char          *getspath(char *s);
int           getrcolor(char *s);
int           getgcolor(char *s);
int           getbcolor(char *s, int i, int j, char *temp);
void          getrgb(char *s, int fc);
void          collectinfos(char **input, int i);
int           noscenemessage(void);
int           toomuchmessage(void);
int           incorrectformatmessage(void);
int           nosavemessage(void);
int           issave(char *s);

#endif
