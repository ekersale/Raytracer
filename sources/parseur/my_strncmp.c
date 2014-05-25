/*
** my_strncmp.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 19:15:27 2013 pierre-edouard hanrion
** Last update Wed Jun  5 15:56:36 2013 elliot kersale
*/

#include	"proto.h"

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;
  int		one;
  int		two;

  one = 0;
  i = 0;
  two = 0;
  while (i < n && s1[i] != 0 && s2[i] != 0)
    {
      one += s1[i];
      two += s2[i++];
    }
  return (one - two);
}
