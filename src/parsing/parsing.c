#include "../cub3d.h"

int	cw(char *s)
{
	int	i;
	int	r;

	r = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '1')
			r++;
	}
	if (!r)
		return (ft_error("cub3d", "no walls", 0, s));
	if ((long)r >= (long)(N_WALLS / 4) || (long)N_WALLS > (long)2147483647)
		return (ft_error("cub3d", "too many walls for define", 0, s));
	return (r * 4);
}

char	**fill_blank(t_map *map, char *file)
{
	int		i;
	int		j;
	char	**split;
	char	end[100000];
	char	*tmp;

	split = ft_split(file, "\n");
	i = -1;
	while (split && split[++i])
	{
		if (is_empty(split[i]))
			split = ft_remove_from_strarr(split, i);
		else if (ft_strlen(split[i]) < map->m_x)
		{
			j = -1;
			while (++j < map->m_x - ft_strlen(split[i]))
				end[j] = '0';
			end[j] = 0;
			tmp = ft_strjoin(split[i], end);
			free(split[i]);
			split[i] = tmp;
		}
	}
	i = -1;
	return (split);
}

static int	check_extension(char *config)
{
	if (ft_strlen(config) > 4)
		if (ft_strncmp(config + ft_strlen(config) - 4, ".cub", 4))
			return (1);
	return (0);
}

int	parse_input(t_mlx *env, char *config)
{
	char	*file;
	char	*line;
	char	*tmp;
	int		fd;

	if (check_extension(config))
		return (ft_error("cub3d", "invalid config file extension", -1, NULL));
	fd = open(config, O_RDONLY);
	if (fd < 0 || get_textures_colors(env, fd, 0)
		|| env->map->floor < 0 || env->map->ceil < 0)
		return (ft_error("cub3d", "invalid config file", -1, NULL));
	if (env->map->tex_error)
		return (ft_error("cub3d", "textures couldn't be loaded", -1, NULL));
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(file, line);
		free(file);
		file = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (get_map(env->map, file));
}
