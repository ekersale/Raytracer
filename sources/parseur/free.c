/*
** free.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 16:00:16 2013 pierre-edouard hanrion
** Last update Wed Jun  5 15:53:04 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"proto.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}
