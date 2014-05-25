/*
** test_file.c for new_parse in /home/thomps_j//Local/raytracer/new_parse
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Mon Apr  8 12:01:11 2013 julien thompson
** Last update Wed Jun  5 16:34:35 2013 elliot kersale
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"proto.h"
#include	"xfunc.h"

int		test_file(char *file)
{
  int		fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      if ((fd = open(file, O_WRONLY | O_CREAT, 00644)) == -1)
	xerror(CANT_CREAT);
      create_new_file(fd);
      close(fd);
      my_putstr(SC_CREATED);
      exit(0);
    }
  return (fd);
}

void		create_new_file(int fd)
{
  write(fd, M_WIN, my_strlen(M_WIN));
  write(fd, M_EYE, my_strlen(M_EYE));
  write(fd, M_FOR, my_strlen(M_FOR));
  write(fd, HDR_1, my_strlen(HDR_1));
  write(fd, HDR_2, my_strlen(HDR_2));
  write(fd, HDR_3, my_strlen(HDR_3));
  write_line(fd, '-', SIZE_HDR);
  write(fd, END, my_strlen(END));
}

void		write_line(int fd, char c, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      write(fd, &c, 1);
      i++;
    }
  write(fd, "\n", 1);
}
