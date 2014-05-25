/*
** xmalloc.c for xmalloc in /home/thomps_j/
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sat Jan  5 16:38:02 2013 julien thompson
** Last update Sun Jun  9 20:20:19 2013 elliot kersale
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"xfunc.h"

void		xerror(char *msg)
{
  while (*msg)
    write (2, msg++, 1);
  exit(EXIT_FAILURE);
}

int		xread(int fd, char *buf, int count)
{
  int		ret;

  if ((ret = read(fd, buf, count)) == -1)
    xerror(ERR_READ);
  buf[ret - 1] = 0;
  return (ret);
}

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    xerror(ERR_MALLOC);
  memset(ptr, 0, size);
  return (ptr);
}
