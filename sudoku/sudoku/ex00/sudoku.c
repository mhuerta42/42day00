/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:34:12 by mhuerta           #+#    #+#             */
/*   Updated: 2018/11/04 23:39:12 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

// A function to print the grid
void printgrid(char **grid)
{
	int		row = 0;
	int		col = 0;
	
	while (row < 9)
    {
		col = 0;
		while (col < 9)
        {
			ft_putchar(grid[row][col]);
			if(col<8)
				ft_putchar(' ');
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}

//check if parameters are valid - include 9 charachrets with 1-9 or .
int		valid(char *string)
{
	int		len = 0;
	while (string[len] != '\0')
	{
		if ((string[len] >= '1' && string[len] <= '9') || string[len] == '.')
			len++;
		else
			return(0);
	}
	return len == 9;
}

//check if there is no similar number in the same colomn
int		columnok(char **grid, int position, char number)
{
	int k = 0;
	while (k < 9)
	{
		if (grid[k][position % 9] == number)
			return (0);
        k++;
    }
    return (1);
}

//check if there is no similar number in the same row
int    rowok(char **grid, int position, char number)
{
int k = 0;
    while (k < 9)
    {
        if (grid[position / 9][k] == number)
            return (0);
        k++;
    }
    return (1);
}

//check if there is no similar number in the same 3x3 box
int    boxok(char **grid, int position, char number)
{
    int		i=0;
    int		j=0;
    while(i < 3)
    {
		j = 0;
		while (j < 3)
        {
            if (grid[(((position / 9) / 3) * 3) + i][(((position % 9) / 3) * 3) + j] ==
                    number)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int		solvesudoku(char **grid,int position)
{
   char    number;
   
   if (position == 81)
	   return (1);
   if (grid[position / 9][position % 9] != '.')
	   return (solvesudoku(grid, position + 1));
   number = '1';
   while (number <= '9')
   {
	   if (columnok(grid, position, number) &&
		rowok(grid, position, number) &&
        boxok(grid, position, number))
       {
		   grid[position / 9][position % 9] = number;
		   if (solvesudoku(grid, position + 1))
			   return (1);
		   grid[position / 9][position % 9] = '.';
	   }
	   number = number + 1;
   }
   return (0);
}
