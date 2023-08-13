/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:27:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/13 16:05:51 by TheTerror        ###   ########lyon.fr   */
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


int	ft_parse(t_meal *meal, int argc, char **argv);
int	ft_initphilo(t_meal *meal);
time_t	ft_time_usec(void);
time_t	ft_time_msec(void);
time_t	ft_time_sec(void);
void	*ft_philo_routine(void *arg);

#endif