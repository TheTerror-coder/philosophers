/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:35:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/13 18:53:12 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_launch(t_meal *meal);

int	main(int argc, char **argv)
{
	t_meal	*meal;

	meal = malloc(sizeof(t_meal));
	if (!meal)
	 	return (1);
	memset(meal, 0, sizeof(t_meal));
	if (!ft_parse(meal, argc, argv))
		return (1);
	ft_initphilo(meal);
	ft_launch(meal);
	free(meal);
	return (0);
}

int	ft_launch(t_meal *meal)
{
	meal->time_start = ft_time_msec();
	pthread_create(&meal->philo1->thread, NULL, ft_philo_routine, meal->philo1);
	pthread_create(&meal->philo2->thread, NULL, ft_philo_routine, meal->philo2);
	pthread_join(meal->philo1->thread, NULL);
	pthread_join(meal->philo2->thread, NULL);
	return (1);
}
