#include <stdlib.h>
#include "cub3d.h"

t_sprite	*ft_new_sprite(int x, int y)
{
	t_sprite *new;

	if (!(new = malloc(sizeof(t_sprite))))
		return (NULL);
	new->pos.x = (double)x;
	new->pos.y = (double)y;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_add_sprite_front(t_sprite **alst, t_sprite *new)
{
	if (new == NULL || alst == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		(*alst)->next = NULL;
		(*alst)->prev = NULL;
	}
	else
	{
		new->next = *alst;
		new->prev = NULL;
		(*alst)->prev = new;
		(*alst) = new;
	}
}

void		ft_clear_list(t_sprite **lst)
{
	t_sprite *ptr;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
