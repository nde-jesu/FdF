/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 08:51:05 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/21 09:08:44 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1250
# define WIDTH 2500
# define MENU_WIDTH 250
# define COLOR_GAMERS_BLUE 0x4B0082
# define COLOR_ZINZOLIN 0x6C0277
# define COLOR_CHARTREUSE 0xDFFF00
# define COLOR_STOMACH_OF_HIND 0xE9C9B1
# define COLOR_THIGH_OF_NYMPH 0xFEE7F0

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_pt_lst
{
	t_point			pt;
	struct s_pt_lst	*next;
}				t_pt_lst;

typedef struct	s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_img		*img;
}				t_mlx;

typedef struct	s_cam
{
	int		proj;
	int		zoom;
	int		x_offset;
	int		y_offset;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_divisor;
}				t_cam;

typedef struct	s_mouse
{
	int		pressed;
	int		act_x;
	int		act_y;
	int		prev_x;
	int		prev_y;
}				t_mouse;

typedef struct	s_fdf
{
	t_mlx		*mlx;
	t_cam		*cam;
	t_pt_lst	*start;
	t_mouse		mouse;
	int			x_max;
	int			y_max;
	int			z_min;
	int			z_max;
}				t_fdf;

t_point			init_point(int x, int y, int z);
void			print_line_img(t_point a, t_point b, t_fdf *fdf);
void			ad_pt(t_pt_lst **start, int x, int y, int z);
t_pt_lst		*give_pos(int fd, t_fdf *fdf);
t_fdf			*init_fdf(void);
int				ft_min(int a, int b);
t_point			transform_pt(t_point pt, t_fdf *fdf);
void			print_2d(t_pt_lst *lst, t_fdf *fdf);
void			zoom(int key, t_fdf *fdf);
void			translation(int key, t_fdf *fdf);
void			rotation(int key, t_fdf *fdf);
void			projection(int key, t_fdf *fdf);
int				user_command(int key, void *param);
void			print_menu(t_fdf *fdf);
void			free_all(t_fdf *fdf);
void			get_ctrl(t_fdf *fdf);
int				press(int click, int x, int y, void *param);
int				release(int click, int x, int y, void *param);
int				move(int x, int y, void *param);
void			change_z(int key, t_fdf *fdf);
t_fdf			*new_img(t_fdf *fdf);
int				get_fst_clr(int min, int max, int z);
int				get_clr(t_point cur, t_point a, t_point b, t_point delta);

#endif
