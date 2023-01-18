#include "minitalk.h"

void	send_bits(unsigned int c, int server_pid)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i > 0)
	{
		bit = (unsigned char)(c & 1);
		c = *((unsigned char *) &c) >> 1;
		if (bit)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i--;
		usleep(350);
	}
}

int main(int agrc, char **argv)
{
    int pid;
	int	i;
	int c;

	i = 0;
    if (agrc != 3)
        ft_putstr_fd("Invalid argument, provide only PID and message\n", 1);
    pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		c = argv[2][i];
		send_bits(c, pid);
		i++;
	}
	return (0);
}