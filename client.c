#include "libft/libft.h"
#include <signal.h>

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
		return (0);
	}
	pid = ft_atoi(argv[1]);
	interpreter(pid, argv[2]);
}
