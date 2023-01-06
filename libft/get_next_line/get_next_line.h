/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:11:45 by retcheba          #+#    #+#             */
/*   Updated: 2022/05/06 17:53:27 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *s);
int		is_line_break(char *str);
char	*ft_gnl_strjoin(char *s1, char const *s2);
char	*ft_save(char *line);

#endif
