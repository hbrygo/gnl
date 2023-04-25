/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:39:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/25 18:00:04 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len1;
	size_t	len2;

	i = -1;
	j = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (++i < len1)
		str[i] = s1[i];
	while (++j < len2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

char	*ft_start(char *s)
{
	char	*dest;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len])
		len++;
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_end(char *s1)
{
	int		i;
	int		j;
	char	*ret;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
		return (ft_free(s1));
	i++;
	ret = malloc(sizeof(char) * (ft_strlen(s1 + i) + 1));
	if (!ret)
		return (ft_free(s1));
	while (s1[i + j])
	{
		ret[j] = s1[i + j];
		j++;
	}
	ret[j] = '\0';
	free(s1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stack = 0;
	int			i;
	char		*ret;
	char		buff[OPEN_MAX][BUFFER_SIZE + 1];

	while (ft_is_new_line(stack) == 0)
	{
		i = read(fd, buff[fd], BUFFER_SIZE);
		if (i == -1)
			return (ft_set_stack(&stack));
		if (i == 0)
			break ;
		buff[fd][i] = '\0';
		stack = ft_join(stack, &ret, buff[fd]);
		if (!stack)
			return (NULL);
		free(ret);
	}
	ret = ft_start(stack);
	if (!ret)
		return (ft_set_stack(&stack));
	stack = ft_end(stack);
	if (stack && stack[0] == '\0')
		ft_set_stack(&stack);
	return (ret);
}

// int main()
// {
// 	int	fd;
// 	int	i;
// 	char	*str;

// 	i = -1;
// 	fd = open("test.txt", O_RDONLY);
// 	while (++i < 10)
// 	{
// 		str = get_next_line(fd);
// 		// printf("%s", str);
// 		// if (i == 3)
// 		// 	printf("!!! [%s]\n", str);
// 		free(str);
// 	}
// 	//printf("\n");
// 	close(fd);
// 	// system("leaks a.out");
// }