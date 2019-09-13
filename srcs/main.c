/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <badhont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:55:44 by badhont           #+#    #+#             */
/*   Updated: 2019/03/14 22:29:33 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check_arg(t_data *data, char *arg, int ac)
{
	if (ac == 2)
	{
		if (ft_strequ(arg, "mandelbrot"))
			data->id_fractal = 0;
		else if (ft_strequ(arg, "burning_ship"))
			data->id_fractal = 1;
		else if (ft_strequ(arg, "julia"))
			data->id_fractal = 2;
		else if (ft_strequ(arg, "burning_julia"))
			data->id_fractal = 3;
		else if (ft_strequ(arg, "barroco"))
			data->id_fractal = 4;
		else if (ft_strequ(arg, "burning_gland"))
			data->id_fractal = 5;
		else if (ft_strequ(arg, "burning_a"))
			data->id_fractal = 6;
		else if (ft_strequ(arg, "batman"))
			data->id_fractal = 7;
		else
			ft_put_usage(data);
	}
	else
		ft_put_usage(data);
}

void	*ft_opt_frac(void *arg)
{
	t_thrd	*thrd;

	thrd = (t_thrd *)arg;
	thrd->data->zoom = WIDTH / (thrd->data->x_max - thrd->data->x_min);
	if (thrd->data->id_fractal == 0)
		ft_mandelbrot(thrd);
	else if (thrd->data->id_fractal == 1)
		ft_burning_ship(thrd);
	else if (thrd->data->id_fractal == 2)
		ft_julia(thrd);
	else if (thrd->data->id_fractal == 3)
		ft_burning_julia(thrd);
	else if (thrd->data->id_fractal == 4)
		ft_barroco(thrd);
	else if (thrd->data->id_fractal == 5)
		ft_burning_gland(thrd);
	else if (thrd->data->id_fractal == 6)
		ft_burning_a(thrd);
	else if (thrd->data->id_fractal == 7)
		ft_batman(thrd);
	pthread_exit(NULL);
}

void	ft_reframe(t_data *data)
{
	t_thrd	thrd[NB_THRD];
	clock_t	last;
	clock_t	diff;
	int		i;

	i = 0;
	last = clock();
	while (i < NB_THRD)
	{
		thrd[i].data = data;
		thrd[i].start = i;
		pthread_create(&(thrd[i].th), NULL, ft_opt_frac, (void *)&(thrd[i]));
		i++;
	}
	i = 0;
	while (i < NB_THRD)
	{
		pthread_join(thrd[i].th, NULL);
		i++;
	}
	mlx_put_image_to_window(data, data->mlx.win_ptr, data->mlx.img_ptr, 0, 0);
	diff = clock() / 10000 - last / 10000;
	data->fps = 1000 / diff;
	ft_put_settings(data);
}

void	ft_fractol_loop(t_data *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 0, ft_keyboard, data);
	mlx_hook(data->mlx.win_ptr, 4, 0, ft_mouse_scroll, data);
	mlx_hook(data->mlx.win_ptr, 6, 0, ft_mouse_move, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, ft_exit, data);
	ft_reframe(data);
	mlx_loop(data->mlx.mlx_ptr);
}

int		main(int ac, char **av)
{
	t_data	data;

	ft_check_arg(&data, av[1], ac);
	ft_init(&data);
	ft_fractol_loop(&data);
	return (0);
}
