/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:18 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/30 23:31:01 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	errors(t_vault *data)
{
	if (data->error_code == 0)
		return ;
	else if (data->error_code == 1)
		printf("%s\n%s\n", "Error", "Il n'y a pas de carte");
	else if (data->error_code == 2)
		printf("%s\n%s\n", "Error", "Carte trop petite");
	else if (data->error_code == 3)
		printf("%s\n%s\n", "Error", "Mauvais caractère");
	else if (data->error_code == 4)
		printf("%s\n%s\n", "Error", "Murs non valides (haut/bas)");
	else if (data->error_code == 5)
		printf("%s\n%s\n", "Error", "Murs non valides (gauche/droite)");
	else if (data->error_code == 6)
		printf("%s\n%s\n", "Error", "La carte n'est pas un rectangle parfait");
	else if (data->error_code == 7)
		printf("%s\n%s\n", "Error", "Probleme FD");
	else if (data->error_code == 8)
		printf("%s\n%s\n", "Error", "Mauvais nom de fichier carte");
	else if (data->error_code == 9)
		printf("%s\n%s\n", "Error", "Mauvais nombre d'arguments");
	else if (data->error_code == 10)
		printf("%s\n%s\n", "Error", "Carte incomplète (P, E, C manquant)");
	else if (data->error_code == 11)
		printf("%s\n%s\n", "Error", "Doublon (P)");
	else if (data->error_code == 12)
		printf("%s\n%s\n", "Error", "C'est un répertoire !");
	else if (data->error_code == 13)
		printf("%s\n%s\n", "Error", "Parametres non valides");
	else if (data->error_code == 14)
		printf("%s\n%s\n", "Error", "textures's path or color code invalid");
	else if (data->error_code == 15)
		printf("%s\n%s\n", "Error", "RGB color code invalid");
	free_map(data);
}

void	free_map(t_vault *data)
{
	int	x;

	if (data->error_code == 7 || data->error_code == 8 || data->error_code == 9
		|| data->error_code == 12)
		exit (0);
	x = 0;
	while (x < data->lines)
	{
		free (data->map[x]);
		x++;
	}
	exit (0);
}

void	destroy_and_free_level(t_vault *data)
{
	mlx_delete_image(data->mlx, data->lvl1->collect);
	mlx_delete_image(data->mlx, data->lvl1->corner_1);
	mlx_delete_image(data->mlx, data->lvl1->corner_2);
	mlx_delete_image(data->mlx, data->lvl1->corner_3);
	mlx_delete_image(data->mlx, data->lvl1->corner_4);
	mlx_delete_image(data->mlx, data->lvl1->exit);
	mlx_delete_image(data->mlx, data->lvl1->floor);
	mlx_delete_image(data->mlx, data->lvl1->pilar);
	mlx_delete_image(data->mlx, data->lvl1->start);
	mlx_delete_image(data->mlx, data->lvl1->wall_bottom);
	mlx_delete_image(data->mlx, data->lvl1->wall_left);
	mlx_delete_image(data->mlx, data->lvl1->wall_right);
	mlx_delete_image(data->mlx, data->lvl1->wall_top);
	free (data->lvl1);
}

void	destroy_and_free_player(t_vault *data)
{
	mlx_delete_image(data->mlx, data->player->p_right);
	mlx_delete_image(data->mlx, data->player->p_left);
	free (data->player);
}

void	free_all(t_vault *data)
{
	mlx_terminate(data->mlx);
	free_map(data);
	destroy_and_free_level(data);
	destroy_and_free_player(data);
}
