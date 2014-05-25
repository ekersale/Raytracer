/*
** str.c for a in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 15:39:42 2013 pierre-edouard hanrion
** Last update Sun Jun  9 21:56:52 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"proto.h"
#include	"xfunc.h"

char		*my_strcat(char *s1, char *s2)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (s1[i] != 0)
    i++;
  while (s2[j] != 0)
    {
      s1[i] = s2[j];
      i++;
      j++;
    }
  s1[i] = 0;
  return (s1);
}

char		*my_strncpy(char *dest, char *src, int size)
{
  int		i;

  i = 0;
  while (src[i] != 0 && i < size)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  while (i < size)
    dest[i++] = 0;
  return (dest);
}

void		is_num(char *str)
{
  int		i;
  int		dot;

  dot = 0;
  i = 0;
  if (str[i] == '-' && str[i + 1] == 0)
    xerror(SYNTAX_ERROR);
  else
    i++;
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	if (str[i] == '.')
	  {
	    i++;
	    dot++;
	  }
      else
	xerror(SYNTAX_ERROR);
    }
  if (dot > 1)
    xerror(SYNTAX_ERROR);
}

int		str_match(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i] != 0)
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

char		*my_strdup(char *str)
{
  int		i;
  char		*new;

  i = 0;
  new = xmalloc(my_strlen(str) + 1);
  while (str[i] != 0)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  return (new);
}
