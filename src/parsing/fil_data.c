#include "cub3d.h"

static char	*texture_path(char *line, int j)
{
	char	*path;
	int		len;
	int		i;

	while (line[j] == ' ' || line[j] == '\t')
		j++;
	len = 0;
	while (line[j + len] && line[j + len] != ' '
		&& line[j + len] != '\t' && line[j + len] != '\n')
		len++;
	path = malloc(sizeof(char) * (len + 1));
	if (!path)
		return (NULL);
	i = -1;
	while (++i < len)
		path[i] = line[j + i];
	path[i] = '\0';
	while (line[j + len] == ' ' || line[j + len] == '\t')
		len++;
	if (line[j + len] != '\0' && line[j + len] != '\n')
		return (free(path), NULL);
	return (path);
}

static int	texture(t_texinfo *textures, char *line, int j)
{
	if (line[j + 2] && line[j + 2] != ' ' && line[j + 2] != '\t')
		return (ERR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !textures->north)
		textures->north = texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !textures->south)
		textures->south = texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !textures->west)
		textures->west = texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !textures->east)
		textures->east = texture_path(line, j + 2);
	else
		return (ERR);
	return (SUCCESS);
}

static int	info_no_9_13(t_data *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (map[i][j] == '\0')
		return (CONTINUE);
	if (ft_isdigit(map[i][j]))
	{
		if (create_map(data, map, i) == FAILURE) // bonus part
			return (err_msg(data->mapinfo.path, ERR_INVALID_MAP, FAILURE));
		return (SUCCESS);
	}
	if (map[i][j + 1] && map[i][j + 1] != ' ' && map[i][j + 1] != '\t')
	{
		if (texture(&data->texinfo, map[i], j) == ERR)
			return (err_msg(data->mapinfo.path, ERR_TEX_INVALID, FAILURE));
		return (BREAK);
	}
	if (fill_color_textures(data, &data->texinfo, map[i], j) == ERR)
		return (FAILURE);
	return (BREAK);
}

int	fil_data(t_data *data, char **map)
{
	int	i;
	int	ret;

	i = 0;
	while (map[i])
	{
		ret = info_no_9_13(data, map, i, 0);
		if (ret == FAILURE)
			return (FAILURE);
		if (ret == SUCCESS)
			return (SUCCESS);
		i++;
	}
	return (SUCCESS);
}
