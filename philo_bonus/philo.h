#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>

# define CNRM "\x1B[0m"
# define CRED "\x1B[31m"
# define CGRN "\x1B[32m"
# define CYEL "\x1B[33m"
# define CBLU "\x1B[34m"
# define CMAG "\x1B[35m"
# define CCYN "\x1B[36m"
# define CWHT "\x1B[37m"

typedef struct s_table {
	int64_t			start_table;
	int64_t			time_life;
	int64_t			time_eat;
	int64_t			time_sleep;
	int32_t			num_count_eat;
	int16_t			num_philo;
}					t_table;

typedef struct s_philo {
	sem_t			*forks;
	sem_t			*print;
	t_table			*s_table;
	int64_t			last_eat;
	int64_t			time_death;
	int32_t			timeout;
	int32_t			actual_count_eat;
	int16_t			id;
}					t_philo;

typedef struct s_processes
{
	pid_t			pid;
	void			*next;
}					t_processes;

typedef struct s_monitor {
	t_philo			*s_arr_philo;
	t_table			*s_table;
	t_processes		*s_processes;
}					t_monitor;

void				*philo(void *data);
void				*monitor(void *data);
void				free_struct(t_monitor *s_monitor);
int8_t				create_table(t_table *s_table);
int64_t				ft_atoi(const char *str);
int64_t				time_unix_ms(void);
void				timeout(int64_t to_time);
#endif
