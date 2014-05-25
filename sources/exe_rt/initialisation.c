/*
** initialisation.c for raytracer in /home/kersal_e//projets_actuels/raytracer-2017-porres_m/new_start/sources
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Thu May 30 14:56:51 2013 elliot kersale
** Last update Sun Jun  9 21:28:50 2013 elliot kersale
*/

#include	<mlx.h>
#include	<stdlib.h>
#include	"proto.h"

int		expose_hook(t_data *wind)
{
  mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr , 0, 0);
  return (0);
}

int		key_hook(int keycode)
{
  if (keycode == 65307)
    exit(1);
  return (0);
}

int		start_window(t_data *data)
{
  if ((data->mlx_ptr = mlx_init()) == NULL)
    return (-1);
  data->img_ptr = mlx_new_image(data->mlx_ptr, data->winx, data->winy);
  data->data = mlx_get_data_addr(data->img_ptr, &data->bpp, \
				 &data->sizeline, &data->endian);
  data->win_ptr = mlx_new_window(data->mlx_ptr, data->winx, data->winy, TITLE);
  mlx_key_hook(data->win_ptr, key_hook, 0);
  traverse_pixel(data);
  mlx_expose_hook(data->win_ptr, expose_hook, data);
  mlx_loop(data->mlx_ptr);
  return (0);
}

int		initialisation(char *FILE)
{
  t_data	data;

  check_and_parse(FILE, &data);
  if ((start_window(&data)) == -1)
    return (-1);
  return (0);
}
