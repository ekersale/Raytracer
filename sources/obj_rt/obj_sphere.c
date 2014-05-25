/*
** obj_sphere.c for RT in /home/porres_m//PROJETS/igraph/RT/obj
** 
** Made by martin porres
** Login   <porres_m@epitech.net>
** 
** Started on  Mon Apr  8 17:22:30 2013 martin porres
** Last update Sun Jun  9 21:47:38 2013 elliot kersale
*/

#include	<math.h>
#include	"proto.h"

int		inter_sphere(t_data *data, float *dist, t_obj *obj, t_ray *r)
{
  float		coef[3];
  float		oeil_obj[3];
  float		k;
  t_vect       	r_tmp;

  (void)data;
  r_tmp = r->dir;
  oeil_obj[0] = r->init.x - obj->pos.x;
  oeil_obj[1] = r->init.y - obj->pos.y;
  oeil_obj[2] = r->init.z - obj->pos.z;
  rotation(&r_tmp, &obj->rot);
  coef[0] = powf(r_tmp.x, 2.0) + powf(r_tmp.y, 2.0) + powf(r_tmp.z, 2.0);
  coef[1] = 2.0 * (oeil_obj[0] * r_tmp.x + oeil_obj[1] * r_tmp.y
	   + oeil_obj[2] * r_tmp.z);
  coef[2] = powf(oeil_obj[0], 2) + powf(oeil_obj[1], 2) + powf(oeil_obj[2], 2)
    - powf(obj->size, 2.0);
  k = delta(coef[0], coef[1], coef[2]);
  if (k < *dist && k > 0.0)
    {
      *dist = k;
      return (1);
    }
  return (0);
}
