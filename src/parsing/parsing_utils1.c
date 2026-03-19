/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niconguy <niconguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:59:34 by niconguy          #+#    #+#             */
/*   Updated: 2026/03/09 19:59:34 by niconguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wp(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\0' || c == '\n');
}

int	is_open(char **map, int i, int j, int height)
{
	if (i < 0 || i >= height || !map[i])
		return (1);
	if (j < 0 || j >= (int)ft_strlen(map[i]))
		return (1);
	if (map[i][j] == '1')
		return (0);
	if (map[i][j] == '0')
		return (0);
	return (1);
}
