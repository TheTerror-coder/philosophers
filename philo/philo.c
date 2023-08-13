/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:18 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/13 21:08:14 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_lock(t_philo *philo, pthread_mutex_t *fork1, pthread_mutex_t *fork2);

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	printf("Start N°%d\n", philo->num_philo);
	philo->time_before = philo->meal->time_start;
	while (1)
	{
		philo->timestamp = ft_time_msec() - philo->meal->time_start;
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		philo->ms_time = ft_time_msec();
	}
	return ((void *) 1);
}

int	ft_eat(t_philo *philo)
{
	philo->ms_eat = 0;
	if (philo->num_philo / 2)
		ft_lock(philo, philo->left_fork, philo->right_fork);
	else
		ft_lock(philo, philo->right_fork, philo->left_fork);
	philo->timestamp = ft_time_msec() - philo->meal->time_start;
	printf("%d %d is eating\n", philo->timestamp, philo->num_philo);
	while (philo->ms_eat < philo->meal->time_to_eat)
	{
		usleep(1000);
		philo->timestamp = ft_time_msec() - philo->meal->time_start;
		philo->ms_eat += (philo->timestamp - philo->time_before);
		philo->time_before = philo->timestamp;
		if (philo->ms_eat >= philo->meal->time_to_die)
			ft_go_to_hell(philo);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	ft_lock(t_philo *philo, pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
	pthread_mutex_lock(fork1);
	philo->timestamp = ft_time_msec() - philo->meal->time_start;
	printf("%d %d has taken a fork\n", philo->timestamp, philo->num_philo);
	pthread_mutex_lock(fork2);
	philo->timestamp = ft_time_msec() - philo->meal->time_start;
	printf("%d %d has taken a fork\n", philo->timestamp, philo->num_philo);
	return (1);
}


