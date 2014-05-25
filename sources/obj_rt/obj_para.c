/*
** obj_para.c for raytracer in /home/kersal_e//projets_actuels/raytracer-2017-porres_m/new_start/sources/obj_rt
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Fri May 31 09:55:51 2013 elliot kersale
** Last update Sun Jun  9 21:48:57 2013 elliot kersale
*/

#include	<math.h>
#include	"proto.h"

int		inter_para1(t_data *data, float *dist, t_obj *obj, t_ray *r)
{
  float		coef[3];
  float		oeil_obj[3];
  float		k;
  t_vect	r_tmp;

  (void)data;
  r_tmp = r->dir;
  oeil_obj[0] = r->init.x - obj->pos.x;
  oeil_obj[1] = r->init.y - obj->pos.y;
  oeil_obj[2] = r->init.z - obj->pos.z;
  rotation(&r_tmp, &obj->rot);
  coef[0] = powf(r_tmp.x, 2.0) + powf(r_tmp.y, 2.0);
  coef[1] = 2.0 * oeil_obj[0] * r_tmp.x + 2.0 * r_tmp.y * oeil_obj[1]
    - obj->size * r_tmp.z;
  coef[2] = powf(oeil_obj[0], 2.0) + powf(oeil_obj[1], 2.0) - obj->size *
    oeil_obj[2];
  k = delta(coef[0], coef[1], coef[2]);
  if (k < *dist && k > 0)
    {
      *dist = k;
      return (1);
    }
  return (0);
}

int		inter_para2(t_data *data, float *dist, t_obj *obj, t_ray *r)
{
  float		coef[3];
  float		oeil_obj[3];
  float		k;
  t_vect	r_tmp;

  (void)data;
  r_tmp = r->dir;
  oeil_obj[0] = r->init.x - obj->pos.x;
  oeil_obj[1] = r->init.y - obj->pos.y;
  oeil_obj[2] = r->init.z - obj->pos.z;
  rotation(&r_tmp, &obj->rot);
  coef[0] = coef[1] = coef[2] = 0.0;
  coef[0] = powf(r_tmp.x, 2.0) + powf(r_tmp.y, 2.0) -
    obj->size * powf(r_tmp.z, 2.0);
  coef[1] = 2.0 * ((oeil_obj[0] * r_tmp.x) + (r_tmp.y * oeil_obj[1]) -
		   (oeil_obj[2] * r_tmp.z * obj->size));
  coef[2] = powf(oeil_obj[0], 2.0) + powf(oeil_obj[1], 2.0) - obj->size *
    powf(oeil_obj[2], 2.0) - 1000.0;
  k = delta(coef[0], coef[1], coef[2]);
  if (k < *dist && k > 0)
    {
      *dist = k;
      return (1);
    }
  return (0);
}
