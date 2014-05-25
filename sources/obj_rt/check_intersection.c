/*
** check_intersection.c for rt in /home/thomps_j//SVN/raytracer-2017-porres_m/new_start
**
** Made by julien thompson
** Login   <thomps_j@epitech.net>
**
** Started on  Thu May  2 01:02:13 2013 julien thompson
** Last update Fri Jun  7 14:32:21 2013 elliot kersale
*/

#include	<stdlib.h>
#include	"types.h"
#include	"proto.h"

static int	(*g_obj_inter[])(t_data *, float *, t_obj *, t_ray *) =
{
  &inter_sphere,
  &inter_plan,
  &inter_cone,
  &inter_cylindre,
  &inter_para1,
  &inter_para2,
  NULL
};

int		is_obj_intersection(t_data *data, float *dist, t_obj *cur, t_ray *r)
{
  if (g_obj_inter[cur->type](data, dist, cur, r))
    return (1);
  return (0);
}

t_obj		*check_intersection(t_ray *r, float *dist, t_data *data)
{
  t_obj		*nearest;
  t_obj		*current;

  nearest = NULL;
  current = data->obj;
  while (current)
    {
      if (is_obj_intersection(data, dist, current, r))
	nearest = current;
      current = current->next;
    }
  if (!nearest)
    return (NULL);
  return (nearest);
}
