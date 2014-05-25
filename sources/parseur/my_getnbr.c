/*
** my_getnbr.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Tue Jun  4 23:34:26 2013 pierre-edouard hanrion
** Last update Wed Jun  5 16:32:44 2013 elliot kersale
*/

#include	"proto.h"

int		my_getnbr(char *str)
{
  int		res;
  int		i;
  int		sign;

  sign = 0;
  res = 0;
  i = 0;
  if (str[i] == '-')
    {
      sign = 1;
      i++;
    }
  while (str[i] != 0)
    res = res * 10 + str[i++] - '0';
  if (sign == 1)
    res *= -1;
  return (res);
}
