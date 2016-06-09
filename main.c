
#include "filler.h"

int main(int argc, char **argv)
{
	char	*lines;
	t_board	c;
	t_piece p;
	t_player t;
	int i = 0;
	int fd;
	t_test	result;

	fd = open("text", O_WRONLY | O_APPEND);
	while (ft_get_next_line(0, &lines) > 0)
	{
		if (ft_strcmp("Plateau", lines))
		{
			ft_get_next_line(0, &lines);
			c.map = save_map(&lines, &c);
		}
		if (ft_strcmp("Piece", lines))
			p.piece = save_piece(&lines, &p);
		ft_search(c.map, &t, &c);
		i++;
		
	}
	place_piece(p, c, t);
	close (fd);
}

