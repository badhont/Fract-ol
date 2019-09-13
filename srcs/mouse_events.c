/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:56:20 by badhont           #+#    #+#             */
/*   Updated: 2019/03/06 21:48:51 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_scroll(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == 1)
		data->freeze = (data->freeze == 0) ? 1 : 0;
	else if (key == 4)
	{
		data->x_min -= (data->x_max - data->x_min) / (data->zoom_ratio);
		data->x_max += (data->x_max - data->x_min) / (data->zoom_ratio);
		data->y_min -= (data->y_max - data->y_min) / (data->zoom_ratio);
		data->y_max += (data->y_max - data->y_min) / (data->zoom_ratio);
	}
	else if (key == 5)
	{
		data->x_min += (data->x_max - data->x_min) / (data->zoom_ratio);
		data->x_max -= (data->x_max - data->x_min) / (data->zoom_ratio);
		data->y_min += (data->y_max - data->y_min) / (data->zoom_ratio);
		data->y_max -= (data->y_max - data->y_min) / (data->zoom_ratio);
	}
	return (1);
}

/*
** 4 scroll down (+)  5 scroll up (-)
*/

int		ft_mouse_move(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->freeze == 0)
	{
		data->mouse_x = (x - WIDTH / 2) / data->zoom;
		data->mouse_y = (y - HEIGHT / 2) / data->zoom;
	}
	ft_reframe(data);
	return (1);
}

int		ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	exit(EXIT_SUCCESS);
}

/*
**	data->cursor_x = ((data->x_max - data->x_min) * (x / WIDTH))
** - (data->x_max - data->x_min) / 2;
**	data->cursor_y = ((data->y_max - data->y_min) * (y / WIDTH))
** - (data->y_max - data->y_min) / 2;
*/
