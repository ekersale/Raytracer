/*
** show_data.c for rt in /home/hanrio_p//loc/src
** 
** Made by pierre-edouard hanrion
** Login   <hanrio_p@epitech.net>
** 
** Started on  Wed Jun  5 01:48:54 2013 pierre-edouard hanrion
** Last update Wed Jun  5 02:23:21 2013 pierre-edouard hanrion
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"parse.h"

void		show_data(t_data *data)
{
  write_line(1, '-', 64);
  printf("Winx = %d\tWiny = %d\n", data->winx, data->winy);
  write_line(1, '-', 64);
  show_vect(data->eye_pos);
  write_line(1, '-', 64);
  show_vect(data->eye_rot);
  write_line(1, '-', 64);
  show_obj(data->obj);
  write_line(1, '-', 64);
  show_lig(data->light);
}

void		show_vect(t_vect vec)
{
  printf("x = %g\n", vec.x);
  printf("y = %g\n", vec.y);
  printf("z = %g\n", vec.z);
}

void		show_col(t_col col)
{
  printf("red = %g\n", col.red);
  printf("green = %g\n", col.green);
  printf("blue = %g\n", col.blue);
}

void		show_obj(t_obj *obj)
{
  t_obj		*tmp;
  int		num;

  num = 1;
  tmp = obj;
  while (tmp != NULL)
    {
      printf("Obj n°%d\n", num);
      printf("type = %d\n", tmp->type);
      printf("size = %g\n", tmp->size);
      printf("pos\n");
      show_vect(tmp->pos);
      printf("rot\n");
      show_vect(tmp->rot);
      printf("col\n");
      show_col(tmp->col);
      printf("lum\n");
      show_col(tmp->lum);
      printf("reflec = %g\n", tmp->reflec);
      printf("transp = %g\n", tmp->transp);
      tmp = tmp->next;
      my_putchar('\n');
      num++;
    }
}

void		show_lig(t_lig *lig)
{
  t_lig		*tmp;
  int		num;

  num = 1;
  tmp = lig;
  while (tmp != NULL)
    {
      printf("Light n°%d\n", num);
      printf("pos\n");
      show_vect(tmp->pos);
      printf("lum\n");
      show_col(tmp->lum);
      tmp = tmp->next;
      my_putchar('\n');
      num++;
    }
}
