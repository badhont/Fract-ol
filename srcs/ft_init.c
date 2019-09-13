/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:24:19 by badhont           #+#    #+#             */
/*   Updated: 2019/03/06 23:16:29 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_exit(char *str, t_data *data)
{
	ft_putendl_fd(str, 2);
	if (data->mlx.mlx_ptr && data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	exit(EXIT_FAILURE);
}

void	ft_init_view(t_data *data)
{
	if (data->id_fractal == 0)
	{
		data->x_min = -2.1;
		data->x_max = 0.6;
		data->y_min = -1.35;
		data->y_max = 1.2;
	}
	else if (data->id_fractal == 1)
	{
		data->x_min = -2.1;
		data->x_max = 1.3;
		data->y_min = -2.1;
		data->y_max = -1.4;
	}
	else if (data->id_fractal == 2 || data->id_fractal == 3
	|| data->id_fractal == 4 || data->id_fractal == 5)
	{
		data->x_min = -1.6;
		data->x_max = 1.6;
		data->y_min = -1.6;
		data->y_max = 1.6;
	}
	data->zoom_ratio = INIT_RATIO;
	data->iter_ratio = 1;
}

void	ft_init(t_data *data)
{
	int	tmp;

	tmp = data->id_fractal;
	ft_bzero(data, sizeof(t_data));
	data->id_fractal = tmp;
	ft_init_view(data);
	if (!(data->mlx.mlx_ptr = mlx_init()))
		ft_error_exit("Error : can't init mlx", data);
	if (!(data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
		WIDTH, HEIGHT, "d*_*b")))
		ft_error_exit("Error : can't get the new window", data);
	if (!(data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT)))
		ft_error_exit("Error : can't get the new image", data);
	if (!(data->mlx.img_str = (int *)mlx_get_data_addr(data->mlx.img_ptr,
	&(data->mlx.bpp), &(data->mlx.s_l), &(data->mlx.endian))))
		ft_error_exit("Error : can't get the data address", data);
	data->iter_max = INIT_ITER;
	data->mouse_x = 0.3;
	data->mouse_y = 0.01;
	data->freeze = 1;
}
