#include "cub3d.h"

static bool	cub_name(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len < 4)
		return (false);
	return (arg[len - 4] == '.'
		&& arg[len - 3] == 'c'
		&& arg[len - 2] == 'u'
		&& arg[len - 1] == 'b');
}

static bool	xpm_name(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len < 4)
		return (false);
	return (arg[len - 4] == '.'
		&& arg[len - 3] == 'x'
		&& arg[len - 2] == 'p'
		&& arg[len - 1] == 'm');
}

static bool	dir_check(char *arg)
{
	int	fd;

	fd = open(arg, O_DIRECTORY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

int	check_file(char *arg, bool cub)
{
	int		fd;
	bool	ok;

	if (dir_check(arg))
		return (err_msg(arg, ERR_FILE_IS_DIR, FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub)
		ok = cub_name(arg);
	else
		ok = xpm_name(arg);
	if (ok == false)
	{
		if (cub)
			return (err_msg(arg, ERR_FILE_NOT_CUB, FAILURE));
		else
			return (err_msg(arg, ERR_FILE_NOT_XPM, FAILURE));
	}
	return (SUCCESS);
}
