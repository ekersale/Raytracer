/*
** main.c for ps list in /home/thomps_j//Local/push_swap/tab_ps/chained
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sun Jan  6 01:39:47 2013 julien thompson
** Last update Wed Jun  5 16:31:15 2013 elliot kersale
*/

#include        <stdlib.h>
#include	"proto.h"
#include        "xfunc.h"

t_obj		*put_obj_in_list(t_obj *list)
{
  t_obj		*new;
  t_obj		*tmp;

  new = xmalloc(sizeof(*new));
  new->next = NULL;
  if (list == NULL)
    {
      new->prev = NULL;
      return (new);
    }
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  return (list);
}

t_lig		*put_light_in_list(t_lig *list)
{
  t_lig		*new;
  t_lig		*tmp;

  new = xmalloc(sizeof(*new));
  new->next = NULL;
  if (list == NULL)
    {
      new->prev = NULL;
      return (new);
    }
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  return (list);
}
