/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:14:52 by badhont           #+#    #+#             */
/*   Updated: 2019/03/07 01:22:56 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_data(t_data *data, int nbr, char *str, int row)
{
	char	*var;
	int		color;

	color = PINK - row * 100;
	if (!(var = (char*)ft_itoa(nbr)))
		ft_error_exit("Error : out of memory", data);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, row, color, str);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 130, row, color, var);
	free(var);
}

void	ft_put_help1(t_data *data)
{
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 270, PINK,
	" * /      + or - Iter_max");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 290, PINK,
	" + -      + or - Zoom");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 310, PINK,
	" SPACE    Freeze");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 330, PINK,
	" 0...7    Switch fractal");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 350, PINK,
	" Mouse    Change C parameter");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 370, PINK,
	" ARROWS   Movements");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 410, PINK,
	" S A      + or - Iter_ratio");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 430, PINK,
	" X Z      + or - zoom_ratio");
}

void	ft_put_help2(t_data *data)
{
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 450, PINK,
	" Q        Reset Zoom");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 470, PINK,
	" W        Reset Iter");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 490, PINK,
	" E        Put Iter to 0");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 530, PINK,
	" J N      + or - Cyan");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 550, PINK,
	" K M      + or - Magenta");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 570, PINK,
	" L ,      + or - Yellow");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 590, PINK,
	" C        Cancer Mode");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 630, PINK,
	" I        Show Settings");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 650, PINK,
	" ESC      Quit");
}

void	ft_put_settings(t_data *data)
{
	if (data->infos == 0 || data->infos == 1 || data->infos == 2)
	{
		mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 20, 15, PINK,
		"Please Press H");
		ft_put_data(data, data->iter_max, "Iter max", 35);
		ft_put_data(data, data->iter_ratio, "Iter ratio", 55);
		ft_put_data(data, 400 / data->zoom_ratio, "Zoom ratio", 75);
	}
	if (data->infos == 1 || data->infos == 2)
	{
		ft_put_data(data, data->mouse_x * 1000, "Cr*1000", 95);
		ft_put_data(data, data->mouse_y * 1000, "Ci*1000", 115);
		ft_put_data(data, data->fps, "FPS", 135);
	}
	if (data->infos == 2)
	{
		ft_put_data(data, data->red, "Cyan", 155);
		ft_put_data(data, data->green, "Magenta", 175);
		ft_put_data(data, data->blue, "Yellow", 195);
	}
	if (data->help == 1)
	{
		ft_put_help1(data);
		ft_put_help2(data);
	}
}
