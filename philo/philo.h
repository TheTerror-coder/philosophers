/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/16 14:13:32 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "preprocss.h"
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<sys/time.h>
# include<time.h>

/* -------------------------------------------------------------------------- */
/* ------------------------ Files and Public Functions ---------------------- */
/* -------------------------------------------------------------------------- */

/* ------------------------------- parsing.c -------------------------------- */

int		ft_parse(t_meal *meal, int argc, char **argv);

/* -------------------------------- init.c ---------------------------------- */

int		ft_initmem(t_meal *meal);

/* ------------------------------- philo.c ---------------------------------- */

void	*ft_philo_routine(void *arg);
int		ft_lock(t_philo *philo, pthread_mutex_t *fork1, pthread_mutex_t *fork2);
int		ft_go_to_hell(t_philo *philo);
int		ft_thegrimreaper(t_philo *philo);
int		ft_display_status(char *str, t_philo *philo);

/* ------------------------------ activity.c -------------------------------- */

int		ft_think(t_philo *philo, time_t time_to_wait, time_t time_til_death);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);

/* -------------------------------- time.c ---------------------------------- */

time_t	ft_time_usec(void);
time_t	ft_time_msec(void);
time_t	ft_time_sec(void);

#endif