/*
** my_strlen.c for Exo02 in /home/besnai_m/rendu/day4
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Thu Oct  2 22:47:09 2014 michael besnainou
** Last update Fri Dec  5 13:25:05 2014 michael besnainou
*/

int	my_strlen(char *str)
{
  int	z;

  z = 0;
  while (str[z] != '\0')
    {
      z = z + 1;
    }
  return (z);
}
