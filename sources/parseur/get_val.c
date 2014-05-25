/*
** get_val.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 20:40:54 2013 pierre-edouard hanrion
** Last update Wed Jun  5 15:55:57 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"proto.h"

double		get_val(char *str, double val)
{
  char		*new;

  new = cut_str(str);
  is_num(new);
  val = atof(new);
  free(new);
  return (val);
}
