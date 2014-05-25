/*
** main.c for rt in /home/thomps_j//SVN/raytracer-2017-porres_m/new_start
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Thu May  2 00:51:46 2013 julien thompson
** Last update Tue Jun 11 19:00:03 2013 elliot kersale
*/
#include	<stdio.h>
#include	<math.h>
#include	<stdlib.h>
#include	"types.h"
#include	"proto.h"

void		set_color(t_col **rend, t_var *var)
{
  (*rend)->red = (*var).obj->color.red * (*var).light->color.red;
  (*rend)->green = (*var).obj->color.green * (*var).light->color.green;
  (*rend)->blue = (*var).obj->color.blue * (*var).light->color.blue;
}

void		render_iteration(t_ray *r, t_col *rend, t_data *data)
{
  t_var		var;
  float		an;

  var.dist = MAX_DIST_VISION;
  r->init = data->eye_pos;
  if (!(var.obj = check_intersection(r, &var.dist, data)))
      return ;
  calc_pos(&var, data, r);
  calculate_normal(&var);
  var.light = data->light;
  if (var.light)
    set_color(&rend, &var);
  an = 0.0;
  while (var.light)
    {
      an += add_light_diff(&var, data);
      var.light = var.light->next;
    }
  if (an >= 1.0)
    an = 1.0;
  rend->red = rend->red * 255.0 * an;
  rend->green = rend->green * 255.0 * an;
  rend->blue = rend->blue * 255.0 * an;
  return ;
}

void		init_value(t_ray *ray, t_col *render, t_data *data)
{
  *render = data->ambi;
  ray->dir.x = 600.0;
  ray->dir.y = (float)((data->winx / 2) - data->x);
  ray->dir.z = (float)((data->winy / 2) - data->y);
  ray->init.x = data->eye_pos.x + (float)data->x;
  ray->init.y = data->eye_pos.y + (float)data->y;
  ray->init.z = data->eye_pos.z;
}

t_col		get_pixel_render(t_data *data)
{
  t_ray		ray;
  t_col		render;

  init_value(&ray, &render, data);
  data->coeff = 1.;
  render.red = 0.00;
  render.green = 0.8;
  render.blue = 0.00;
  render_iteration(&ray, &render, data);
  if (render.red > 255.)
    render.red = 255.;
  if (render.green > 255.)
    render.green = 255.;
  if (render.blue > 255.)
    render.blue = 255.;
  return (render);
}
