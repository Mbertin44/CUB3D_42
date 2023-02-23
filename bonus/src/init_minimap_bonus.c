/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:39:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 15:05:38 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	reinit_minimap(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	if (data->minimap->on_screen == 1)
		load_minimap(data);
}

void	show_minimap(t_vault *data)
{
	if (data->minimap->on_screen == 1)
	{
		data->minimap->on_screen = 0;
		mlx_delete_image(data->mlx, data->minimap->minimap);
	}
	else
	{
		data->minimap->on_screen = 1;
		load_minimap(data);
		draw_player(data);
	}
}

void	load_minimap(t_vault *data)
{
	data->minimap->minimap = mlx_new_image(data->mlx,
			data->map->max_lenght * TILE, data->map->lines * TILE);
	if (data->minimap->on_screen == 1)
	{
		draw_minimap(data);
		draw_player(data);
	}
	mlx_image_to_window(data->mlx,
		data->minimap->minimap,
		(WIDTH / 2) - (data->map->max_lenght * TILE / 2),
		(HEIGHT / 2) - (data->map->lines * TILE / 2));
}

void	draw_minimap(t_vault *data)
{
	//background minimap
	minimap_background(data);
	data->minimap->x = 0;
	while (data->minimap->x < data->map->lines)
	{
		data->minimap->y = 0;
		while (data->minimap->y < data->map->max_lenght)
		{
			if (data->map->map[data->minimap->x][data->minimap->y] == '0')
				draw_tiles(data, data->minimap->x * TILE, data->minimap->y * TILE,
					0x6E99FFFF);
			else if (data->map->map[data->minimap->x][data->minimap->y] == '1')
				draw_tiles(data, data->minimap->x * TILE, data->minimap->y * TILE,
					0xFFFFFFFF);
			else if (data->map->map[data->minimap->x][data->minimap->y] == '2')
				draw_tiles(data, data->minimap->x * TILE, data->minimap->y * TILE,
					0x000000FF);
			else if (ft_char_isinset("NSEW", data->map->map[data->minimap->x]
					[data->minimap->y]) == TRUE)
				draw_tiles(data, data->minimap->x * TILE, data->minimap->y * TILE,
					0x6E99FFFF);
			data->minimap->y++;
		}
		data->minimap->x++;
	}
	//contours MINIMAP
	full_line_minimap_hor(data, 0, 0xFF00FFFF);
	full_line_minimap_ver(data, 0, 0xFF00FFFF);
	full_line_minimap_ver(data, data->map->max_lenght * TILE - 1, 0xFF00FFFF);
	full_line_minimap_hor(data, data->map->lines * TILE - 1, 0xFF00FFFF);
}

void	minimap_background(t_vault *data)
{
	int	i;

	i = 0;
	while (i < data->map->lines * TILE)
	{
		full_line_minimap_hor(data, i, DGRAY);
		i++;
	}
}


void	draw_tiles(t_vault *data,
			int screen_x, int screen_y, unsigned int color)
{
	int	rows;
	int	cols;
	int	end_x;
	int	end_y;

	rows = screen_y;
	end_x = screen_x + TILE - 1;
	end_y = screen_y + TILE - 1;
	while (rows < end_y)
	{
		cols = screen_x;
		while (cols < end_x)
		{
			mlx_put_pixel(data->minimap->minimap, rows, cols, color);
			cols++;
		}
		rows++;
	}
}

void	full_line_minimap_hor(t_vault *data, int screen_y, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->max_lenght * TILE;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, start, screen_y, color);
		start++;
	}
}

void	full_line_minimap_ver(t_vault *data, int screen_x, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->lines * TILE;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, screen_x, start, color);
		start++;
	}
}