/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoria <cdoria@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:22:21 by cdoria            #+#    #+#             */
/*   Updated: 2022/01/19 17:49:56 by cdoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK
# define MINITALK

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
