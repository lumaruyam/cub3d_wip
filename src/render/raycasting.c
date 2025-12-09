/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:11:41 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/09 22:15:29 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);//do we need while we do it at render.c
	ray->camera_x = 2 * x / (double)WIN_WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;//to be fix
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;//to be fix

}

int	raycasting(t_player *player, t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = data->ray;
	while (x < data->win_width)
	{
		init_raycasting(x, &ray, player)
	}
}
