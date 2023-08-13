/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:54:20 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/13 18:48:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initphilo(t_meal *meal)
{
	meal->philo1 = malloc(sizeof(t_philo));
	if (!meal->philo1)
		return (0);
	meal->philo2 = malloc(sizeof(t_philo));
	if (!meal->philo2)
		return (0);
	meal->philo1->num_philo = 1;
	meal->philo2->num_philo = 2;
	meal->philo1->left_fork = malloc(sizeof(pthread_mutex_t));
	meal->philo2->left_fork = malloc(sizeof(pthread_mutex_t));
	meal->philo1->right_fork = meal->philo2->left_fork;
	meal->philo2->right_fork = meal->philo1->left_fork;
	pthread_mutex_init(meal->philo1->left_fork, NULL);
	pthread_mutex_init(meal->philo2->left_fork, NULL);
	meal->philo1->meal = meal;
	meal->philo2->meal = meal;
	return (1);
}
