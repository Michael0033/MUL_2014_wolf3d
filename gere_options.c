/*
** wolf3d2.c for wolf3d2 in /home/besnai_m/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Dec 23 17:56:10 2014 michael besnainou
** Last update Fri Jan  2 20:10:33 2015 michael besnainou
*/

#include <math.h>
#include "include/mlx.h"
#include "include/mlx_int.h"
#include "include/my.h"

extern int	lab[15][15];

int		gere_expose(t_struct *stru)
{
  mlx_put_image_to_window(stru->libx.mlx_ptr,
			  stru->libx.win_ptr, stru->libx.img, 0, 0);
  return (0);
}

int             gere_left_right(int key, t_struct *stru)
{
  if (key == 65361)
    stru->form.a = stru->form.a + 0.09;
  if (key == 65363)
    stru->form.a = stru->form.a - 0.09;
  gere_up(key, stru);
  return (0);
}

int		gere_up(int key, t_struct *stru)
{
  double	speed;
  int		tmp1;
  int		tmp2;

  speed = 0.08;
  if (key == 65362)
    {
      tmp1 = stru->form.x + 0.09 * cos(stru->form.a);
      tmp2 = stru->form.y + 0.09 * sin(stru->form.a);
      if (lab[tmp1][tmp2] == 1)
      	return (0);
      stru->form.x = stru->form.x + speed * cos(stru->form.a);
      stru->form.y = stru->form.y + speed * sin(stru->form.a);
    }
  gere_down(key, stru);
  if (key == 65307)
    exit (1);
  wolf(stru);
  return (0);
}

int		gere_down(int key, t_struct *stru)
{
  double	speed_reverse;
  int		tmp1;
  int		tmp2;

  speed_reverse = 0.05;
  if (key == 65364)
    {
      tmp1 = stru->form.x - 0.06 * cos(stru->form.a);
      tmp2 = stru->form.y - 0.06 * sin(stru->form.a);
      if (lab[tmp1][tmp2] == 1)
	return (0);
      stru->form.x = stru->form.x - speed_reverse * cos(stru->form.a);
      stru->form.y = stru->form.y - speed_reverse * sin(stru->form.a);
    }
  return (0);
}

void		fonctions(t_struct *stru)
{
  values(stru);
  draw_sky(stru);
  draw_sol(stru);
}
