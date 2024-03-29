#include <math.h>
#include "cub3d.h"
#include "cub_macro.h"
#include "cub_struct.h"
#include "ft_utils.h"

void	ft_forward(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_conf		*conf;

	conf = get_lst_elem(prm->dlist, ID_CONF)->content;
	player = get_lst_elem(prm->dlist, ID_PLAYER)->content;
	map = get_lst_elem(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x + player->dir.x * conf->front_speed) >= 0
			&& (int)(player->pos.x + player->dir.x * conf->front_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y + player->dir.y * conf->front_speed) >= 0
			&& (int)(player->pos.y + player->dir.y * conf->front_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
				[(int)(player->pos.x + player->dir.x * conf->front_speed)],
					MAP_OBSTACLE))
			player->pos.x += player->dir.x * conf->front_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
			+ player->dir.y * conf->front_speed)]
			[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y += player->dir.y * conf->front_speed;
	}
}

void	ft_backward(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_conf		*conf;

	conf = get_lst_elem(prm->dlist, ID_CONF)->content;
	player = get_lst_elem(prm->dlist, ID_PLAYER)->content;
	map = get_lst_elem(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x - player->dir.x * conf->back_speed) >= 0
			&& (int)(player->pos.x - player->dir.x * conf->back_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y - player->dir.y * conf->back_speed) >= 0
			&& (int)(player->pos.y - player->dir.y * conf->back_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
				[(int)(player->pos.x - player->dir.x * conf->back_speed)],
					MAP_OBSTACLE))
			player->pos.x -= player->dir.x * conf->back_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
								- player->dir.y * conf->back_speed)]
								[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y -= player->dir.y * conf->back_speed;
	}
}

void	ft_strafe_left(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_conf		*conf;

	conf = get_lst_elem(prm->dlist, ID_CONF)->content;
	player = get_lst_elem(prm->dlist, ID_PLAYER)->content;
	map = get_lst_elem(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x + player->dir.y * conf->strafe_speed) >= 0
			&& (int)(player->pos.x + player->dir.y * conf->strafe_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y - player->dir.x * conf->strafe_speed) >= 0
			&& (int)(player->pos.y - player->dir.x * conf->strafe_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
				[(int)(player->pos.x + player->dir.y * conf->strafe_speed)],
						MAP_OBSTACLE))
			player->pos.x += player->dir.y * conf->strafe_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
								- player->dir.x * conf->strafe_speed)]
								[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y -= player->dir.x * conf->strafe_speed;
	}
}

void	ft_strafe_right(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_conf		*conf;

	conf = get_lst_elem(prm->dlist, ID_CONF)->content;
	player = get_lst_elem(prm->dlist, ID_PLAYER)->content;
	map = get_lst_elem(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x - player->dir.y * conf->strafe_speed) >= 0
			&& (int)(player->pos.x - player->dir.y * conf->strafe_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y + player->dir.x * conf->strafe_speed) >= 0
			&& (int)(player->pos.y + player->dir.x * conf->strafe_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
				[(int)(player->pos.x
				- player->dir.y * conf->strafe_speed)], MAP_OBSTACLE))
			player->pos.x -= player->dir.y * conf->strafe_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y +
								player->dir.x * conf->strafe_speed)]
								[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y += player->dir.x * conf->strafe_speed;
	}
}
