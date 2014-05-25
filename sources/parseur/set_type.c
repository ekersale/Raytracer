/*
** set_type.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 20:34:56 2013 pierre-edouard hanrion
** Last update Fri Jun  7 12:46:32 2013 pierre-edouard hanrion
*/

#include	<stdlib.h>
#include	"proto.h"
#include	"xfunc.h"

double		set_type(char *str, char type)
{
  char		*new;
  char		**list;
  int		i;

  type = -1;
  list = get_types_list();
  new = cut_str(str);
  i = 0;
  while (list[i] != NULL)
    {
      if (my_strncmp(new, list[i], my_strlen(list[i])) == 0)
	type = i;
      i++;
    }
  if (type == -1)
    xerror(TYPE_ERROR);
  free(new);
  free_tab(list);
  return (type);
}

char		*cut_str(char *str)
{
  char		*new;
  int		i;

  new = xmalloc(my_strlen(str) + 1);
  i = 0;
  while (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  return (new);
}

char		**get_types_list()
{
  char		**list;

  list = xmalloc(sizeof(char*) * 8);
  list[0] = my_strdup("SPHERE");
  list[1] = my_strdup("PLAN");
  list[2] = my_strdup("CONE");
  list[3] = my_strdup("CYLIND");
  list[4] = my_strdup("PARABO");
  list[5] = my_strdup("HYPERB");
  list[6] = my_strdup("MOEBIU");
  list[7] = NULL;
  return (list);
}
