/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocss.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/13 21:11:23 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCSS_H
# define PREPROCSS_H

# include<pthread.h>

typedef struct s_meal	t_meal;
typedef struct	s_philo
{
	t_meal	*meal;
	int		num_philo;
	int		ms_eat;
	int		ms_sleep;
	int		ms_think;
	int		timestamp;
	int		time_before;
	int		meal_countdown;
	int		death_countdown;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;


struct	s_meal
{
	int		argc;
	char	**argv;
	int		nbr_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_start;
	int		nb_meal_max;
	pthread_mutex_t	mxdisplay;
	t_philo	*philo1;
	t_philo	*philo2;
};


#endif