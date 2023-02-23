/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:38:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 08:52:09 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_forward(t_vault *data)
{
	if (data->map->map[(int)(data->player->row + data->player->pdy
			* data->raycaster->mov_speed)][(int)(data->player->col)] != '1')
		data->player->row = data->player->row + data->player->pdy
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->player->row)][(int)(data->player->col
			+ data->player->pdx * data->raycaster->mov_speed)] != '1')
		data->player->col = data->player->col + data->player->pdx
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}

void	move_backward(t_vault *data)
{
	if (data->map->map[(int)(data->player->row - data->player->pdy
			* data->raycaster->mov_speed)][(int)(data->player->col)] != '1')
		data->player->row = data->player->row - data->player->pdy
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->player->row)][(int)(data->player->col
			- data->player->pdx * data->raycaster->mov_speed)] != '1')
		data->player->col = data->player->col - data->player->pdx
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}

void	move_left(t_vault *data)
{
	if (data->map->map[(int)(data->player->row - data->raycaster->plane_y
			* data->raycaster->mov_speed)][(int)(data->player->col)] != '1')
		data->player->row = data->player->row - data->raycaster->plane_y
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->player->row)][(int)(data->player->col
			- data->raycaster->plane_x * data->raycaster->mov_speed)] != '1')
		data->player->col = data->player->col - data->raycaster->plane_x
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}

void	move_right(t_vault *data)
{
	if (data->map->map[(int)(data->player->row + data->raycaster->plane_y
			* data->raycaster->mov_speed)][(int)(data->player->col)] != '1')
		data->player->row = data->player->row + data->raycaster->plane_y
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->player->row)][(int)(data->player->col
			+ data->raycaster->plane_x * data->raycaster->mov_speed)] != '1')
		data->player->col = data->player->col + data->raycaster->plane_x
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}
