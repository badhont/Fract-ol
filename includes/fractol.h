/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:52:53 by badhont           #+#    #+#             */
/*   Updated: 2019/03/14 22:55:07 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# include <time.h>

# define PINK       0xFD2BE6
# define WIDTH		1000
# define HEIGHT		1000
# define NB_THRD	8
# define INIT_ITER	50
# define INIT_RATIO 40

typedef struct s_data	t_data;
typedef struct s_mlx	t_mlx;
typedef struct s_cplx	t_cplx;
typedef struct s_thrd	t_thrd;

struct					s_cplx
{
	double	r;
	double	i;
};

struct					s_thrd
{
	pthread_t	th;
	t_data		*data;
	int			start;
};

struct					s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_str;
	int		bpp;
	int		s_l;
	int		endian;
};

struct					s_data
{
	t_mlx		mlx;
	int			id_fractal;
	int			iter_max;
	int			iter_ratio;
	int			fps;
	double		tmp;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		mouse_x;
	double		mouse_y;
	double		zoom;
	double		zoom_ratio;
	int			freeze;
	int			cancer;
	int			infos;
	int			help;
	int			red;
	int			green;
	int			blue;
};

void					ft_error_exit(char *str, t_data *data);
void					ft_init_view(t_data *data);
void					ft_init(t_data *data);
void					ft_mandelbrot(t_thrd *thrd);
void					ft_burning_ship(t_thrd *thrd);
void					ft_julia(t_thrd *thrd);
void					ft_burning_julia(t_thrd *thrd);
void					ft_gland(t_thrd *thrd);
void					ft_burning_gland(t_thrd *thrd);
void					ft_barroco(t_thrd *thrd);
void					ft_burning_a(t_thrd *thrd);
void					ft_batman(t_thrd *thrd);
void					ft_aztec(t_thrd *thrd);
int						ft_keyboard(int key, t_data *data);
int						ft_mouse_move(int x, int y, t_data *data);
int						ft_mouse_scroll(int key, int x, int y, t_data *data);
int						ft_exit(t_data *data);
void					ft_put_settings(t_data *data);
void					ft_reframe(t_data *data);
void					ft_put_pixel(t_data *data, int x, int y, int color);
int						ft_set_color(t_data *data, int i);
void					ft_put_usage(t_data *data);

#endif
