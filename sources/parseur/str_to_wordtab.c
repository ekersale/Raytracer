/*
** str_to_wordtab.c for 4 in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 15:58:46 2013 pierre-edouard hanrion
** Last update Wed Jun  5 16:32:30 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"proto.h"
#include	"xfunc.h"

char		**str_to_wordtab(char *str)
{
  int		k;
  int		i;
  int		j;
  char		**new;

  k = 0;
  i = 0;
  new = xmalloc(sizeof(char*) * (my_strlen(str) + 1));
  while (str[k] != 0)
    {
      j = 0;
      while (str[k] != 0 && (str[k] == ' ' || str[k] == '\t'))
	k++;
      if (str[k] != 0)
	{
	  new[i] = xmalloc(my_strlen(str) + 1);
	  while (str[k] != 0 && str[k] != ' ' && str[k] != '\t')
	    new[i][j++] = str[k++];
	  new[i++][j] = 0;
	}
    }
  new[i] = NULL;
  return (new);
}
