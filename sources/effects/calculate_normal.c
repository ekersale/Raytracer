/*
** calculate_normal.c for rt in /home/thomps_j//SVN/raytracer-2017-porres_m/new_start
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Thu May  2 04:49:53 2013 julien thompson
** Last update Sun Jun  9 20:24:24 2013 elliot kersale
*/

#include	<stdlib.h>
#include	<math.h>
#include	"proto.h"

static void	(*g_obj_norm[])(t_var **) =
{
  &norme_sphere,
  &norme_plan,
  &norme_cone,
  &norme_cylindre,
  &norme_para1,
  &norme_para2,
  NULL
};

void		calc_pos(t_var *var, t_data *data, t_ray *r)
{
  var->new_pos.x = data->eye_pos.x + var->dist * r->dir.x;
  var->new_pos.y = data->eye_pos.y + var->dist * r->dir.y;
  var->new_pos.z = data->eye_pos.z + var->dist * r->dir.z;
  return ;
}

void		calculate_normal(t_var *var)
{
  g_obj_norm[var->obj->type](&var);
  return ;
}
