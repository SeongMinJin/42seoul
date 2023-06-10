/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:41:12 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:43:11 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/* Constructors & Destructors */
ClapTrap::ClapTrap() : name("Nobody"), hitPoint(10), energyPoint(10), attackDamage(0) { std::cout << "ClapTrap Default constructor is called." << std::endl; }
ClapTrap::ClapTrap( std::string name ) : name(name), hitPoint(10), energyPoint(10), attackDamage(0) { std::cout << "ClapTrap String constructor is called." << std::endl; }
ClapTrap::ClapTrap( std::string name, int hitPoint, int energyPoint, int attackDamage) : name(name), hitPoint(hitPoint), energyPoint(energyPoint), attackDamage(attackDamage) { std::cout << "ClapTrap mixed constructor is called." << std::endl; }
ClapTrap::ClapTrap( const ClapTrap &ct ) : name(ct.getName()), hitPoint(ct.getHitPoint()), energyPoint(ct.getEnergyPoint()), attackDamage(ct.getAttackDamage()) { std::cout << "ClapTrap Copy constructor is called." << std::endl; }
ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor is called." << std::endl; }


/* Operator overload */
ClapTrap &ClapTrap::operator=( const ClapTrap &ct )
{
	if (this != &ct)
	{
		std::cout << "ClapTrap Copy assignment is called." << std::endl;
		this->name = ct.getName();
		this->hitPoint = ct.getHitPoint();
		this->energyPoint = ct.getEnergyPoint();
		this->attackDamage = ct.getAttackDamage();
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
