#include <math.h>
#include "cub3d.h"
#include "cub_macro.h"
#include "cub_struct.h"
#include "ft_utils.h"

void	ft_rotate_right(t_param *prm)
{
	double		old_dir_x;
	t_player	*player;
	t_conf		*conf;

	conf = get_lst_elem(prm->dlist, ID_CONF)->content;
	player = get_lst_elem(prm->dlist, ID_PLAYER)->content;
	old_dir_x = player->dir.x;
	player->dir.x = (player->dir.x * cos(conf->rot_speed))
				- (player->dir.y * sin(conf->rot_speed));
	player->dir.y = (old_dir_x * sin(conf->rot_speed))
				+ (player->dir.y * cos(conf->rot_speed));
	player->plane.x = -player->dir.y * ((player->view_angle * M_PI) / 180.0);
	player->plane.y = player->dir.x * ((player->view_angle * M_PI) / 180.0);
}

void	ft_rotate_left(t_param *prm)
{
	double		old_dir_x;
	t_player	*player;
	t_conf		*conf;

	conf = get_lst_elem(prm->dlist, ID_CONF)->content;
	player = get_lst_elem(prm->dlist, ID_PLAYER)->content;
	old_dir_x = player->dir.x;
	player->dir.x = (player->dir.x * cos(-conf->rot_speed))
				- (player->dir.y * sin(-conf->rot_speed));
	player->dir.y = (old_dir_x * sin(-conf->rot_speed))
				+ (player->dir.y * cos(-conf->rot_speed));
	player->plane.x = -player->dir.y * ((player->view_angle * M_PI) / 180.0);
	player->plane.y = player->dir.x * ((player->view_angle * M_PI) / 180.0);
}
