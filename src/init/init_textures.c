/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:37:58 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/14 19:48:49 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);//check here if there is leak
	if (!data->textures)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	// WIP 1214
}
