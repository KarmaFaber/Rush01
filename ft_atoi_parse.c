/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:15:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/06/02 14:21:41 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void    ft_atoi_parse(char *argv, int *clues)
{
    int i;
    i = 0;
    while (i < 16)
    {
        if (argv[i * 2] >= '1' && argv[i * 2] <= '4')
        {
            clues[i] = argv[i * 2] - '0';
            //printf("SE GUARDA %d\n", clues[i]);
        }
        else
        {
            write(1, "2error\n", 7);
            return ;
        }
        if (i < 15 && argv[i * 2 + 1] != ' ')
        {
            write(1, "3error\n", 7);
            return ;
        }
        i++;
    }
}

void    ft_validate(int *clues)
{
    int i;
    i = 0;
    while (i < 12)
    {   //comprrobamos las sumas de los colls y rows
        if ((clues[i] + clues[i + 4] < 3) || (clues[i] + clues[i + 4] > 5))
        {
            write(1, "4error\n", 6);
            int sum;
            sum = clues[i] + clues[i + 4];
            write (1, &sum, 1);
            return ;
        }
        i++;
    }
}