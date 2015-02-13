/*
** wolf3d.c for wolf3d in /home/besnai_m/rendu/Igraph/minilibx/Exo_test
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Dec 15 10:54:01 2014 michael besnainou
** Last update Sun Jan  4 23:05:10 2015 michael besnainou
*/

#include <math.h>
#include "include/mlx_int.h"
#include "include/mlx.h"
#include "include/my.h"

int		lab[15][15] =
  {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };

int		mathematicals_operations(t_struct *stru)
{
  stru->form.slt = 0;
  stru->form.x1 = 0.5;
  stru->form.y1 = ((350 - stru->form.i) / 700);
  stru->form.Xp = (0.5 * (cos(stru->form.a))) -
    (stru->form.y1 * (sin(stru->form.a)));
  stru->form.Yp = (0.5 * (sin(stru->form.a))) +
    (stru->form.y1 * (cos(stru->form.a)));
  stru->form.Xp = stru->form.Xp + stru->form.x;
  stru->form.Yp = stru->form.Yp + stru->form.y;
  stru->form.Vx = stru->form.Xp - stru->form.x;
  stru->form.Vy = stru->form.Yp - stru->form.y;
  return (0);
}

int		values(t_struct *stru)
{
  stru->form.i = 0;
  stru->form.D = 1/2;
  stru->form.P = 1;
  return (0);
}

void		wolf(t_struct *stru)
{
  fonctions(stru);
  while (stru->form.i != 700)
    {
      mathematicals_operations(stru);
      stru->form.k = 1;
      stru->form.murx = stru->form.x + stru->form.k * stru->form.Vx;
      stru->form.mury = stru->form.y + stru->form.k * stru->form.Vy;
      stru->form.i = stru->form.i + 1;
      while (lab[stru->form.murx][stru->form.mury] == 0)
	{
	  stru->form.murx = stru->form.x + stru->form.k * stru->form.Vx;
	  stru->form.mury = stru->form.y + stru->form.k * stru->form.Vy;
	  stru->form.k = stru->form.k + 0.01;
	}
      stru->form.taille_mur = (700 / (2 * stru->form.k));
      while (stru->form.slt != stru->form.taille_mur)
	{
	  my_put_pixel_to_image_wall(stru->form.i,
				     350 - stru->form.slt, stru->libx);
	  my_put_pixel_to_image_wall(stru->form.i,
				     350 + stru->form.slt, stru->libx);
	  stru->form.slt = stru->form.slt + 1;
	}
    }
  gere_expose(stru);
}

int		main()
{
  t_struct	*stru;

  stru = malloc(sizeof(t_struct));
  if (stru == NULL)
    return (1);
  stru->libx.mlx_ptr = mlx_init();
  if (stru->libx.mlx_ptr == NULL)
    return (1);
  stru->libx.win_ptr = mlx_new_window(stru->libx.mlx_ptr, 700, 700, "TEST");
  if (stru->libx.win_ptr == NULL)
    return (1);
  stru->libx.img = mlx_new_image(stru->libx.mlx_ptr, 700, 700);
  stru->libx.data = mlx_get_data_addr(stru->libx.img, &stru->libx.bpp,
				      &stru->libx.sizeline, &stru->libx.endian);
  stru->form.a = 1.4;
  stru->form.x = 2;
  stru->form.y = 2;
  wolf(stru);
  mlx_expose_hook(stru->libx.win_ptr, &gere_expose, stru);
  mlx_hook(stru->libx.win_ptr, KeyPress, KeyPressMask, &gere_left_right, stru);
  mlx_loop(stru->libx.mlx_ptr);
  free(stru);
  return (0);
}
