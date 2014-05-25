/*
** get_str_value.c for new_parse in /home/thomps_j//Local/raytracer/new_parse
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Mon Apr  8 14:23:06 2013 julien thompson
** Last update Wed Jun  5 15:55:44 2013 elliot kersale
*/
#include	<stdio.h>
#include	<math.h>
#include	"proto.h"
#include	"xfunc.h"

char		*check_sign(char *str, int *sign)
{
  *sign = 1;
  if (*str == '-')
    {
      str++;
      *sign = -1;
    }
  return (str);
}

char		*get_float_nbr(char *str, float *nbr)
{
  int		i;
  int		sign;

  str = check_sign(str, &sign);
  *nbr = 0;
  while (*str && *str >= '0' && *str <= '9')
    {
      *nbr = *nbr * 10 + *str - '0';
      str++;
    }
  if (*str && *str == '.')
    {
      i = 0;
      str++;
      while (*str && *str >= '0' && *str <= '9')
	{
	  *nbr = *nbr * 10 + *str - '0';
	  i++;
	  str++;
	}
      *nbr = (*nbr) / pow(10, (float)(i));
    }
  if (sign == -1)
    *nbr *= -1;
  return (str);
}

char		*get_vector(char *str, t_vect *vec)
{
  str = get_float_nbr(str, &vec->x);
  str = skip_void(str);
  if (*str != ',')
    xerror("Invalid vector declaration.\n");
  str++;
  str = skip_void(str);
  str = get_float_nbr(str, &vec->y);
  str = skip_void(str);
  if (*str != ',')
    xerror("Invalid vector declaration.\n");
  str++;
  str = skip_void(str);
  str = get_float_nbr(str, &vec->z);
  str = skip_void(str);
  return (str);
}

char		*get_color(char *str, t_col *col)
{
  str = get_float_nbr(str, &col->red);
  str = skip_void(str);
  if (*str != ',')
    xerror("Invalid color declaration.\n");
  str++;
  str = skip_void(str);
  str = get_float_nbr(str, &col->green);
  str = skip_void(str);
  if (*str != ',')
    xerror("Invalid color declaration.\n");
  str++;
  str = skip_void(str);
  str = get_float_nbr(str, &col->blue);
  str = skip_void(str);
  return (str);
}
