/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:43:28 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/28 18:48:18 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_textinfo(t_textinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (trextures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (terxtures->ceiling)
		free(textures->ceiling);
}

static void	free_map(t_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd)
	if (data->mapinfo.file)
		free_tab((void **)data->mapinfo.file);
	if (data->map)
		free_tab((void **)data->map);
}

int	free_data(t_data *data)
{
	if (data->textures)
		free_tab((void **)data->textures);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	free_textinfo(&data->texinfo);
	free_map(data);
	return (FAILURE);
}
