
#include "filler.h"
//#include <fcntl.h>

void	ft_search(char **map, t_player *player, t_board *b)
{
	int			fd;
	int			x;
	int			y;

	y = 0;
	fd = open("text", O_WRONLY | O_APPEND);
	while (y < b->max_y)
	{
		x = 0;
		while (x < b->max_x)
		{
			if (b->map[y][x] == 'X')
			{
				player->pos_p1x = x;
				player->pos_p1y = y;
				player->found_p1 = 1;
				ft_putstr_fd("player 1 x: ",fd);
				ft_putstr_fd(ft_itoa(player->pos_p1x),fd);
				ft_putstr_fd(" player 1 y: ",fd);
				ft_putstr_fd(ft_itoa(player->pos_p1y),fd);	
			}
			else if (b->map[y][x] == 'O')
			{
				player->pos_p2x = x;
				player->pos_p2y = y;
				player->found_p2 = 1;
				ft_putstr_fd("player 2 x: ",fd);
				ft_putstr_fd(ft_itoa(player->pos_p2x),fd);
				ft_putstr_fd(" player 2 y: ",fd);
				ft_putstr_fd(ft_itoa(player->pos_p2y),fd);
			}
			x++;
		}
		y++;
	}
		close(fd);
}

/*	void	ft_build_quad(t_players pass)
	{
		t_board	trap;
		int		fd;

		fd = open("text", O_WRONLY | O_APPEND);
		trap.quad_x = pass.opx;
		trap.quad_y = pass.opy;
		while (trap.quad_x != pass.x1)
		{
			if ((pass.x1 - trap.quad_x) < 0)
				trap.quad_x--;
			else if ((pass.x1 - trap.quad_x) > 0)
				trap.quad_x++;
		}
		while (trap.quad_y != pass.y1)
		{
			if ((pass.y1 - trap.quad_y) < 0)
				trap.quad_y--;
			else if ((pass.y1 - trap.quad_y) > 0)
				trap.quad_y++;
		}
		ft_putstr_fd("Built\n", fd);
		ft_putnbr_fd(trap.quad_y, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(trap.quad_x, fd);
		ft_putchar_fd('\n', fd);
		close(fd);
	}*/
