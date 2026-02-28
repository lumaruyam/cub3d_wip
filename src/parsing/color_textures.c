#include "cub3d.h"

static bool	no_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	*copy_into_rgb_array(char **rgb_to_convert, int *rgb)
{
	int	i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit(rgb_to_convert[i]))
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

int	fill_color_textures(t_data *data, t_texinfo *textures, char *line, int j)
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
		return (err_msg(data->mapinfo.path, ERR_FLOOR_CEILING, ERR));
	return (SUCCESS);
}
