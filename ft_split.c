/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:08:02 by ebakirog          #+#    #+#             */
/*   Updated: 2024/01/23 14:08:04 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_wlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (*(s + i) && *(s + i) != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ft_getword(char const *s, char c, int i)
{
	char	*str;
	int		len;
	int		j;

	len = ft_wlen(s, c, i);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (*(s + i) != 0 && *(s + i) != c)
	{
		str[j] = *(s + i);
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

static int	ft_countofword(char const *s, char c)
{
	int	countword;
	int	i;

	i = 0;
	countword = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i) != 0)
		{
			i++;
		}
		if (*(s + i) != 0)
		{
			countword++;
		}
		while (*(s + i) != c && *(s + i) != 0)
			i++;
	}
	return (countword);
}

char	**ft_allfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc((ft_countofword(s, c) + 1) * sizeof(char *));
	if (!str)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		while (*(s + i) == c && *(s + i) != 0)
			i++;
		if (*(s + i))
		{
			str[j] = ft_getword(s, c, i);
			if (!str[j++])
				return (ft_allfree(str));
		}
		while (*(s + i) != c && *(s + i) != 0)
			i++;
	}
	return (str[j] = 0, str);
}
