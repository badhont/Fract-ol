/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gland.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:36:21 by badhont           #+#    #+#             */
/*   Updated: 2019/03/06 23:24:50 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_cp_barroco(t_thrd *thrd, t_cplx c, t_cplx z)
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
		z.i = -(2 * z.i * z.r + c.i);
		z.r = fabs(sqi - sqr + c.r);
		i++;
	}
	return (i);
}

void	ft_barroco(t_thrd *thrd)
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
			z.r = (x / thrd->data->zoom + thrd->data->x_min);
			z.i = fabs(y / thrd->data->zoom + thrd->data->y_min);
			c.r = thrd->data->mouse_x;
			c.i = thrd->data->mouse_y;
			i = ft_cp_barroco(thrd, c, z);
			ft_put_pixel(thrd->data, x, y, ft_set_color(thrd->data, i));
			x++;
		}
		y += NB_THRD;
	}
}

/*
*************         *****************           **********
*/

int		ft_cp_burning_gland(t_thrd *thrd, t_cplx c, t_cplx z)
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
		z.i = fabs(3 * z.i * z.r + c.i);
		z.r = fabs(sqr - sqi + c.r);
		i++;
	}
	return (i);
}

void	ft_burning_gland(t_thrd *thrd)
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
			z.r = (x / thrd->data->zoom + thrd->data->x_min);
			z.i = (y / thrd->data->zoom + thrd->data->y_min);
			c.r = thrd->data->mouse_x;
			c.i = thrd->data->mouse_y;
			i = ft_cp_burning_gland(thrd, c, z);
			ft_put_pixel(thrd->data, x, y, ft_set_color(thrd->data, i));
			x++;
		}
		y += NB_THRD;
	}
}
