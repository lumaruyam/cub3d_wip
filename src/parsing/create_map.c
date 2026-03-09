/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niconguy <niconguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:59:08 by niconguy          #+#    #+#             */
/*   Updated: 2026/03/09 19:59:08 by niconguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_height(t_data *data, char **file, int i)
{
	int	start;
	int	j;

	start = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] && ft_strchr(" \t\r\v\f", file[i][j]))
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->mapinfo.index_end_of_map = i;
	return (i - start);
}

static int	extract_map_grid(t_mapinfo *mi, char **map, int idx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mi->height)
	{
		map[i] = malloc(sizeof(char) * (mi->width + 1));
		if (!map[i])
			return (err_msg(NULL, ERR_MALLOC, FAILURE));
		j = 0;
		while (mi->file[idx][j] && mi->file[idx][j] != '\n')
		{
			map[i][j] = mi->file[idx][j];
			j++;
		}
		while (j < mi->width)
			map[i][j++] = '\0';
		map[i][mi->width] = '\0';
		idx++;
	}
	map[i] = NULL;
	return (SUCCESS);
}

static int	allocate_map(t_data *data, char **file, int i)
{
	int	j;
	int	len;

	data->mapinfo.height = get_map_height(data, file, i);
	data->mapinfo.width = 0;
	j = i;
	while (j < i + data->mapinfo.height)
	{
		len = ft_strlen(file[j]);
		if (len > 0 && file[j][len - 1] == '\n')
			len--;
		if (len > data->mapinfo.width)
			data->mapinfo.width = len;
		j++;
	}
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (err_msg(NULL, ERR_MALLOC, FAILURE));
	return (extract_map_grid(&data->mapinfo, data->map, i));
}

int	create_map(t_data *data, char **file, int i)
{
	if (allocate_map(data, file, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
