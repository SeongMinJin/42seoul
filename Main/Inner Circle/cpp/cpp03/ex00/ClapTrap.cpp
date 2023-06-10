/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:41:12 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 12:31:40 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/* Constructors & Destructors */
ClapTrap::ClapTrap() : name("Nobody"), hitPoint(10), energyPoint(10), attackDamage(0) { std::cout << "Default constructor is called." << std::endl; }
ClapTrap::ClapTrap( std::string name ) : name(name), hitPoint(10), energyPoint(10), attackDamage(0) { std::cout << "String constructor is called." << std::endl; }
ClapTrap::ClapTrap( const ClapTrap &ct ) : name(ct.getName()), hitPoint(ct.getHitPoint()), energyPoint(ct.getEnergyPoint()), attackDamage(ct.getAttackDamage()) { std::cout << "Copy constructor is called." << std::endl; }
ClapTrap::~ClapTrap() { std::cout << "Destructor is called." << std::endl; }


/* Operator overload */
ClapTrap &ClapTrap::operator=( const ClapTrap &ct )
{
	if (this != &ct)
	{
		this->name = ct.getName();
		this->hitPoint = ct.getHitPoint();
		this->energyPoint = ct.getEnergyPoint();
		this->attackDamage = ct.getAttackDamage();
		std::cout << "Copy assignment is called." << std::endl;
	}
	return *this;
}


/* public member functions */
std::string ClapTrap::getName( void ) const { return this->name; }
int ClapTrap::getHitPoint( void ) const { return this->hitPoint; }
int ClapTrap::getEnergyPoint( void ) const {return this->energyPoint; }
int ClapTrap::getAttackDamage( void ) const {return this->attackDamage; }


void ClapTrap::attack( const std::string &target )
{
	if (this->getHitPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " has not enough hit points." << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " has not enough energy points." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->energyPoint--;
	}
}

void ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->getName() << " is attacked and damaged " << amount << " points." << std::endl;
	this->hitPoint -= amount;
}


void ClapTrap::beRepaired( unsigned int amount )
{
	if (this->getHitPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " has not enough hit points." << std::endl;
	else if (this->getEnergyPoint() == 0)
		std::cout << "ClapTrap " << this->getName() << " has not enough energy points." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->getName() << " is repaired and healed " << amount << " points." << std::endl;
		this->hitPoint += amount;
		this->energyPoint--;
	}
}
