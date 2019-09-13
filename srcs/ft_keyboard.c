/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:00:41 by badhont           #+#    #+#             */
/*   Updated: 2019/03/07 02:31:59 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_input1(int key, t_data *data)
{
	if (key == 69)
	{
		data->x_min += (data->x_max - data->x_min) / (data->zoom_ratio);
		data->x_max -= (data->x_max - data->x_min) / (data->zoom_ratio);
		data->y_min += (data->y_max - data->y_min) / (data->zoom_ratio);
		data->y_max -= (data->y_max - data->y_min) / (data->zoom_ratio);
	}
	else if (key == 78)
	{
		data->x_min -= (data->x_max - data->x_min) / (data->zoom_ratio);
		data->x_max += (data->x_max - data->x_min) / (data->zoom_ratio);
		data->y_min -= (data->y_max - data->y_min) / (data->zoom_ratio);
		data->y_max += (data->y_max - data->y_min) / (data->zoom_ratio);
	}
	else if (key == 49)
		data->freeze = (data->freeze == 0) ? 1 : 0;
	else if (key >= 82 && key <= 89)
	{
		data->id_fractal = key - 82;
		ft_init_view(data);
	}
	if (key == 1)
		data->iter_ratio *= 2;
	else if (key == 0 && data->iter_ratio > 1)
		data->iter_ratio /= 2;
}

/*
** 69 +  78 -  49 SPACE  82......89 0......7  1 S  0 A
*/

void	ft_key_input2(int key, t_data *data)
{
	if (key == 6)
		data->zoom_ratio *= 1.5;
	else if (key == 7)
		data->zoom_ratio /= 1.5;
	else if (key == 123)
	{
		data->x_min -= 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
		data->x_max -= 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
	}
	else if (key == 124)
	{
		data->x_min += 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
		data->x_max += 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
	}
	else if (key == 125)
	{
		data->y_min += 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
		data->y_max += 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
	}
	else if (key == 126)
	{
		data->y_min -= 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
		data->y_max -= 25 / data->zoom / (data->zoom_ratio / INIT_RATIO);
	}
}

/*
** 6 Z  7 X  123 <  124 >  125 v  126 ^
*/

void	ft_key_input3(int key, t_data *data)
{
	if (key == 12)
		ft_init_view(data);
	else if (key == 13)
		data->iter_max = INIT_ITER;
	else if (key == 14)
		data->iter_max = 0;
	else if (key == 8)
		data->cancer = !data->cancer;
	else if (key == 34)
		data->infos = (data->infos == 3) ? 0 : data->infos + 1;
	else if (key == 4)
		data->help = (data->help) ? 0 : 1;
	else if (key == 38 && data->red < 255)
		data->red += 5;
	else if (key == 45 && data->red > 0)
		data->red -= 5;
	else if (key == 40 && data->green < 255)
		data->green += 5;
	else if (key == 46 && data->green > 0)
		data->green -= 5;
	else if (key == 37 && data->blue < 255)
		data->blue += 5;
	else if (key == 43 && data->blue > 0)
		data->blue -= 5;
}

/*
** 12 Q  13 W  8 C  34 I  4 H  38 J  45 N  40 K  46 M  37 L  43 ,
*/

int		ft_keyboard(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (key == 67 && data->iter_max >= 0)
		data->iter_max += data->iter_ratio;
	else if (key == 75 && data->iter_max >= 2 * data->iter_ratio)
		data->iter_max -= data->iter_ratio;
	ft_key_input1(key, data);
	ft_key_input2(key, data);
	ft_key_input3(key, data);
	ft_reframe(data);
	return (1);
}

/*
** 53 ESC  67 *  75 /s
*/
