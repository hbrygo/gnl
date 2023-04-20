/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:39:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/20 18:16:30 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	ft_putchar(char c)
{
	int	i;

	i = 0;
	write(1, &c, 1);
	i++;
}

int	ft_is_next_line(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
		{
			write(1, "\n", 1);
			return (0);
		}
		ft_putchar(buff[i]);
		i++;
	}
	return (1);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] <= 126 && str[i] >= 32)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			line;
	static char	*buff;
	int			len;

	if (!len)
		len = ft_strlen(buff);
	else
	{
		len = 0;
		buff = NULL;
	}
	buff = malloc (sizeof(char *) * BUFFER_SIZE);
	if (fd == -1 || !buff)
		return (NULL);
	line = read(fd, buff, BUFFER_SIZE);
	if (!line)
		return (0);
	if (ft_is_next_line(buff) == 0)
		return (buff);
	return (buff);
}

int main()
{
	int	fd;
	int	i;

	i = -1;
	fd = open("test.txt", O_RDONLY);
	while (++i < 5)
		get_next_line(fd);
	close(fd);
}