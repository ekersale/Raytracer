/*
** traverse_pixel.c for raytracer in /home/kersal_e//projets_finis/rtv1-2017-kersal_e/source
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Thu May 30 15:25:53 2013 elliot kersale
** Last update Sun Jun  9 19:59:33 2013 elliot kersale
*/
#include	<stdio.h>
#include	<mlx.h>
#include	"proto.h"

void		traverse_pixel(t_data *wind)
{
  t_col		color_calc;

  wind->y = 0;
  while (wind->y < wind->winy)
    {
      wind->x = 0;
      while (wind->x < wind->winx)
	{
	  color_calc = get_pixel_render(wind);
	  my_pixel_put_to_image(wind, wind->x, wind->y, color_calc);
	  wind->x++;
	}
      wind->y++;
    }
  mlx_put_image_to_window(wind->mlx_ptr, wind->win_ptr, wind->img_ptr , 0, 0);
  return ;
}

void		my_pixel_put_to_image(t_data *wind, int  x, int y, t_col col)
{
  int		pos;

  pos = ((y * wind->sizeline) + (x * (wind->bpp / 8)));
  wind->data[pos] = (char)col.blue;
  wind->data[pos + 1] = (char)col.green;
  wind->data[pos + 2] = (char)col.red;
  wind->data[pos + 3] = 0;
  return ;
}
