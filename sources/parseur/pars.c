/*
** new.c for parse in /home/thomps_j//Local/raytracer/new_parse
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Fri Apr 12 13:40:08 2013 julien thompson
** Last update Wed Jun  5 16:28:42 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"types.h"
#include	"proto.h"

void		light_power(double pwr, t_col *col)
{
  col->red *= pwr;
  col->green *= pwr;
  col->blue *= pwr;
}

t_lig		*get_light(char *str, t_lig *light)
{
  double	pwr;
  t_lig		*tmp;

  pwr = 0;
  light = put_light_in_list(light);
  tmp = light;
  while (tmp->next != NULL)
    tmp = tmp->next;
  str = skip_useless(str);
  str = get_vector(str, &tmp->pos);
  str = skip_useless(str);
  str = get_color(str, &tmp->color);
  str = skip_void(str);
  pwr = get_val(str, pwr);
  light_power(pwr, &tmp->color);
  return (light);
}

t_obj		*get_obj(char *str, t_obj *obj)
{
  double	pwr;
  t_obj		*tmp;

  pwr = 0;
  obj = put_obj_in_list(obj);
  tmp = obj;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->type = set_type(str, tmp->type);
  str = skip_next(str);
  tmp->size = get_val(str, tmp->size);
  str = skip_next(str);
  str = get_vector(str, &tmp->pos);
  str = get_color(str, &tmp->color);
  str = get_vector(str, &tmp->rot);
  str = get_color(str, &tmp->lum);
  pwr = get_val(str, pwr);
  light_power(pwr, &tmp->lum);
  str = skip_next(str);
  tmp->reflec = get_val(str, tmp->reflec);
  str = skip_next(str);
  tmp->transp = get_val(str, tmp->transp);
  return (obj);
}
