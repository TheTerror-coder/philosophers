/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:28:50 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/15 22:58:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checkerrors(char **argv);
int	ft_atoi_philo(const char *nptr);

int	ft_parse(t_meal *meal, int argc, char **argv)
{
	meal->argc = argc;
	meal->argv = argv;
	if (argc < 5)
		return (printf("missing arguments\n"), 0);
	if (argc > 6)
		return (printf("too much arguments\n"), 0);
	if (!ft_checkerrors(argv))
		return (0);
	meal->nbr_of_philo = ft_atoi_philo(argv[1]);
	meal->time_to_die = ft_atoi_philo(argv[2]);
	meal->time_to_eat = ft_atoi_philo(argv[3]);
	meal->time_to_sleep = ft_atoi_philo(argv[4]);
	if (argc == 6)
		meal->nb_meal_max = ft_atoi_philo(argv[5]);
	else
		meal->nb_meal_max = -1;
	if (meal->nbr_of_philo < 1)
		return (printf("no one at the table\nyou should invite some people - \
but only philosophers!!!\n"), 0);
	return (1);
}

int	ft_checkerrors(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (!argv[i][0])
			return (printf("error\n"), 0);
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '+')
				return (printf("error\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_philo(const char *nptr)
{
	unsigned int		i;
	int					sign;
	unsigned long long	fdb;

	i = 0;
	fdb = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		fdb = (fdb * 10) + (nptr[i] - 48);
		if (fdb > __LONG_MAX__ && sign == 1)
			return (-1);
		if (fdb > __LONG_MAX__ && sign == -1)
			return (0);
		i++;
	}
	return ((int)(fdb * sign));
}
