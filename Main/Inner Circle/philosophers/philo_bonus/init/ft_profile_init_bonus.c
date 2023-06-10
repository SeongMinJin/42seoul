/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_profile_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:26:21 by seojin            #+#    #+#             */
/*   Updated: 2022/09/27 23:19:09 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static char	*ft_itoa(int n);
static int	ft_get_len(int n);

t_profile	*ft_profile_init(t_status *status)
{
	t_profile	*profile;
	char		*str;

	profile = (t_profile *)malloc(sizeof(t_profile));
	if (!profile)
		return (NULL);
	profile->alive = ALIVE;
	profile->eat_cnt = 0;
	profile->status = status;
	str = ft_itoa(status->id);
	sem_unlink(str);
	profile->private_sem = sem_open(str, O_CREAT | O_EXCL, \
	S_IRWXU | S_IRWXG | S_IRWXO, 1);
	sem_unlink(str);
	if (profile->private_sem == SEM_FAILED)
		exit(0);
	free(str);
	return (profile);
}

static char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		idx;

	len = ft_get_len(n);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		exit(0);
	str[len] = 0;
	idx = 0;
	while (len--)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

static int	ft_get_len(int n)
{
	int	cnt;

	cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}
