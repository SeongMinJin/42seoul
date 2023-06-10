/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:02 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:39:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

	FragTrap A("JEA-SEOK");
	std::cout << "=======================================" << std::endl;
	ScavTrap C("HONG-CHUL");
	std::cout << "=======================================" << std::endl;
	ClapTrap E("MYEONG-SOO");
	std::cout << "=======================================" << std::endl;



	std::cout << A.getName() << std::endl;
	std::cout << A.getHitPoint() << std::endl;
	std::cout << A.getEnergyPoint() << std::endl;
	std::cout << A.getAttackDamage() << std::endl;
	A.highFivesGuys();
	std::cout << "=======================================" << std::endl;
	std::cout << C.getName() << std::endl;
	std::cout << C.getHitPoint() << std::endl;
	std::cout << C.getEnergyPoint() << std::endl;
	std::cout << C.getAttackDamage() << std::endl;
	C.guardGate();
	std::cout << "=======================================" << std::endl;
	std::cout << E.getName() << std::endl;
	std::cout << E.getHitPoint() << std::endl;
	std::cout << E.getEnergyPoint() << std::endl;
	std::cout << E.getAttackDamage() << std::endl;
	std::cout << "=======================================" << std::endl;

	return 0;
}
