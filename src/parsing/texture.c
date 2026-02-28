#include "cub3d.h"

static int	rgb_check(int *rgb)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg_val(rgb[i], ERR_TEX_RGB_VAL, FAILURE));
	}
	return (SUCCESS);
}

static unsigned long	convert_rgb_to_hex(int *rgb)
{
	return (((rgb[0] & 0xFF) << 16) // changed rgb_tab to rgb (28/02/2026)
		| ((rgb[1] & 0xFF) << 8)
		| (rgb[2] & 0xFF));
}

int	valid_texture(t_data *data, t_texinfo *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (err_msg(data->mapinfo.path, ERR_TEX_MISSING, FAILURE));
	if (!textures->floor || !textures->ceiling)
		return (err_msg(data->mapinfo.path, ERR_COLOR_MISSING, FAILURE));
	if (check_file(textures->north, false) == FAILURE
		|| check_file(textures->south, false) == FAILURE
		|| check_file(textures->west, false) == FAILURE
		|| check_file(textures->east, false) == FAILURE
		|| rgb_check(textures->floor) == FAILURE
		|| rgb_check(textures->ceiling) == FAILURE)
		return (FAILURE);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
	return (SUCCESS);
}

// int	valid_texture(t_data *data, t_texinfo *textures)
// {
// 	if (!textures->north || !textures->south || !textures->west
// 		|| !textures->east)
// 		return (err_msg(data->mapinfo.path, ERR_TEX_MISSING, FAILURE));
// 	if (!textures->floor || !textures->ceiling)
// 		return (err_msg(data->mapinfo.path, ERR_COLOR_MISSING, FAILURE));
// 	if (check_file(textures->north, false) == FAILURE
// 		|| check_file(textures->south, false) == FAILURE
// 		|| check_file(textures->west, false) == FAILURE
// 		|| check_file(textures->east, false) == FAILURE
// 		|| check_valid_rgb(textures->floor) == FAILURE
// 		|| check_valid_rgb(textures->ceiling) == FAILURE)
// 		return (FAILURE);
// 	textures->hex_floor = convert_rgb_to_hex(textures->floor);
// 	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
// 	return (SUCCESS);
// }
