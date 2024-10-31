/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:28:28 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/16 18:28:36 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

char	*lolilol(char **str, char *strr, int x, int y)
{
	char	*line;
	char	*temp;

	line = (char *)malloc(sizeof(char) * (x + 1));
	if (!line)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (y + 1));
	if (!temp)
		return (NULL);
	x = 0;
	y = 0;
	while (strr[y] != '\n' && strr[y] != '\0')
		line[x++] = strr[y++];
	line[x] = '\0';
	x = 0;
	while (strr[++y] != '\0')
		temp[x++] = strr[y];
	temp[x] = '\0';
	free(strr);
	*str = temp;
	return (line);
}

char	*ft_nextline(char **str)
{
	char	*strr;
	int		x;
	int		y;

	strr = *str;
	x = 0;
	y = 0;
	while (strr[x] != '\n' && strr[x] != '\0')
		x++;
	while (strr[x + y] != '\0')
		y++;
	return (lolilol(str, strr, x, y));
}

int	free_for_rtn(void *ptr, int rtn)
{
	free(ptr);
	return (rtn);
}
