#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "cub_struct.h"

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_isset(char c, const char *set);
int				ft_strcmp(char *s1, char *s2);

char			*ft_strdup(const char *s1);
int				ft_atoi_base(char *str, char *set);
int				verify_extension(char *file_name, char *ext);
int				ft_contains_notset(char *str, char *set);

t_list			*get_lst_elem(t_list *alst, int type);
t_list			*ft_lstnew(int type, void *content);
void			ft_lstadd_back(t_list **alst, t_list *new);

void			ft_lst_delone(t_list **lst, t_list *one);
void			ft_lstclear_content(t_list *lst);
void			ft_dlist_clear(t_list **lst);

int				get_pixel_color(int x, int y, t_data *img);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
t_data			my_mlx_new_image(void *mlx, int width, int height);
int				my_mlx_destroy_tx(void *mlx, t_list *elem);
int				my_mlx_tx_from_path(void *mlx, t_list *elem);

t_sprite		*ft_new_sprite(int x, int y);
void			ft_add_sprite_front(t_sprite **alst, t_sprite *new);
void			ft_sprite_switch(t_sprite *ptr);
void			ft_clear_list(t_sprite **lst);

char			**ft_split(char const *s, char *set);

char			*ft_strtrim(char const *s1, char const *set);

int				rec_gnl(int fd, char **line);

#endif
