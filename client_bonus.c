/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:06:58 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/28 16:07:02 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	confirm(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Signal Received\n");
}

void	interpreter(int pid, char *str)
{
	int				shift;
	int				i;

	i = 0;
	while (str[i])
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
			shift--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <Pid> <Message>\n", argv[0]);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, confirm);
	interpreter(pid, argv[2]);
}
