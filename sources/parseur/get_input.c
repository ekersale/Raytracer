/*
** gnl.c for gnl in /home/thomps_j//GetFileSystem
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Thu Dec 13 12:36:06 2012 julien thompson
** Last update Sun Jun  9 20:19:41 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"get_next_line.h"
#include	"xfunc.h"
#include	"proto.h"

char		*cmb_str(char *frt, char *end)
{
  char		*all;
  int		i;
  int		j;

  all = xmalloc(sizeof(char) * (my_strlen(frt) + my_strlen(end) + 1));
  i = 0;
  j = 0;
  while (frt[i])
    {
      all[i] = frt[i];
      i++;
    }
  while (end[j])
    all[i++] = end[j++];
  free(frt);
  return (all);
}

int		check_return(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != '\n')
    i++;
  if (str[i] == '\n')
    return (1);
  return (0);
}

char		*no_save(const int fd)
{
  char		*all;
  char		*tmp;

  tmp = xmalloc(sizeof(char) * READ);
  all = xmalloc(sizeof(char));
  all[0] = '\0';
  while (!check_return(all))
    {
      xread(fd, tmp, READ - 1);
      all = cmb_str(all, tmp);
    }
  all = cmb_str(all, "\0");
  free(tmp);
  return (all);
}

char		*get_input()
{
  char		*save;
  char		*line;
  int		i;

  save = no_save(0);
  line = xmalloc(sizeof(char) * (my_strlen(save) - 1));
  while (save[i] && save[i] != '\n')
    {
      line[i] = save[i];
      i++;
    }
  if (save[i] == '\n')
    line[i] = '\0';
  free(save);
  return (line);
}
