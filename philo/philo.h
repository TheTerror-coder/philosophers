/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/11/17 15:32:28 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "preprocss.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>

/* -------------------------------------------------------------------------- */
/* ------------------------ Files and Public Functions ---------------------- */
/* -------------------------------------------------------------------------- */

/* ------------------------------- parsing.c -------------------------------- */

int		ft_parse(t_meal *meal, int argc, char **argv);

/* -------------------------------- init.c ---------------------------------- */

int		ft_initmem(t_meal *meal);

/* ------------------------------- philo.c ---------------------------------- */

void	*philo_routine(void *arg);
int		ft_lock(t_philo *philo, pthread_mutex_t *fork1, pthread_mutex_t *fork2);
int		go_to_hell(t_philo *philo);
int		thegrimreaper(t_philo *philo);
int		display_status(char *str, t_philo *philo);

/* ------------------------------ activity.c -------------------------------- */

int		ft_think(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		agonize(t_philo *philo, pthread_mutex_t *locked1, \
											pthread_mutex_t *locked2);
int		unlock_then_die(pthread_mutex_t *locked1, pthread_mutex_t *locked2);

/* -------------------------------- time.c ---------------------------------- */

time_t	ft_time_usec(void);
time_t	ft_time_msec(void);
time_t	ft_time_sec(void);

#endif