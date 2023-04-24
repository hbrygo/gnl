/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:39:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/21 13:30:47 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_next_line(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
		{
			write(1, &buff[i], 1);
			i++;
			return (i);
		}
		ft_putchar(buff[i]);
		i++;
	}
	return (i);
}

int ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] <= 126 && str[i] >= 32)
		i++;
	return (i);
}

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	int			line;
	static char	*buff;
	int			len;
	int			i;

	len = 1;
	while (len != 0)
	{
		if (buff)
		{
			len = ft_strlen(buff);
			// printf("\nPas vide: [%d]", ft_strlen(buff));
			// printf("[%s]\n", buff);
		}
		else
		{
			// printf("\nVide:     [%d]", ft_strlen(buff));
			// printf("[%s]\n", buff);
			len = 0;
			buff = NULL;
		}
		if (len != 0)
		{
			i = 0;
			while (buff[i] != '\n')
			{
				// printf("[%c]", buff[i]);
				// write(1, "[", 1);
				// write(1, &buff[i], 1);
				// write(1, "]", 1);
				i++;
			}
			// printf("nombre passe: %d\n", i);
			buff += i + 1;
			// printf("Reste: %d\n", ft_strlen(buff));
			i = 0;
			while (buff[i] && i < BUFFER_SIZE && buff[i] != '\n' && ft_isprint(buff[i]))
			{
				ft_putchar(buff[i]);
				i++;
			}
		}
	}
	buff = malloc (sizeof(char *) * BUFFER_SIZE);
	if (fd == -1 || !buff)
		return (NULL);
	line = read(fd, buff, BUFFER_SIZE - len);
	if (!line)
		return (NULL);
	if (ft_is_next_line(buff) >= BUFFER_SIZE)
	{
		buff += ft_is_next_line(buff);
	 	return (NULL);
	}
	return (buff);
}

int main()
{
	int	fd;
	int	i;

	i = -1;
	fd = open("test.txt", O_RDONLY);
	while (++i < 4)
		get_next_line(fd);
	close(fd);
}