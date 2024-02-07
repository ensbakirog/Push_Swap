/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:09:10 by ebakirog          #+#    #+#             */
/*   Updated: 2024/01/23 14:09:12 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	push_swap(char **argv)
{
	t_push_swap	arrays;
	int			i;

	arrays.size_a = pushswap_len(argv);
	arrays.a = malloc(sizeof(int) * arrays.size_a);
	if (!arrays.a)
		return (ft_allfree(argv), write(2, "Error\n", 6), 0);
	arrays.b = malloc(sizeof(int) * arrays.size_a);
	if (!arrays.b)
		return (free(arrays.a), ft_allfree(argv), write(2, "Error\n", 6), 0);
	arrays.size_b = 0;
	i = -1;
	while (++i < arrays.size_a)
		arrays.a[i] = push_swap_atoi(argv[i], arrays, argv);
	ctrl_doubles(arrays, arrays.size_a, argv);
	start_sort(&arrays, arrays.size_a);
	free(arrays.a);
	free(arrays.b);
	ft_allfree(argv);
	return (0);
}

char	**arg_converter(char **argv)
{
	char	*str;
	char	*tmp;
	char	**str2;
	int		i;

	str = NULL;
	i = -1;
	while (argv[++i])
	{
		if (!str)
			str = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(str, " ");
			free(str);
			if (str == NULL || tmp == NULL)
				return (NULL);
			str = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
	}
	str2 = ft_split(str, ' ');
	return (free(str), str2);
}

int	main(int argc, char **argv)
{
	char	**str;

	if (argc > 1)
	{
		argv++;
		str = arg_converter(argv);
		if (str == NULL)
			return (write(2, "Error\n", 6), 0);
		push_swap(str);
		return (0);
	}
	return (0);
}
