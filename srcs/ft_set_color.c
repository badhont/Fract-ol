/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:18:29 by badhont           #+#    #+#             */
/*   Updated: 2019/01/09 19:58:53 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	data->mlx.img_str[x + y * WIDTH] = color;
}

int		ft_set_color(t_data *data, int i)
{
	int	color;

	if (i == data->iter_max)
		return (0);
	if (data->cancer == 0)
	{
		color = (int)((i * (255 - data->blue)) / data->iter_max);
		color += (int)(((i * (255 - data->green)) / data->iter_max) << 8);
		color += (int)(((i * (255 - data->red)) / data->iter_max) << 16);
	}
	else
		color = i * ((1 << 24) - 1) / data->iter_max;
	return (color);
}

/*
**	main
**		ft_check_arg
**			.ft_strequ
**			/ft_error_exit
**				.ft_put_endl_fd
**				..ft_exit
**		ft_init
**			.ft_bzero
**			ft_init_view
**			..mlx_init
**			..mlx_new_window
**			..mlx_new_image
**			..mlx_get_data_addr
**			/ft_error_exit
**		ft_fractol_loop
**			..mlx_hook
**			ft_keyboard
**
**			ft_mouse_scroll
**
**			ft_mouse_move
**
**			ft_exit
**
**			ft_reframe
**				..clock
**				..pthread_create
**				ft_opt_frac
**					ft_mandelbrot
**						ft_calc_mandelbrot
**							ft_calc_mandelbrot
**							ft_set_color
**							ft_put_pixel
**						..pthread_exit
**					ft_julia
**						ft_calc_julia
**							ft_calc_julia
**							ft_set_color
**							ft_put_pixel
**						..pthread_exit
**				..pthread_join
**				..mlx_put_image_to_window
**				ft_put_settings
**					..mlx_string_put
**					ft_put_data
**						.ft_itoa
**						/ft_error_exit
**						..mlx_string_put
**						..free
**					ft_put_help1
**						..mlx_string_put
**					ft_put_help2
**						..mlx_string_put
**			..mlx_loop
*/
