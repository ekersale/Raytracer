/*
** calc_norme.c for raytracer in /home/kersal_e//projets_actuels/raytracer-2017-porres_m/new_start/sources/effects
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Fri Jun  7 14:32:47 2013 elliot kersale
** Last update Sun Jun  9 21:51:15 2013 elliot kersale
*/

#include	<math.h>
#include	"proto.h"

void		norme_sphere(t_var **var)
{
  (*var)->normal.x = (*var)->new_pos.x - (*var)->obj->pos.x;
  (*var)->normal.y = (*var)->new_pos.y - (*var)->obj->pos.y;
  (*var)->normal.z = (*var)->new_pos.z - (*var)->obj->pos.z;
  return ;
}

void		norme_plan(t_var **var)
{
  (*var)->normal.x = 0.0;
  (*var)->normal.y = 0.0;
  (*var)->normal.z = 100.0;
  return ;
}

void		norme_cone(t_var **var)
{
  (*var)->normal.x = (*var)->new_pos.x - (*var)->obj->pos.x;
  (*var)->normal.y = (*var)->new_pos.y - (*var)->obj->pos.y;
  (*var)->normal.z = ((*var)->new_pos.z - (*var)->obj->pos.z)
    * (-1.0 / tanf((*var)->obj->size));
  return ;
}

void		norme_cylindre(t_var **var)
{
  (*var)->normal.x = (*var)->new_pos.x - (*var)->obj->pos.x;
  (*var)->normal.y = (*var)->new_pos.y - (*var)->obj->pos.y;
  (*var)->normal.z = 0;
  return ;
}

void		norme_para1(t_var **var)
{
  (*var)->normal.x = (*var)->new_pos.x - (*var)->obj->pos.x;
  (*var)->normal.y = (*var)->new_pos.y - (*var)->obj->pos.y;
  (*var)->normal.z = (*var)->obj->size;
  return ;
}
