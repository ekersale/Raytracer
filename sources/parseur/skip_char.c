/*
** skip_char.c for check in /home/thomps_j//Local/corewar_safe
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri Mar 29 18:11:07 2013 julien thompson
** Last update Wed Jun  5 16:31:39 2013 elliot kersale
*/

#include	"proto.h"

char		*skip_useless(char *str)
{
  str = skip_text(str);
  str = skip_void(str);
  str = skip_text(str);
  str = skip_void(str);
  return (str);
}

char		*skip_next(char *str)
{
 str = skip_text(str);
 str = skip_void(str);
 return (str);
}

char		*skip_void(char *line)
{
  while (*line && (*line == ' ' || *line == '\t'))
    line++;
  return (line);
}

char		*skip_text(char *line)
{
  while (*line && *line != ' ' && *line != '\t')
    line++;
  return (line);
}
