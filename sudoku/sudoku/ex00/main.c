/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 23:27:16 by mhuerta           #+#    #+#             */
/*   Updated: 2018/11/04 23:38:55 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char *argv[])
{
	char	grid[9][9];
	int i;

	if (argc != 10)
	{
		print("Error\n");
		return (0);
	}
	i = 0;
	while (i < 9)
	{
		i++;
		if (valid(argv[i]) == 0)
		{
			print ("Error\n");
			return(0);  //end the program
		}
	}
	printgrid(&argv[1]);
	if (solvesudoku(&argv[1],0) == 1)
		printgrid(&argv[1]);
	else
		print("Error\n");
	return (0);
}
