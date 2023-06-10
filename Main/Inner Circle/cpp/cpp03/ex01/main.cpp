/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:02 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 12:51:59 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{

	ScavTrap A("HA-HA");
	ScavTrap B("JAE-SEOK");

	std::cout << "==============================" << std::endl;
	std::cout << A.getName() << std::endl;
	std::cout << A.getHitPoint() << std::endl;
	std::cout << A.getEnergyPoint() << std::endl;
	std::cout << A.getAttackDamage() << std::endl;
	std::cout << "==============================" << std::endl;
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.guardGate();
	std::cout << "==============================" << std::endl;

	return 0;
}
