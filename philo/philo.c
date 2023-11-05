/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:18 by TheTerror         #+#    #+#             */
/*   Updated: 2023/11/05 17:29:03 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;
	int		fdbk;

	philo = arg;
	fdbk = 0;
	pthread_mutex_lock(&philo->meal->display);
	philo->time_start = ft_time_msec();
	printf("%ldms %d is thinking\n", ft_time_msec() - philo->time_start, philo->num_philo);
	pthread_mutex_unlock(&philo->meal->display);
	philo->ms_lastmeal = philo->time_start;
	while (1)
	{
		if (!ft_thegrimreaper(philo))
			return ((void *) 0);
		fdbk = ft_eat(philo);
		if (philo->left_fork)
			pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (!fdbk)
			return ((void *) 0);
		if (!ft_sleep(philo))
			return ((void *) 0);
		if (!ft_think(philo, 0, 0))
			return ((void *) 0);
		usleep(1000);
	}
	return ((void *) 1);
}

int	ft_lock(t_philo *philo, pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
	if (philo->num_philo % 2)
	{
		fork1 = philo->right_fork;
		fork2 = philo->left_fork;
	}
	else
	{
		fork1 = philo->left_fork;
		fork2 = philo->right_fork;
	}
	if (!fork1)
		return (ft_go_to_hell(philo));
	pthread_mutex_lock(fork1);
	if (!ft_thegrimreaper(philo))
		return (0);
	ft_display_status("has taken a fork", philo);
	if (!fork2)
		return (ft_go_to_hell(philo));
	pthread_mutex_lock(fork2);
	if (!ft_thegrimreaper(philo))
		return (0);
	ft_display_status("has taken a fork", philo);
	return (1);
}

int	ft_go_to_hell(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal->deathrow);
	ft_display_status("died", philo);
	pthread_mutex_lock(&philo->meal->access);
	philo->meal->hellsouls++;
	pthread_mutex_unlock(&philo->meal->access);
	pthread_mutex_unlock(&philo->meal->deathrow);
	return (0);
}

int	ft_thegrimreaper(t_philo *philo)
{
	int	fdbk;

	fdbk = 1;
	pthread_mutex_lock(&philo->meal->access);
	if (philo->meal->undeads >= philo->meal->nbr_of_philo)
		fdbk = 0;
	else if (philo->meal->hellsouls)
		fdbk = 0;
	pthread_mutex_unlock(&philo->meal->access);
	if (!fdbk)
		return (ft_go_to_hell(philo));
	philo->timestamp = ft_time_msec() - philo->time_start;
	if ((philo->timestamp - philo->ms_lastmeal) > philo->meal->time_to_die)
		return (ft_go_to_hell(philo));
	return (fdbk);
}

int	ft_display_status(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->meal->display);
	philo->timestamp = ft_time_msec() - philo->time_start;
	printf("%ldms %d %s\n", philo->timestamp, philo->num_philo, str);
	pthread_mutex_unlock(&philo->meal->display);
	return (1);
}
