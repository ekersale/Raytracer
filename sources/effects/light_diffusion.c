/*
** light_diffusion.c for rt in /home/thomps_j//SVN/raytracer-2017-porres_m/new_start
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Thu May  2 03:33:40 2013 julien thompson
** Last update Sun Jun  9 22:37:15 2013 elliot kersale
*/

#include	<math.h>
#include	"types.h"
#include	"proto.h"

float		add_light_diff(t_var *var, t_data *data)
{
  float		norme;
  float		angle;
  float		scalaire;
  float		val_abs;
  t_vect	l_dist;
  t_ray		l_ray;

  l_dist.x = var->light->pos.x - var->new_pos.x;
  l_dist.y = var->light->pos.y - var->new_pos.y;
  l_dist.z = var->light->pos.z - var->new_pos.z;
  l_ray.init = var->new_pos;
  val_abs = fabsf(l_dist.x) + fabsf(l_dist.y) + fabsf(l_dist.z);
  l_ray.dir = vect_scal(1 / val_abs, &l_dist);
  if (check_intersection(&l_ray, &val_abs, data))
    return (0.0);
  scalaire = ((l_dist.x * var->normal.x) + (l_dist.y * var->normal.y)
	      + (l_dist.z * var->normal.z)) * data->coeff;
  norme = (sqrtf(powf(l_dist.x, 2.0) + powf(l_dist.y, 2.0) +
		 powf(l_dist.z, 2.0)) * sqrtf(powf(var->normal.x, 2.0) +
		 powf(var->normal.y, 2.0) + powf(var->normal.z, 2.0)));
  angle = scalaire / norme;
  if (angle <= 0.0)
    return (0.0);
  return (angle);
}
