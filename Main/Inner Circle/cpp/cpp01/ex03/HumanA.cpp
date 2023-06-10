/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:31:30 by seojin            #+#    #+#             */
/*   Updated: 2022/12/07 10:54:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : name(name), weapon(weapon) {}
HumanA::~HumanA() { std::cout << name << " is dead." << std::endl; }

void HumanA::attack( void ) { std::cout << getName() << " attacks with their " << weapon.getType() << std::endl; }

std::string HumanA::getName( void ) { return name; }
