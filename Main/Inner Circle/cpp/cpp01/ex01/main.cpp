/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:58 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 19:18:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie leaderZombie("Leader");
	leaderZombie.announce();

	Zombie *zombieHorde = leaderZombie.zombieHorde(10, "Dregs");
	for(int i = 0; i < 10; i++)
		zombieHorde[i].announce();
	delete[] zombieHorde;
}
