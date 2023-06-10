/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:18:03 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 17:33:43 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie nobody;
	Zombie linux("linux");
	Zombie mac("mac");
	Zombie window("window");

	nobody.announce();

	linux.announce();
	Zombie *debian = linux.newZombie("debian");
	debian->announce();
	linux.randomChump("centOS");
	delete debian;

	mac.announce();
	Zombie *iPhone = mac.newZombie("iPhone");
	iPhone->announce();
	mac.randomChump("iPad");

	window.announce();
	window.randomChump("window7");
	Zombie *window10 = window.newZombie("window10");
	window10->announce();

	return (0);
}
