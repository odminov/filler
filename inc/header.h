/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:30:01 by ahonchar          #+#    #+#             */
/*   Updated: 2019/03/10 20:30:05 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct	s_board
{
	char		**map;
	char		**piece;
	int			cols;
	int			rows;
}				t_board;

#endif
