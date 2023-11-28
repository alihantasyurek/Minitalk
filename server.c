/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:06:17 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/28 16:06:17 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	bit_handler(int bit)
{
	static int	shift = 7;
	static int	res = 0;

	res += (bit << shift);
	if (shift == 0)
	{
		ft_printf("%c", res);
		shift = 7;
		res = 0;
	}
	else
		shift--;
}

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		bit_handler(1);
	else
		bit_handler(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Pid-> %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
