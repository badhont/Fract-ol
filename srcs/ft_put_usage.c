/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badhont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:28:23 by badhont           #+#    #+#             */
/*   Updated: 2019/03/14 22:29:27 by badhont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_usage(t_data *data)
{
	ft_putendl("Usage: fractol [fractal name]");
	ft_putendl("> mandelbrot\n> burning_ship\n> julia\n> burning_julia");
	ft_error_exit("> barroco\n> burning_gland\n> burning_a\n> batman", data);
}
