/*
** my_putstr.c for Exo02 in /home/besnai_m/rendu/day4
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Thu Oct  2 18:54:06 2014 michael besnainou
** Last update Mon Dec 29 12:49:35 2014 michael besnainou
*/

#include <unistd.h>
#include "../../include/my.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
