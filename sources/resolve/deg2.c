/*
** delta.c for RT in /home/porres_m//PROJETS/igraph/RT/obj
** 
** Made by martin porres
** Login   <porres_m@epitech.net>
** 
** Started on  Mon Apr  8 17:35:37 2013 martin porres
** Last update Sun Jun  9 14:02:56 2013 elliot kersale
*/

#include	<math.h>
#include	"proto.h"

float		delta(float a, float b, float c)
{
  float		k[2];
  float		delt;

  k[0] = -1.0;
  k[1] = -1.0;
  delt = b * b - 4 * a * c;
  if (delt < 0.0)
    return (-1);
  if (delt == 0)
    {
      k[0] = (- b / 2 * a);
      return (k[0]);
    }
  k[0] = (- b + sqrtf(delt)) / (2 * a);
  k[1] = (- b - sqrtf(delt)) / (2 * a);
  if (k[0] <= k[1] && k[0] >= 0.0)
    return (k[0]);
  if (k[1] >= 0.0)
    return (k[1]);
  return (-1.0);
}
