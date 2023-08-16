/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:35:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/15 23:08:07 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_launch(t_meal *meal);
int	ft_free_meal(t_meal *meal);

int	main(int argc, char **argv)
{
	t_meal	*meal;

	meal = malloc(sizeof(t_meal));
	if (!meal)
		return (1);
	memset(meal, 0, sizeof(t_meal));
	if (!ft_parse(meal, argc, argv))
		return (ft_free_meal(meal), 1);
	if (!ft_initmem(meal))
		return (printf("sys error\n"), ft_free_meal(meal), 1);
	return (!ft_launch(meal));
}

int	ft_launch(t_meal *meal)
{
	int	i;

	i = -1;
	while (++i < meal->nbr_of_philo)
	{
		pthread_create(&meal->philos[i]->thread, NULL, \
								ft_philo_routine, meal->philos[i]);
		usleep(100);
	}
	i = -1;
	while (++i < meal->nbr_of_philo)
		pthread_join(meal->philos[i]->thread, NULL);
	return (ft_free_meal(meal));
}

int	ft_free_meal(t_meal *meal)
{
	int	i;

	i = -1;
	while (++i < meal->i_free)
	{
		if (meal->philos[i]->right_fork)
		{
			pthread_mutex_destroy(meal->philos[i]->right_fork);
			free(meal->philos[i]->right_fork);
		}
		meal->philos[i]->right_fork = NULL;
	}
	i = -1;
	while (++i < meal->i_free)
		free(meal->philos[i]);
	free(meal->philos);
	meal->philos = NULL;
	free(meal);
	meal = NULL;
	return (1);
}