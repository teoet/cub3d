#ifndef CUB3D_H
# define CUB3D_H

# include "cub_struct.h"

# ifdef Darwin
#  define SYS 	1

void			mlx_get_screen_size(void *mlx, int *w, int*h);
# endif

# ifdef Linux
#  define SYS	2
# endif

int				parse_trigger(t_param *prm);

int				parse_line(t_param *prm);

int				id_res_filler(t_param *prm, char **elem);
int				id_path_filler(t_param *prm, char **elem, int id);

int				id_hcc_filler(t_param *prm, char **elem, int id);

int				parse_map(t_param *prm);

int				control_map(t_param *prm);

int				game_struct_init(t_param *prm);

void			ray_init(int x, t_ray *ray, t_param *prm);
int				ray_caster(t_param *prm);

void			ray_hit_scan(t_ray *ray, t_param *prm);
void			ray_perspective(t_ray *ray, t_param *prm);
void			ray_texture(t_ray *ray, t_param *prm);

void			img_refresh(t_ray *ray, t_param *prm);
void			fill_buffer(t_ray *ray, t_param *prm);
void			fill_line(int x, t_ray *ray, t_param *prm);

void			sprite_calc_draw_val(t_sprite *ptr, t_param *prm);
void			sprite_projection(t_ray *ray, t_param *prm);
void			sprite_line_to_buff(t_sprite *ptr, t_ray *ray, t_param *prm);
void			ray_fill_line_sprite(int x, t_ray *ray, t_param *prm);

int				player_init(t_param *prm);

int				pic_calculate(t_param *prm);

void			pic_export(t_ray *ray, t_param *prm, t_screen *screen);

int				ft_key_press(int keycode, t_param *prm);
int				ft_key_release(int keycode, t_param *prm);
int				ft_move(t_param *prm);

void			ft_forward(t_param *prm);
void			ft_backward(t_param *prm);
void			ft_strafe_left(t_param *prm);
void			ft_strafe_right(t_param *prm);

void			ft_rotate_right(t_param *prm);
void			ft_rotate_left(t_param *prm);

int				ft_error(int err_code);

int				render_error(int err_code);

int				clean_parse(t_param *prm);
int				clean_render(t_param *prm);
int				ft_exit(int err_code, t_param *prm);
int				ui_cross_exit(t_param *prm);

#endif
