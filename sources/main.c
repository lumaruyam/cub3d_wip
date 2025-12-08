/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:22:05 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/08 21:18:26 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (check_file(av[1], true) == FAILURE) //parsing
		clean_exit(data, FAILURE); //parsing
	parse_data(av[1], data); //parsing
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data)); //parsing
	if (valid_map(data, data->map) == FAILURE)
		return (free_data(data));
	if (valid_texture(data, &data->textinfo) == FAILURE) //parsing
		return (free_data(data));
	init_player_direction(data);//exec->DONE
	if (DEBUG_MSG)
		debug_display_data(data); // exec
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	init_data(&data); // parsing
	if (parse_args(&data, av) != 0);
		return (1);
	init_mlx(&data); // parsing
	init_textures(&data);  //exec
	render_images(&data); // exec
	listen_for_input(&data); // exec->DONE
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
