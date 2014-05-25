/*
** get_win_and_eye.c for rt in /home/hanrio_p//rtpars
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Mon Apr  8 18:05:01 2013 pierre-edouard hanrion
** Last update Wed Jun  5 15:56:15 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"get_next_line.h"
#include	"proto.h"
#include	"xfunc.h"

t_data		*get_win_and_eye(int fd, t_data *data)
{
  data = get_dimensions(fd, data);
  data = get_eye_data(fd, data);
  return (data);
}

t_data		*get_eye_data(int fd, t_data *data)
{
  char		*line;
  char		**tab;

  line = get_next_line(fd);
  if (str_match(line, "#ORIGIN") == 0)
    xerror(EYE_ERROR);
  line = get_next_line(fd);
  tab = str_to_wordtab(line);
  if (tab[0] == NULL || str_match(tab[0], "POS") == 0 || tab[1] == NULL)
    xerror(SYNTAX_ERROR);
  get_vector(tab[1], &data->eye_pos);
  free_tab(tab);
  line = get_next_line(fd);
  tab = str_to_wordtab(line);
  if (tab[0] == NULL || str_match(tab[0], "ROT") == 0 || tab[1] == NULL)
    xerror(SYNTAX_ERROR);
  get_vector(tab[1], &data->eye_rot);
  free_tab(tab);
  free(line);
  return (data);
}

t_data		*get_dimensions(int fd, t_data *data)
{
  char		*line;
  char		**tab;

  line = get_next_line(fd);
  if (str_match(line, "#WINDOW") == 0)
    xerror(WIN_ERROR);
  line = get_next_line(fd);
  tab = str_to_wordtab(line);
  if (tab[0] == NULL || str_match(tab[0], "WINX") == 0 || tab[1] == NULL)
    xerror(SYNTAX_ERROR);
  is_num(tab[1]);
  data->winx = my_getnbr(tab[1]);
  free_tab(tab);
  line = get_next_line(fd);
  tab = str_to_wordtab(line);
  if (tab[0] == NULL || str_match(tab[0], "WINY") == 0 || tab[1] == NULL)
    xerror(SYNTAX_ERROR);
  is_num(tab[1]);
  data->winy = my_getnbr(tab[1]);
  free_tab(tab);
  free(line);
  return (data);
}
