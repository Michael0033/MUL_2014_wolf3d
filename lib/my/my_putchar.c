/*
** my_putchar.c for my_putchar in /home/besnai_m/rendu/day7/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Oct  7 11:24:39 2014 michael besnainou
** Last update Sun Nov  9 17:59:21 2014 michael besnainou
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
