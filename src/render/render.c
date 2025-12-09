/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:25:10 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/09 21:11:25 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_images(t_data *data)
{
	init_texture_pixels(data);//done
	init_ray(&data->ray);//done
	raycasting(&data->player, data);

}
