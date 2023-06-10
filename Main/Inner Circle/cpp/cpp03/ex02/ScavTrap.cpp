/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:39:49 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 20:45:56 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* constructors & destructor */
ScavTrap::ScavTrap() : ClapTrap( "Nobody", 100, 50, 20) { std::cout << "ScavTrap default constructor is called." << std::endl; }
ScavTrap::ScavTrap( std::string name ) : ClapTrap( name, 100, 50, 20 ) { std::cout << "ScavTrap string constructor is called." << std::endl; }
ScavTrap::ScavTrap( const ScavTrap &ct ) : ClapTrap( ct.getName(), ct.getHitPoint(), ct.getEnergyPoint(), ct.getAttackDamage() ) { std::cout << "ScavTrap copy constructor is called." << std::endl; }
ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor is called." << std::endl; }


/* operator overload*/
ScavTrap &ScavTrap::operator=( const ScavTrap &ct )
{
	if (this != &ct)
	{
		std::cout << "ScavTrap copy assignment is called." << std::endl;
		this->name = ct.getName();
		this->hitPoint = ct.getHitPoint();
		this->energyPoint = ct.getEnergyPoint();
		this->attackDamage = ct.getAttackDamage();
	}
	return *this;
}


/* public member functions */
void ScavTrap::guardGate( void ) const { std::cout << this->getName() << " is Gate Keeper mode now!" << std::endl; }
void ScavTrap::attack( const std::string &target )
{
	if (this->getHitPoint() == 0)
		std::cout << "ScavTrap " << this->getName() << " has not enough hit points." << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "ScavTrap " << this->getName() << " has not enough energy points." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}
