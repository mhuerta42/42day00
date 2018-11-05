/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuerta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 23:13:02 by mhuerta           #+#    #+#             */
/*   Updated: 2018/11/04 23:16:00 by mhuerta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Utility to print a string - "for the Error"

int		print(char *string)
{
	int i;

	i = 0;
	while(string[i] != '\0')
	{
		ft_putchar(string[i]);
		i++;
	}
	return (0);
}
