/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:42:48 by TheTerror         #+#    #+#             */
/*   Updated: 2023/11/05 17:27:53 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo, time_t time_to_wait, time_t time_til_death)
{
	time_t	ms_tool;

	ms_tool = 0;
	ft_display_status("is thinking", philo);
	time_to_wait = philo->meal->time_to_eat - philo->meal->time_to_sleep;
	philo->timestamp = ft_time_msec() - philo->time_start;
	time_til_death = \
			philo->meal->time_to_die - (philo->timestamp - philo->ms_lastmeal);
	if (time_to_wait > 0 && time_til_death > 0 && time_to_wait > time_til_death)
	{
		while (1)
		{
			usleep(1000);
			if (!ft_thegrimreaper(philo))
				return (0);
			ms_tool += 1;
			if (ms_tool - 2 > time_til_death)
				break ;
		}
	}
	return (1);
}

int	ft_eat(t_philo *philo)
{
	philo->ms_eat = 0;
	if (!ft_lock(philo, NULL, NULL))
		return (0);
	ft_display_status("is eating", philo);
	philo->meal_countdown--;
	philo->ms_lastmeal = ft_time_msec() - philo->time_start;
	philo->time_before = philo->ms_lastmeal;
	while (philo->ms_eat < philo->meal->time_to_eat)
	{
		usleep(1000);
		philo->timestamp = ft_time_msec() - philo->time_start;
		philo->ms_eat += (philo->timestamp - philo->time_before);
		philo->time_before = philo->timestamp;
		if (!ft_thegrimreaper(philo))
			return (0);
	}
	if (philo->meal->nb_meal_max > 0 && !philo->meal_countdown)
	{
		pthread_mutex_lock(&philo->meal->deathrow);
		pthread_mutex_lock(&philo->meal->access);
		philo->meal->undeads++;
		pthread_mutex_unlock(&philo->meal->access);
		pthread_mutex_unlock(&philo->meal->deathrow);
	}
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	philo->ms_sleep = 0;
	if (!ft_thegrimreaper(philo))
		return (0);
	ft_display_status("is sleeping", philo);
	philo->time_before = philo->timestamp;
	while (philo->ms_sleep < philo->meal->time_to_sleep)
	{
		usleep(1000);
		philo->timestamp = ft_time_msec() - philo->time_start;
		philo->ms_sleep += (philo->timestamp - philo->time_before);
		philo->time_before = philo->timestamp;
		if (!ft_thegrimreaper(philo))
			return (0);
	}
	return (1);
}
