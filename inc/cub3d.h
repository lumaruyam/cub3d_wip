/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:57:54 by lulmaruy          #+#    #+#             */
/*   Updated: 2026/03/01 15:19:42 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>


/* ---------------------------------------------------------------------------*
								MACROS
 --------------------------------------------------------------------------- */

# ifndef DEBUG_MSG
# define DEBUG_MSG 0
# endif

# ifndef BONUS /*Uncomment here when we added bonus*/
# define BONUS 0
# endif

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

# define MOVESPEED 0.0125
# define ROTSPEED 0.015

/*Error Messages*/
# define ERR_USAGE "./cub3d <path/to/map.cub>"
# define ERR_MALLOC "Failed to allocate memory"
# define ERR_MLX_START "Failed to start mlx"
# define ERR_MLX_WIN "Failed to create mlx window"
# define ERR_MLX_IMG "Failed to create mlx image"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_FILE_NOT_CUB "File is not a .cub file"
# define ERR_FILE_NOT_XPM "File is not a .xpm file"
# define ERR_FLOOR_CEILING "Invalid floor/ceiling RGB color(s)"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_INVALID_MAP "Map description is either wrong or incomplete"
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_NO_MAP "Map does not exist"
# define ERR_MAP_NO_WALLS "has no walls"
# define ERR_TEX_RGB_VAL "Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_COLOR_MISSING "Missing color(s)"



enum	e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum	e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/* ---------------------------------------------------------------------------*
								COLORS
 --------------------------------------------------------------------------- */

 # define RESET	"\e[0m"
 # define RED	"\e[31m"

/* ---------------------------------------------------------------------------*
								STRUCTURES
 --------------------------------------------------------------------------- */

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct	s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

// typedef struct	s_texinfo
// {
// 	char			*north;
// 	char			*south;
// 	char			*west;
// 	char			*east;
// 	int				*floor;
// 	int				*ceiling;
// 	unsigned long	hex_floor;
// 	unsigned long	hex_ceiling;
// 	int				size;
// 	int				index;
// 	int				step;
// 	int				pos;
// 	int				x;
// 	int				y;
// }	t_texinfo;

typedef struct	s_minimap
{
	char	**map;
	t_img	*img;
	int		size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
}	t_minimap;

typedef struct	s_mapinfo
{
	int		fd;
	int		line_count;
	char	*path;
	char	**file;
	int		height;
	int		width;
	int		index_end_of_map;
}	t_mapinfo;

typedef struct	s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct	s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_data;

/* ---------------------------------------------------------------------------*
								FUNCTIONS
 --------------------------------------------------------------------------- */

/*init*/
void	init_data(t_data *data);
void	init_ray(t_ray *ray);
void	init_img_clean(t_img *img);

void	init_textures(t_data *data);
void	init_texinfo(t_texinfo *textures);

void	init_mlx(t_data *data);
void	init_texture_img(t_data *data, t_img *image, char *path);
void	init_img(t_data *data, t_img *image, int width, int height);

/*parsing*/
void	parse_data(char *path, t_data *data);
int		check_file(char *arg, bool cub);
int		valid_texture(t_data *data, t_texinfo *textures);
int		fil_data(t_data *data, char **map);
int		map_ok(t_data *data, char **map);
int		fill_color_textures(t_data *data, t_texinfo *textures, char *line, int j);
int		check_map_is_at_the_end(t_data *data);
void	space_into_wall(char **map);
int		is_void(char c);
int		valid_texture(t_data *data, t_texinfo *textures);
int		create_map(t_data *data, char **file, int i);

/*render*/
int		render(t_data *data);
void	render_images(t_data *data);
void	set_image_pixel(t_img *image, int x, int y, int color);

/*render/texture*/
void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x);
void	init_texture_pixels(t_data *data);

/*render/raycasting*/
int		raycasting(t_player *player, t_data *data);

/*move*/
int		validate_move(t_data *data, double new_x, double new_y);
void	init_player_direction(t_data *data);
int		move_player(t_data *data);
int		rotate_player(t_data *data, double rotdir);

/*input handler*/
void	listen_for_input(t_data *data);

/*exit*/
int		quit_cub3d(t_data *data);
void	clean_exit(t_data *data, int code);

/*free data*/
int		free_data(t_data *data);
void	free_tab(void **tab);

/*error*/
int		err_msg(char *detail, char *str, int code);
int		err_msg_val(int detail, char *str, int code);

/*utils*/
void	*ft_calloc(size_t ct, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
