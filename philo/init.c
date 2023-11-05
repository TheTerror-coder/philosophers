/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:54:20 by TheTerror         #+#    #+#             */
/*   Updated: 2023/11/05 17:18:37 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_meal *meal);

int	ft_initmem(t_meal *meal)
{
	int	i;

	i = -1;
	pthread_mutex_init(&meal->access, NULL);
	pthread_mutex_init(&meal->display, NULL);
	pthread_mutex_init(&meal->deathrow, NULL);
	meal->philos = malloc(sizeof(t_philo *) * meal->nbr_of_philo);
	if (!meal->philos)
		return (0);
	memset(meal->philos, 0, sizeof(t_philo *) * meal->nbr_of_philo);
	while (++i < meal->nbr_of_philo)
	{
		meal->philos[i] = malloc(sizeof(t_philo));
		if (!meal->philos[i])
			return (0);
		meal->i_free++;
		memset(meal->philos[i], 0, sizeof(t_philo));
	}
	i = -1;
	while (++i < meal->nbr_of_philo)
	{
		meal->philos[i]->right_fork = malloc(sizeof(pthread_mutex_t));
		if (!meal->philos[i]->right_fork)
			return (0);
		pthread_mutex_init(meal->philos[i]->right_fork, NULL);
	}
	ft_init_philo(meal);
	return (1);
}

int	ft_init_philo(t_meal *meal)
{
	int	i;

	i = -1;
	while (++i < meal->nbr_of_philo)
	{
		meal->philos[i]->meal = meal;
		meal->philos[i]->num_philo = i + 1;
		meal->philos[i]->meal_countdown = meal->nb_meal_max;
		if (i == 0 && meal->nbr_of_philo > 1)
			meal->philos[i]->left_fork = \
						meal->philos[meal->nbr_of_philo - 1]->right_fork;
		else if (meal->nbr_of_philo > 1)
			meal->philos[i]->left_fork = meal->philos[i - 1]->right_fork;
		else
			meal->philos[i]->left_fork = NULL;
	}
	return (1);
}
