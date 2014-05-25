/*
** get_obj_and_light.c for new_parse in /home/thomps_j//Local/raytracer/new_parse
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Mon Apr  8 18:25:26 2013 julien thompson
** Last update Wed Jun  5 15:55:26 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"get_next_line.h"
#include	"xfunc.h"
#include	"proto.h"

t_data		*get_obj_and_light(int fd, t_data *data)
{
  char		*line;
  int		end;

  end = 0;
  line = NULL;
  while (end == 0)
    {
      line = get_next_line(fd);
      if (line == NULL || str_match(line, "#EOF") == 1)
	end = 1;
      else
	{
	  if (my_strncmp(line, "LIGHT", my_strlen("LIGHT")) == 0)
	    data->light = get_light(line, data->light);
	  else
	    data->obj = get_obj(line, data->obj);
	}
      if (line != NULL)
	free(line);
    }
  return (data);
}
