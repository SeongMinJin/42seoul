/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:44:42 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 20:45:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructors & Destructor */
FragTrap::FragTrap() : ClapTrap( "Nobody", 100, 100, 30 ) { std::cout << "FragTrap default constructor is called." << std::endl; }
FragTrap::FragTrap( std::string name ) : ClapTrap( name, 100, 100, 30 ) { std::cout << "FragTrap string constructor is called." << std::endl; }
FragTrap::FragTrap( const FragTrap &ft ) : ClapTrap( ft.getName(), ft.getHitPoint(), ft.getEnergyPoint(), ft.getAttackDamage() ) { std::cout << "FragTrap copy constructor is called." << std::endl; }
FragTrap::~FragTrap() { std::cout << "FragTrap destructor is called." << std::endl; }


/* Operator overload */
FragTrap &FragTrap::operator=( const FragTrap &ft )
{
	if (this != &ft)
	{
		std::cout << "FragTrap copy assignment is called." << std::endl;
		this->name = ft.getName();
		this->hitPoint = ft.getHitPoint();
		this->energyPoint = ft.getEnergyPoint();
		this->attackDamage = ft.getAttackDamage();
	}
	return *this;
}


/* public member functions */

void FragTrap::attack( const std::string &target )
{
	if (this->getHitPoint() == 0)
		std::cout << "FragTrap " << this->getName() << " has not enough hit points." << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "FragTrap " << this->getName() << " has not enough energy points." << std::endl;
	else
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}

void FragTrap::highFivesGuys( void ) const { std::cout << this->getName() << " requests high fives!" << std::endl; }
