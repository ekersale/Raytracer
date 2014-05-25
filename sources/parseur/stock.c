/*
** stock.c for mysh in /home/thomps_j//Local/minishell
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Mon Dec 17 14:26:50 2012 julien thompson
** Last update Sun Jun  9 13:01:34 2013 elliot kersale
*/

#include	<unistd.h>
#include	"proto.h"

void		my_putchar(char c)
{
  write (1, &c, 1);
}

int		my_putstr(char *str)
{
  if (str != NULL)
    {
      while (*str)
	my_putchar(*str++);
    }
  return (0);
}

int		my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      i++;
  return (i);
}
