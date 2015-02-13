/*
** my.h for my.h in /home/besnai_m/rendu/Igraph/minilibx/Exo_test
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Dec 16 17:54:50 2014 michael besnainou
** Last update Sun Jan  4 18:13:33 2015 michael besnainou
*/

#ifndef			MY_H_
# define		MY_H_

typedef struct		s_coor
{
  int			x;
  int			y;
}			t_coor;

typedef struct		s_mlx
{
  void			*mlx_ptr;
  void			*win_ptr;
  void			*img;
  int			bpp;
  int			sizeline;
  int			endian;
  char			*data;
}			t_mlx;

typedef struct		s_form
{
  double       		i;
  double		x;
  double       		y;
  double		D;
  double		P;
  double		x1;
  double		y1;
  double		a;
  double		Xp;
  double		Yp;
  double		Vx;
  double		Vy;
  double		k;
  int			murx;
  int			mury;
  int			taille_mur;
  int			slt;
}			t_form;

typedef struct		s_struct
{
  t_coor		coor;
  t_mlx			libx;
  t_form		form;
}			t_struct;

char			*my_put_pixel_to_image(int x, int y, t_mlx libx);
char			*put_black_to_my_image(int x, int y, t_mlx libx);
void			wolf(t_struct *stru);
void			my_putchar(char c);
void			my_putstr(char *str);
int			my_strlen(char *str);
char			*my_put_pixel_to_image_wall(int x, int y, t_mlx libx);
char			*my_put_pixel_to_image_sky(int x, int y, t_mlx libx);
char			*my_put_pixel_to_image_sol(int x, int y, t_mlx libx);
int			gere_expose(t_struct *stru);
int			gere_left_right(int key, t_struct *stru);
int			gere_up(int key, t_struct *stru);
int			gere_down(int key, t_struct *stru);
void			draw_sky(t_struct *stru);
void			draw_sol(t_struct *stru);
int			values(t_struct *stru);
void			fonctions(t_struct *stru);

#endif			/* !MY_H_ */
