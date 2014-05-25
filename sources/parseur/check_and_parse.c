/*
** check_and_parse.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Wed Jun  5 02:35:34 2013 pierre-edouard hanrion
** Last update Wed Jun  5 15:19:35 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"proto.h"
#include	"get_next_line.h"
#include	"xfunc.h"

int		check_and_parse(char *file, t_data *data)
{
  int		fd;
  char		*line;

  line = NULL;
  data->obj = NULL;
  data->light = NULL;
  fd = test_file(file);
  data = get_win_and_eye(fd, data);
  line = get_next_line(fd);
  if (str_match("#FORMS", line) == 0)
    xerror(FOR_ERROR);
  get_next_line(fd);
  get_next_line(fd);
  data = get_obj_and_light(fd, data);
  return (0);
}
