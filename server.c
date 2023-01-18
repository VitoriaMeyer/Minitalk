/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeyer-s <vmeyer-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:50:47 by vmeyer-s          #+#    #+#             */
/*   Updated: 2023/01/18 16:57:03 by vmeyer-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_power(unsigned char base, unsigned char power)
{
	unsigned char	sum;

	sum = 1;
	while (power)
	{
		sum = sum * base;
		power--;
	}
	return (sum);
}

void	read_signals(int signal)
{
	static unsigned int		c;
	static int				counter;

	if (signal == SIGUSR1)
		c += ft_power(2, counter);
	counter++;
	if (counter == 8)
	{
		counter = 0;
		write(1, &c, 1);
		c = 0;
	}
	return ;
}

int	main(void)
{
	pid_t					id;
	struct sigaction		sigact;

	id = getpid();
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	sigact.sa_flags = SA_RESTART;
	sigact.sa_handler = read_signals;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
