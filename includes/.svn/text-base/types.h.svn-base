/*
** types.h for rt in /home/thomps_j//my_new_rt/source
** 
** Made by julien thompson
** Login   <thomps_j@epitech.net>
** 
** Started on  Sat Mar 16 01:38:12 2013 julien thompson
** Last update Fri Jun  7 21:02:38 2013 elliot kersale
*/

#ifndef		_TYPES_H__
# define       	_TYPES_H__

typedef	struct	s_vect
{
  float		x;
  float		y;
  float		z;
}		t_vect;

typedef	struct	s_col
{
  float		red;
  float		green;
  float		blue;
}		t_col;

typedef	struct	s_ray
{
  t_vect	init;
  t_vect	dir;
}		t_ray;

typedef	struct	s_mat
{
  t_col		color;
  float		reflec;
}		t_mat;

typedef	struct	s_lig
{
  float		lum;
  t_vect	pos;
  t_col		color;
  struct s_lig	*prev;
  struct s_lig	*next;
}		t_lig;

typedef	struct	s_obj
{
  int		type;
  t_vect	pos;
  t_vect	rot;
  float		size;
  float		height;
  t_col		color;
  t_col		lum;
  float		reflec;
  float		transp;
  struct s_obj	*prev;
  struct s_obj	*next;
}		t_obj;

typedef struct	s_data
{
  int		winx;
  int		winy;
  t_col		ambi;
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  int		bpp;
  int		endian;
  int		sizeline;
  char		*data;
  t_vect	eye_pos;
  t_vect	eye_rot;
  t_lig		*light;
  t_obj		*nobj;
  t_obj		*obj;
  float		coeff;
  int		x;
  int		y;
  float		angle;
}		t_data;

typedef struct s_var
{
  t_vect	new_pos;
  t_vect	normal;
  float		dist;
  t_obj		*obj;
  t_lig		*light;
}		t_var;

#endif
