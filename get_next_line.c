/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:39:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/24 18:20:56 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (++j < ft_strlen(s2))
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

int	ft_is_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_start(char *s)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_end(char *str)
{
	int		i;
	int		j;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	while (str[i + j])
	{
		ret[j] = str[i + j];
		j++;
	}
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char *stack = 0;
	int			i;
	char		*temp;
	char		*ret;
	char		buff[BUFFER_SIZE + 1];

	i = read(fd, buff, BUFFER_SIZE);
	if (i == 0)
	{
		temp = ft_end(stack);
		stack = NULL;
		return (temp);
	}
	buff[i] = '\0';
	while (i != 0)
	{
		temp = stack;
		stack = ft_strjoin(temp, buff);
		free(temp);
		if (ft_is_new_line(buff) == 1)
			break;
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0)
		{
			temp = ft_start(stack);
			stack = NULL;
			return (temp);
		}
		buff[i] = '\0';
	}
	ret = ft_start(stack);
	stack = ft_end(stack);
	return (ret);
}

int main()
{
	int	fd;
	int	i;

	i = -1;
	fd = open("test.txt", O_RDONLY);
	while (++i < 10)
		printf("%s\n", get_next_line(fd));
	// get_next_line(fd);
	close(fd);
	//system("leaks a.out");
}