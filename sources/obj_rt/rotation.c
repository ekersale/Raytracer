/*
** rotation.c for RT in /home/porres_m//PROJETS/igraph/RT/raytracer-2017-porres_m/rotation
** 
** Made by martin porres
** Login   <porres_m@epitech.net>
** 
** Started on  Fri Jun  7 16:30:46 2013 martin porres
** Last update Sat Jun  8 02:15:34 2013 vincent thibaud
*/

#include	<math.h>
#include	"proto.h"

void		rotation(t_vect *r, t_vect *rot)
{
  if (rot->x != 0)
    rotate_x(r, rot->x);
  if (rot->y != 0)
    rotate_y(r, rot->y);
  if (rot->z != 0)
    rotate_z(r, rot->z);
}

void		rotate_x(t_vect *r, float teta)
{
  float		y;
  float		z;

  teta = teta * M_PI / 180;
  y = cosf(teta) * r->y - sinf(teta) * r->z;
  z = cosf(teta) * r->z + sinf(teta) * r->y;
  r->y = y;
  r->z = z;
}

void		rotate_y(t_vect *r, float teta)
{
  float		x;
  float		z;

  teta = teta * M_PI / 180;
  x = cosf(teta) * r->x + sinf(teta) * r->z;
  z = cosf(teta) * r->z - sinf(teta) * r->x;
  r->x = x;
  r->z = z;
}

void		rotate_z(t_vect *r, float teta)
{
  float		x;
  float		y;

  teta = teta * M_PI / 180;
  x = cosf(teta) * r->x - sinf(teta) * r->y;
  y = cosf(teta) * r->y + sinf(teta) * r->x;
  r->x = x;
  r->y = y;
}
