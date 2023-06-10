/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:31:30 by seojin            #+#    #+#             */
/*   Updated: 2022/11/08 19:39:38 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() : name("Nobody"), weapon(NULL) {}
HumanB::HumanB( std::string name ) : name(name), weapon(NULL) {}
HumanB::~HumanB() { std::cout << name << " is dead." << std::endl; }

void HumanB::attack( void )
{
	if (!weapon)
		std::cout << getName() << " doesn't have any weapon..." << std::endl;
	else
		std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &weapon ) { this->weapon = &weapon; }

std::string HumanB::getName( void ) { return name; }
