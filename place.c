#include "filler.h"

void	place_piece(t_piece pi, t_board map, t_player c)
{
	int		y_count;
	int		x_count;
	char	**star;
	int		star_y;
	int		star_x;
	int		loop;
	char	**coord;
	t_test	result;
	int		fd = open("text", O_WRONLY | O_APPEND);

	coord = 0;
	star = 0;
	star_x = 0;
	star_y = 0;
	y_count = 0;
	x_count = 0;
	loop = 0;
	result.place_x = 0;
	result.place_y = 0;
	while (y_count < pi.p_y_max)
	{

		while (x_count < pi.p_x_max)
		{
			ft_putstr_fd("Entered", fd);
			if (loop == 0 && pi.piece[y_count][x_count] == '*')
			{
				loop = 1;
				star_y = y_count;
				star_x = x_count;
			}
			x_count++;
		}
		y_count++;
	}
	ft_putstr_fd("exit", fd);
	result.place_x = c.pos_p1x - star_x;
	result.place_y = c.pos_p1y - star_y;
	ft_putnbr(result.place_y);
	ft_putchar(' ');
	ft_putnbr(result.place_x);
	ft_putchar('\n');
}
