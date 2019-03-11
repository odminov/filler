/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:24:46 by ahonchar          #+#    #+#             */
/*   Updated: 2019/03/10 20:24:48 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

void	create_map(char *size, t_board *board)
{
	char	rows[10];
	char	cols[10];
	int		i;

	size += 8;
	i = 0;
	while (ft_isdigit(*size))
		rows[i++] = *size++;
	size++;
	if (!i)
		return ;
	i = 0;
	while (ft_isdigit(*size))
		cols[i++] = *size++;
	board->rows = ft_atoi(rows);
	if (!(board->map = (char **)malloc(sizeof(char *) * (board->rows <= 0 ? -1 : board->rows + 1))))
		return ;
	board->cols = ft_atoi(cols);
	i = 0;
	while (i <= board->rows)
	{
		if (!(board->map[i++] = (char *)malloc(board->cols <= 0 ? -1 : board->cols + 1)))
			return ;
	}
	board->map[i] = NULL;
}

int		main(void)
{
	char	*buf;
	t_board	*board;
	int fd;
	int i;

	buf = NULL;
	fd = open("./src/input", O_RDONLY);
	if (get_next_line(fd, &buf) >= 0)
		printf("%s", buf);
	if (!buf)
		return(0);
	if (ft_strncmp("Plateau", buf, 7))
		return (0);
	board = (t_board *)malloc(sizeof(t_board));
	create_map(buf, board);
	if (fd < 0)
		exit(1);
	i = 0;
	while (board->map[i])
		ft_putendl_fd(board->map[i++], 1);
	close(fd);
	return (0);
}
