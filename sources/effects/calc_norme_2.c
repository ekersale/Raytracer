/*
** calc_norme_2.c for raytracer in /home/kersal_e//projets_actuels/raytracer-2017-porres_m/new_start/sources/effects
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Fri Jun  7 14:41:44 2013 elliot kersale
** Last update Fri Jun  7 15:00:14 2013 elliot kersale
*/

#include	"proto.h"

void		norme_para2(t_var **var)
{
  (*var)->normal.x = (*var)->new_pos.x;
  (*var)->normal.y = (*var)->new_pos.y;
  (*var)->normal.z = - (*var)->obj->size * (*var)->new_pos.z;
  return ;
}
