/*
** gnl.c for gnl in /home/thomps_j//GetFileSystem
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Thu Dec 13 12:36:06 2012 julien thompson
** Last update Sun Jun  9 20:21:59 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"get_next_line.h"
#include	"xfunc.h"

char		*get_next_line(const int fd)
{
  static char	*save = NULL;
  static int	i = 0;
  char		*line;
  int		j;

  if (save == NULL)
    save = no_save(fd);
  if (save[i] == '\n')
    i++;
  else
    if (save[i] == '\0')
      return (NULL);
  j = 0;
  while (save[++i - 1] && save[i - 1] != '\n')
    j++;
  i--;
  line = xmalloc(sizeof(char) * (j + 1));
  i -= j;
  j = 0;
  while (save[i] && save[i] != '\n')
    line[j++] = save[i++];
  line[j] = '\0';
  return (line);
}
