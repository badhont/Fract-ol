/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 20:36:46 by badhont           #+#    #+#             */
/*   Updated: 2019/03/05 21:45:07 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_cp_mandelbrot(t_thrd *thrd, t_cplx c, t_cplx z)
{
	double	sqi;
	double	sqr;
	int		i;

	sqi = z.i * z.i;
	sqr = z.r * z.r;
	i = 0;
	while (sqr + sqi < 4 && i < thrd->data->iter_max)
	{
		sqi = z.i * z.i;
		sqr = z.r * z.r;
		thrd->data->tmp = z.r;
		z.i = 2 * z.i * z.r + c.i;
		z.r = sqr - sqi + c.r;
		i++;
	}
	return (i);
}

void	ft_mandelbrot(t_thrd *thrd)
{
	t_cplx	c;
	t_cplx	z;
	int		y;
	int		x;
	int		i;

	y = thrd->start;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.r = x / thrd->data->zoom + thrd->data->x_min;
			z.i = y / thrd->data->zoom + thrd->data->y_min;
			c.r = x / thrd->data->zoom + thrd->data->x_min;
			c.i = y / thrd->data->zoom + thrd->data->y_min;
			i = ft_cp_mandelbrot(thrd, c, z);
			ft_put_pixel(thrd->data, x, y, ft_set_color(thrd->data, i));
			x++;
		}
		y += NB_THRD;
	}
}

int		ft_cp_burning_ship(t_thrd *thrd, t_cplx c, t_cplx z)
{
	double	sqi;
	double	sqr;
	int		i;

	sqi = z.i * z.i;
	sqr = z.r * z.r;
	i = 0;
	while (sqr + sqi < 4 && i < thrd->data->iter_max)
	{
		sqi = z.i * z.i;
		sqr = z.r * z.r;
		thrd->data->tmp = z.r;
		z.i = fabs(2 * z.i * z.r + c.i);
		z.r = fabs(sqr - sqi + c.r);
		i++;
	}
	return (i);
}

void	ft_burning_ship(t_thrd *thrd)
{
	t_cplx	c;
	t_cplx	z;
	int		y;
	int		x;
	int		i;

	y = thrd->start;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.r = fabs(x / thrd->data->zoom + thrd->data->x_min);
			z.i = fabs(y / thrd->data->zoom + thrd->data->y_min);
			c.r = x / thrd->data->zoom + thrd->data->x_min;
			c.i = y / thrd->data->zoom + thrd->data->y_min;
			i = ft_cp_burning_ship(thrd, c, z);
			ft_put_pixel(thrd->data, x, y, ft_set_color(thrd->data, i));
			x++;
		}
		y += NB_THRD;
	}
}
