/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atasyure <atasyure@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:07:08 by atasyure          #+#    #+#             */
/*   Updated: 2023/11/28 16:08:21 by atasyure         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	bit_handler(int bit, siginfo_t *info)
{
	static int	shift = 7;
	static int	res = 0;

	res += (bit << shift);
	if (shift == 0)
	{
		ft_printf("%c", res);
		shift = 7;
		res = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		shift--;
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
		bit_handler(1, info);
	else
		bit_handler(0, info);
	(void)context;
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("Pid-> %d\n", pid);
	sig.sa_sigaction = signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
