/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:02 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:35:14 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap A;
	ClapTrap B("B");
	ClapTrap C(A);
	ClapTrap D;

	D = C;
	D = ClapTrap("D");
	std::cout << "-------------------------------" << std::endl;

	B.attack("D");
	D.takeDamage(B.getAttackDamage());

	std::cout << "B - eneryPoint : " << B.getEnergyPoint() << std::endl;
	std::cout << "D - hitPoint : " << D.getHitPoint() << std::endl;

	std::cout << "-------------------------------" << std::endl;
	for(int i = 0; i < 10; i++)
	{
		B.attack("D");
		std::cout << "B - eneryPoint : " << B.getEnergyPoint() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl;
	D.beRepaired(10);
	std::cout << "D - energyPoint : " << D.getEnergyPoint() << std::endl;
	std::cout << "D - hitPoint : " << D.getHitPoint() << std::endl;

	return 0;
}
