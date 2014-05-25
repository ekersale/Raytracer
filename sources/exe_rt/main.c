/*
** main.c for raytracer in /home/kersal_e//projets_actuels/raytracer-2017-porres_m/new_start/sources
** 
** Made by elliot kersale
** Login   <kersal_e@epitech.net>
** 
** Started on  Thu May 30 14:55:21 2013 elliot kersale
** Last update Wed Jun  5 10:17:20 2013 elliot kersale
*/

#include	<unistd.h>
#include	"proto.h"

int		main(int ac, char **av)
{
  if (ac != 2)
    {
      write(1, "Usage: ./raytracer file\n", 25);
      return (-1);
    }
  else
    initialisation(av[1]);
  return (0);
}
