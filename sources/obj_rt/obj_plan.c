/*
** obj_plan.c for RT in /home/porres_m//PROJETS/igraph/RT/obj
** 
** Made by martin porres
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Apr  5 16:29:02 2013 martin porres
** Last update Sat Jun  8 23:28:23 2013 elliot kersale
*/

#include	<math.h>
#include	"proto.h"

int		inter_plan(t_data *data, float *dist, t_obj *obj, t_ray *r)
{
  float		k;
  t_vect	r_tmp;

  r_tmp = r->dir;
  rotation(&r_tmp, &obj->rot);
  k = -((data->eye_pos.z - obj->pos.z) / r_tmp.z);
  if (k < *dist && k > 0)
    {
      *dist = k;
      return (1);
    }
  return (0);
}
