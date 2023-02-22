/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:30 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 10:04:16 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void load_3d(t_vault *data)
{
	data->raycaster->height_3d = HEIGHT - data->hud->hud_height - 1;
	data->game->ddd = mlx_new_image(data->mlx, WIDTH, data->raycaster->height_3d);
	mlx_image_to_window(data->mlx, data->game->ddd, 0, 0);
}
