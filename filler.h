#ifndef FILLER_H
# define FILLER_H

# include <string.h>
# include "libft.h"
#include <fcntl.h>

typedef struct  s_board
{
	int     max_x;
	int     max_y;
	char    **map;
}               t_board;

typedef struct s_test
{
	int	place_y;
	int	place_x;
}				t_test;

typedef struct	s_piece
{
	int		p_x_max;
	int		p_y_max;
	char	**piece;
}				t_piece;

typedef struct	s_player
{
	int		pos_p1x;
	int		pos_p1y;
	int		found_p1;
	int		pos_p2x;
	int		pos_p2y;
	int		found_p2;
}				t_player;

void    ft_search(char **map, t_player *player, t_board *b);
char	**save_map(char **line, t_board *c);
char	**save_piece(char **line, t_piece *p);
void	place_piece(t_piece pi, t_board map, t_player c);
#endif
