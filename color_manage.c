/*
** color_manage.c for colormanage in /home/besnai_m/rendu/Igraph/MUL_2014_wolf3d
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Dec 23 18:32:56 2014 michael besnainou
** Last update Fri Jan  2 20:10:43 2015 michael besnainou
*/

#include <math.h>
#include "include/mlx_int.h"
#include "include/mlx.h"
#include "include/my.h"

char            *my_put_pixel_to_image_wall(int x, int y, t_mlx libx)
{
  int		octet;
  int		i;

  octet = ((y * libx.sizeline - libx.sizeline) + (x * libx.bpp / 8));
  i = octet - libx.bpp / 8;
  while (i != octet)
    {
      libx.data[i] = 150;
      i = i + 1;
    }
  return (libx.data);
}

char            *my_put_pixel_to_image_sky(int x, int y, t_mlx libx)
{
  int		octet;
  int		i;

  octet = ((y * libx.sizeline - libx.sizeline) + (x * libx.bpp / 8));
  i = octet - libx.bpp / 8;
  while (i != octet)
    {
      libx.data[i] = 150;
      libx.data[i + 1] = 150;
      libx.data[i + 2] = 0;
      libx.data[i + 3] = 0;
      i = i + 4;
    }
  return (libx.data);
}

char            *my_put_pixel_to_image_sol(int x, int y, t_mlx libx)
{
  int		octet;
  int		i;

  octet = ((y * libx.sizeline - libx.sizeline) + (x * libx.bpp / 8));
  i = octet - libx.bpp / 8;
  while (i != octet)
    {
      libx.data[i] = 0;
      i = i + 1;
    }
  return (libx.data);
}

void		draw_sky(t_struct *stru)
{
  int		x;
  int		y;

  y = 1;
  while (y != 350)
    {
      x = 1;
      while (x != 700)
	{
	  my_put_pixel_to_image_sky(x, y, stru->libx);
	  x = x + 1;
	}
      y = y + 1;
    }
}

void		draw_sol(t_struct *stru)
{
  int		x;
  int		y;

  y = 350;
  while (y != 700)
    {
      x = 1;
      while (x != 700)
	{
	  my_put_pixel_to_image_sol(x, y, stru->libx);
	  x = x + 1;
	}
      y = y + 1;
    }
}
