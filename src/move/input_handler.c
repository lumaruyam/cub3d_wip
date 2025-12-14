/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:38:33 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/14 19:33:48 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w)
		data->player.move_y = 1;
	if (key == XK_a)
		data->player.move_x = -1;
	if (key == XK_s)
		data->player.move_y = -1;
	if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

static int	handle_key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		quit_cub3d(data);
	if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}
//Bonus part
// static void	wrap_mouse_position(t_data *data, int x, int y)
// {
// 	if (x > data->win_width - DIST_EDGE_MOUSE_WRAP)
// 	{
// 		x = DIST_EDGE_MOUSE_WRAP;

// 	}
// }

// static int	mouse_move_handler(int x, int y, t_data *data)
// {
// 	static int	old_x = WIN_WIDTH / 2;

// 	wrap_mouse_position(data, x, y);
// }

void	listen_for_input(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, quit_cub3d, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, handle_key_release, data);
	// if (BONUS)
	// 	mlx_hook(data->win, MotionNotify, PointerMotionMask,
	// 		mouse_move_handler, data);
}
