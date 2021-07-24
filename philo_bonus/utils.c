#include "philo.h"

void	free_struct(t_monitor *s_monitor)
{
	t_processes	*s_processes;

	sem_unlink("philo_print");
	sem_unlink("philo_forks");
	while (s_monitor->s_processes)
	{
		s_processes = s_monitor->s_processes->next;
		kill(s_monitor->s_processes->pid, SIGINT);
		free(s_monitor->s_processes);
		s_monitor->s_processes = s_processes;
	}
	free(s_monitor->s_arr_philo);
	free(s_monitor);
}

int64_t	ft_atoi(const char *str)
{
	unsigned int	res;
	int				sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' ||
		   *str == '\v' || *str == '\f' ||
		   *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	if (!(*str >= '0' && *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		if ((res * 10) < res)
			return ((sign < 1) ? 0 : -1);
		res = res * 10 + (*str++ - '0');
	}
	if (*str && !(*str >= '0' && *str <= '9'))
		return (-1);
	return ((int)res * sign);
}

int64_t	time_unix_ms(void)
{
	struct timeval	s_time;

	gettimeofday(&s_time, NULL);
	return (s_time.tv_sec * 1000 + (int)(s_time.tv_usec * 0.001));
}

void	timeout(int64_t to_time)
{
	int64_t	time;

	while (1)
	{
		time = time_unix_ms();
		if (to_time <= time)
			break ;
	}
}