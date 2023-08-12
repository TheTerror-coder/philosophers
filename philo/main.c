/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:35:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/12 20:23:33 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_meal	*meal;

	meal = malloc(sizeof(t_meal));
	if (!meal)
	 	return (1);
	memset(meal, 0, sizeof(t_meal));
	if (!ft_parse(meal, argc, argv))
		return (1);
	free(meal);
	return (0);
}
