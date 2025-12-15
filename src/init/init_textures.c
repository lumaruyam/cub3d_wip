/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:37:58 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/15 19:48:36 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_data, *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
		sizeof * buffer * data->textinfo.size * data->textinfo.size);
	if (buffer)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));;
	y = 0;
	while (y < data->textinfo.size)
	{
		x = 0;
		while (x < data->textinfo.size)
		{
			buffer[y * data->textinfo.size + x]
				= tmp.addr[y * data->textinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);//check here if there is leak
	if (!data->textures)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	data->textures[NORTH] = xpm_to_img(data, data->textinfo.north);
	data->textures[SOUTH] = xpm_to_img(data, data->textinfo.south);
	data->textures[EAST] = xpm_to_img(data, data->textinfo.east);
	data->textures[WEST] = xpm_to_img(data, data->textinfo.west);
}
