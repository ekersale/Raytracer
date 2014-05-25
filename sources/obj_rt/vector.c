/*
** vector.c for rt in /home/thomps_j//my_new_rt/source
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sat Mar 16 01:43:36 2013 julien thompson
** Last update Tue Jun  4 17:35:29 2013 elliot kersale
*/

#include	"types.h"
#include	"proto.h"

t_vect		vect_add(t_vect *vect1, t_vect *vect2)
{
  t_vect	res;

  res.x = vect1->x + vect2->x;
  res.y = vect1->y + vect2->y;
  res.z = vect1->z + vect2->z;
  return (res);
}

t_vect		vect_sub(t_vect *vect1, t_vect *vect2)
{
  t_vect	res;

  res.x = vect1->x - vect2->x;
  res.y = vect1->y - vect2->y;
  res.z = vect1->z - vect2->z;
  return (res);
}

t_vect		vect_scal(float prod, t_vect *vect)
{
  t_vect	res;

  res.x = prod * vect->x;
  res.y = prod * vect->y;
  res.z = prod * vect->z;
  return (res);
}

float		scal_prod(t_vect *vect1, t_vect *vect2)
{
  return (vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z);
}
