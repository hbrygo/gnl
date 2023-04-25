/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:59:37 by hubrygo           #+#    #+#             */
/*   Updated: 2023/04/25 18:00:21 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		ft_is_new_line(char *str);
char	*ft_set_stack(char **s);
char	*ft_join(char *stack, char **ret, char *buff);
char	*ft_strjoin(char *s1, char *s2);

#endif