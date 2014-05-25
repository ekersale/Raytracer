/*
** obj_cone.c for RT in /home/porres_m//PROJETS/igraph/RT/obj
** 
** Made by martin porres
** Login   <porres_m@epitech.net>
** 
** Started on  Mon Apr  8 18:06:31 2013 martin porres
** Last update Sat Jun  8 23:12:03 2013 elliot kersale
*/

#include	<math.h>
#include	"proto.h"

int		inter_cone(t_data *data, float *dist, t_obj *obj, t_ray *r)
{
  float		coef[3];
  float		oeil_obj[3];
  float		tmp;
  t_vect       	r_tmp;

  (void)data;
  r_tmp = r->dir;
  oeil_obj[0] = r->init.x - obj->pos.x;
  oeil_obj[1] = r->init.y - obj->pos.y;
  oeil_obj[2] = r->init.z - obj->pos.z;
  rotation(&r_tmp, &obj->rot);
  tmp = powf(tanf(obj->size), 2.0);
  coef[0] = tmp * powf(r_tmp.x, 2.0) + tmp * powf(r_tmp.y, 2.0)
    - powf(r_tmp.z, 2.0);
  coef[1] = tmp * 2 * oeil_obj[0] * r_tmp.x
    + tmp * 2 * oeil_obj[1] * r_tmp.y - 2 * oeil_obj[2] * r_tmp.z;
  coef[2] = tmp * powf(oeil_obj[0], 2.0) + tmp * powf(oeil_obj[1], 2.0)
    - powf(oeil_obj[2], 2.0);
  tmp = delta(coef[0], coef[1], coef[2]);
  if (tmp < *dist && tmp > 0)
    {
      *dist = tmp;
      return (1);
    }
  return (0);
}
