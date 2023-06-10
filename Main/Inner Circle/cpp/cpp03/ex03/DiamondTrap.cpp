/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:56:05 by seojin            #+#    #+#             */
/*   Updated: 2022/12/13 13:23:11 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap( "Nobody_clap_name", 100,  50, 30 ), ScavTrap(), FragTrap(), name("Nobody")
{
	std::cout << "DiamondTrap default constructor is called." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name", 100, 50, 30 ), ScavTrap(), FragTrap(), name(name)
{
	std::cout << "DiamondTrap string constructor is called." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &dt ) : ClapTrap( dt.getName() + "_clap_name", dt.getHitPoint(), dt.getEnergyPoint(), dt.getAttackDamage() ), ScavTrap(), FragTrap(), name(dt.getName()) { std::cout << "DiamondTrap copy structor is called." << std::endl; ClapTrap::name = dt.getName() + "_clap_name"; }
DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor is called." << std::endl; }

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &dt )
{
	if (this != &dt)
	{
		std::cout << "ScavTrap copy assignment is called." << std::endl;
		name = dt.getName();
		hitPoint = dt.getHitPoint();
		energyPoint = dt.getEnergyPoint();
		attackDamage = dt.getAttackDamage();
	}
	return *this;
}


std::string DiamondTrap::getName( void ) const { return this->name; }


void DiamondTrap::attack( const std::string &target ) { ScavTrap::attack( target ); }
void DiamondTrap::whoAmI( void ) const { std::cout << "I am " << getName() << ", and My gramdParents is " << ClapTrap::getName() << std::endl; }

