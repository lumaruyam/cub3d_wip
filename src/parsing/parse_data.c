#include "cub3d.h"

static int	count_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	fill_file_array(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(data->mapinfo.fd);
	while (line)
	{
		data->mapinfo.file[i] = line;
		i++;
		line = get_next_line(data->mapinfo.fd);
	}
	data->mapinfo.file[i] = NULL;
}

void	parse_data(char *path, t_data *data)
{
	data->mapinfo.path = path;
	data->mapinfo.line_count = count_lines(path);
	if (data->mapinfo.line_count < 0)
	{
		err_msg(path, strerror(errno), FAILURE);
		return ;
	}
	data->mapinfo.file = ft_calloc(data->mapinfo.line_count + 1,
			sizeof(char *));
	if (!data->mapinfo.file)
	{
		err_msg(NULL, ERR_MALLOC, FAILURE);
		return ;
	}
	data->mapinfo.fd = open(path, O_RDONLY);
	if (data->mapinfo.fd < 0)
	{
		err_msg(path, strerror(errno), FAILURE);
		free(data->mapinfo.file);
		data->mapinfo.file = NULL;
		return ;
	}
	fill_file_array(data);
	close(data->mapinfo.fd);
}
