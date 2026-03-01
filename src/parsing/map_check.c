/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:22:05 by lulmaruy          #+#    #+#             */
/*   Updated: 2026/01/19 17:01:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	space_into_wall(char **map) // 2
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((map[i][j] >= 9 && map[i][j] <= 13) || map[i][j] == 32)
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

// static int	map_sign(t_data *data, char **map) // 1
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	data->player.dir = '0';
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if (ft_strchr(" \t\r\v\f\n", map[i][j]))
// 				continue ;
// 			if (!ft_strchr("10NSEW", map[i][j]))
// 				return (err_msg(data->mapinfo.path, ERR_INV_LETTER, FAILURE));
// 			if (ft_strchr("NSEW", map[i][j]))
// 			{
// 				if (data->player.dir != '0')
// 					return (err_msg(data->mapinfo.path, ERR_NUM_PLAYER, FAILURE));
// 				data->player.dir = map[i][j];
// 				data->player.pos_x = j + 0.5;
// 				data->player.pos_y = i + 0.5;
// 			}
// 		}
// 	}
// 	return (SUCCESS);
// }

static int	map_sign(t_data *data, char **map) // 1
{
	int	i;
	int	j;

	i = -1;
	data->player.dir = '0';
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr(" \t\r\v\f\n", map[i][j]))
				continue ;
			if (!ft_strchr("10NSEW", map[i][j]))
				return (err_msg(data->mapinfo.path, ERR_INV_LETTER, FAILURE));
			if (ft_strchr("NSEW", map[i][j]))
			{
				if (data->player.dir != '0')
					return (err_msg(data->mapinfo.path, ERR_NUM_PLAYER, FAILURE));
				data->player.dir = map[i][j];
				data->player.pos_x = j + 0.5;
				data->player.pos_y = i + 0.5;
				map[i][j] = '0'; // ← ADD THIS LINE
			}
		}
	}
	return (SUCCESS);
}

static int	check_map(t_data *data, char **map) //3
{
	size_t	i; // changed from int because it's size_t (28/02/2026)
	size_t	j;

	if (data->player.dir == '0')
		return (err_msg(data->mapinfo.path, "Missing player", FAILURE));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || ft_strchr("NSEW", map[i][j]))
			{
				if (i == 0 || map[i + 1] == NULL || j == 0)
					return (err_msg(data->mapinfo.path, "Map not closed", FAILURE));
				if (is_void(map[i][j - 1]) || is_void(map[i][j + 1]) ||
					j >= (size_t)ft_strlen(map[i - 1]) || is_void(map[i - 1][j]) ||
					j >= (size_t)ft_strlen(map[i + 1]) || is_void(map[i + 1][j]))
					return (err_msg(data->mapinfo.path, "Map not closed", FAILURE));
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

// static int	check_map(t_data *data, char **map) //3
// {
// 	int	i;
// 	int	j;

// 	if (data->player.dir == '0')
// 		return (err_msg(data->mapinfo.path, "Missing player", FAILURE));
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '0' || ft_strchr("NSEW", map[i][j]))
// 			{
// 				if (i == 0 || map[i + 1] == NULL || j == 0)
// 					return (err_msg(data->mapinfo.path, "Map not closed", FAILURE));
// 				if (is_void(map[i][j - 1]) || is_void(map[i][j + 1]) ||
// 					(size_t)j >= ft_strlen(map[i - 1]) || is_void(map[i - 1][j]) ||
// 					(size_t)j >= ft_strlen(map[i + 1]) || is_void(map[i + 1][j]))
// 					return (err_msg(data->mapinfo.path, "Map not closed", FAILURE));
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	check_map_is_at_the_end(t_data *data) //4
{
	int	i;
	int	j;

	i = data->mapinfo.index_end_of_map;
	while (data->mapinfo.file[i])
	{
		j = 0;
		while (data->mapinfo.file[i][j])
		{
			if (!ft_strchr(" \t\r\v\f\n", data->mapinfo.file[i][j]))
				return (err_msg(data->mapinfo.path,
					"Unexpected data after map end", FAILURE));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int map_ok(t_data *data, char **map)
{
	if (!data->map)
		return(err_msg(data->mapinfo.path, ERR_NO_MAP, FAILURE));
	if (data->mapinfo.height < 3)
		return(err_msg(data->mapinfo.path, ERR_MAP_NO_WALLS, FAILURE));
	if (map_sign(data, map) == FAILURE)
		return(FAILURE);
	space_into_wall(map);
	if (check_map(data, map) == FAILURE)
		return(FAILURE);
	if (check_map_is_at_the_end(data) == FAILURE)
		return(FAILURE);
	return(SUCCESS);
}
