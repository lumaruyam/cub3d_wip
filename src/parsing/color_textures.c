/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niconguy <niconguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:01:47 by niconguy          #+#    #+#             */
/*   Updated: 2026/03/09 20:01:47 by niconguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	invalid_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '\t' && str[i] != '\n')
			return (true);
		i++;
	}
	return (false);
}

static int	get_value(char *str)
{
	char	clean[32];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && j < 31)
	{
		if (ft_isdigit(str[i]))
			clean[j++] = str[i];
		i++;
	}
	clean[j] = '\0';
	return (ft_atoi(clean));
}

static int	*copy_into_rgb_array(char **rgb_to_convert, int *rgb)
{
	int	i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		if (invalid_number(rgb_to_convert[i]))
			return (free_tab((void **)rgb_to_convert), free(rgb), NULL);
		rgb[i] = get_value(rgb_to_convert[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (free_tab((void **)rgb_to_convert), free(rgb), NULL);
	}
	free_tab((void **)rgb_to_convert);
	return (rgb);
}

static int	*set_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	if (!rgb_to_convert)
		return (NULL);
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
		return (free_tab((void **)rgb_to_convert), NULL);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		err_msg(NULL, ERR_MALLOC, 0);
		return (free_tab((void **)rgb_to_convert), NULL);
	}
	return (copy_into_rgb_array(rgb_to_convert, rgb));
}

int	fill_color_tex(t_data *data, t_texinfo *textures, char *line, int j)
{
	if (line[j + 1] && line[j + 1] != ' ' && line[j + 1] != '\t')
		return (err_msg(data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	if (line[j] == 'C' && !textures->ceiling)
	{
		textures->ceiling = set_rgb_colors(line + j + 1);
		if (!textures->ceiling)
			return (err_msg(data->mapinfo.path, ERR_COLOR_CEILING, ERR));
	}
	else if (line[j] == 'F' && !textures->floor)
	{
		textures->floor = set_rgb_colors(line + j + 1);
		if (!textures->floor)
			return (err_msg(data->mapinfo.path, ERR_COLOR_FLOOR, ERR));
	}
	else
		return (err_msg(data->mapinfo.path, "Duplicate F/C identifier", ERR));
	return (SUCCESS);
}
