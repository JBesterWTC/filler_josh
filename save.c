
#include "filler.h"

char    **save_map(char **line, t_board *c)
{
	char    **mapline;
	int     i;
	int     fd;
	char    **map;

	i = 0;
	fd = open("text", O_WRONLY | O_APPEND);
	mapline = ft_strsplit(*line, ' '); // mapline[0] = plateau
	c->max_y = ft_atoi(mapline[1]);         //       [1] = y value
	c->max_x = ft_atoi(mapline[2]);         //       [2] = x value
	ft_putstr_fd("x co ord: ", fd);
	ft_putstr_fd(ft_itoa(c->max_x), fd);
	ft_putstr_fd(" y co ord: ", fd);
	ft_putstr_fd(ft_itoa(c->max_y), fd);
	map = (char **)malloc(c->max_y * sizeof(char *));
	free(*line);                        // done with that line
	ft_get_next_line(0, line);             // next line is useless
	free(*line);
	free(mapline);
	while (i < c->max_y)                    // grid is left
	{
		ft_get_next_line(0, line);
		map[i] = ft_strdup(*line + 4); // + 4 get rid of side values
		ft_putstr_fd(map[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
		free(*line);
	}
	close(fd);
	ft_get_next_line(0, line);
	return (map);
}

char        **save_piece(char **line, t_piece *p)
{
	char    **pieceline;
	char    **piece;
	int     i = 0;
	int     fd;

	fd = open("text", O_WRONLY | O_APPEND);
	piece = ft_strsplit(*line, ' ');
	p->p_y_max = ft_atoi(piece[1]);
	p->p_x_max = ft_atoi(piece[2]);
	piece = (char **)malloc(p->p_y_max * sizeof(char *));
	ft_putstr_fd("piece y: ", fd);
	ft_putstr_fd(ft_itoa(p->p_y_max), fd);
	ft_putstr_fd(" piece x: ", fd);
	ft_putstr_fd(ft_itoa(p->p_x_max), fd);
	ft_putchar_fd('\n', fd);
	while (i < p->p_y_max)
	{
		ft_get_next_line(0, line);
		piece[i] = ft_strdup(*line);
		ft_putstr_fd(*line, fd);
		ft_putchar_fd('\n', fd);
		i++;
		free(*line);
	}
	close(fd);
	return (piece);
}
