/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocss.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:42 by TheTerror         #+#    #+#             */
/*   Updated: 2023/11/05 17:18:21 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCSS_H
# define PREPROCSS_H

# include<pthread.h>

/* -------------------------------------------------------------------------- */
/* ---------------------------- Structures ---------------------------------- */
/* -------------------------------------------------------------------------- */

typedef struct s_meal	t_meal;

/* ------------ Structure specific to every philosopher --------------------- */

typedef struct s_philo
{
	t_meal			*meal;
	int				num_philo;
	time_t			ms_eat;
	time_t			ms_sleep;
	time_t			ms_lastmeal;
	time_t			timestamp;
	time_t			time_before;
	time_t			time_start;
	int				meal_countdown;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

/* -------------------------- Main Structure -------------------------------- */

struct s_meal
{
	int				argc;
	char			**argv;
	int				i_free;
	int				nbr_of_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				hellsouls;
	int				undeads;
	int				nb_meal_max;
	pthread_mutex_t	access;
	pthread_mutex_t	display;
	pthread_mutex_t	deathrow;
	t_philo			**philos;
};

#endif