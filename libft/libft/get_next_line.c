/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:10:37 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/03 12:51:23 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_verify(char **str, char **line)
{
	char *newline;
	char *tmp;

	while ((newline = ft_strchr(*str, '\n')))
	{
		*line = ft_strndup(*str, (newline - *str));
		tmp = ft_strdup(newline + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (**str)
	{
		*line = ft_strdup(*str);
		ft_bzero(*str, ft_strlen(*str));
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			jebaited;

	if (fd < 0 || BUFF_SIZE <= 0 || (read(fd, buff, 0) < 0) || \
		(jebaited = CHAR_BYTE) < 0)
		return (-1);
	while ((jebaited = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[jebaited] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	if (str[fd] == 0 || str[fd][0] == '\0')
		return (0);
	if (ft_strlen(str[fd]) > 0)
		return (ft_verify(&str[fd], line));
	return (0);
}
