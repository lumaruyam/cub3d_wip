/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:28:10 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/14 19:24:45 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pizels);
	if (!data->texture_pixels)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = ft_calloc(data->win_width + 1,
			size3of * data->texture_pixels);
		if (!data->texture_pixcels[i])
			clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
		i++;
	}
}

static void	get_textutre_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->textinfo.index = WEST;
		else
			data->textinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texinfo.index = SOUTH;
		else
			data->texinfo.index = NORTH;
	}
}

void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x)
{
	int	y;
	int	color;

	get_texture_index(data, ray);
	//WIP 1214
}
