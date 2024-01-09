#include <stdlib.h>
#include "cub_macro.h"
#include "cub3d.h"
#include "ft_utils.h"

static int		prm_init(t_param *prm)
{
	t_parse		*parse_struct;

	prm->booleans = 0;
	prm->dlist = NULL;
	if (!(parse_struct = malloc(sizeof(t_parse))))
	{
		prm->ptr = NULL;
		return (0);
	}
	parse_struct->buff = NULL;
	parse_struct->id_strings = NULL;
	prm->ptr = parse_struct;
	return (1);
}

int				main(int argc, char **argv)
{
	t_param	prm;

	if (!(prm_init(&prm)))
		return (ft_exit(MAL_ERR_PARSE_STRUCT, &prm));
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
		{
			if (!(ft_strcmp(argv[2], SAVE_STR)))
				return (ft_exit(WRONG_SAVE_STR, &prm));
			prm.booleans += BMP_SAVE;
		}
		if (verify_extension(argv[1], CUB_EXT))
		{
			if (!(((t_parse*)(prm.ptr))->buff = ft_strdup(argv[1])))
				return (ft_exit(MAL_ERR_FILENAME, &prm));
			parse_trigger(&prm);
		}
		else
			return (ft_exit(WRONG_FILE_EXT, &prm));
	}
	else
		return (ft_exit(WRONG_ARG_NUM, &prm));
	return (0);
}
