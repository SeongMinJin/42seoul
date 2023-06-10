/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:37:49 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 11:48:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* Constructors & Destructor */
Character::Character() : ICharacter(), name("Nobody")
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}
Character::Character( std::string name ) : ICharacter(), name(name)
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}
Character::Character( const Character &c ) : ICharacter(), name(c. getName())
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = c.slot[i];
}
Character::~Character() {}

/* Operator overload */
Character &Character::operator=( const Character &c )
{
	if (this != &c)
	{
		for (int i = 0; i < 4; i++)
			this->slot[i] = c.slot[i];
	}
	return *this;
}





/* Member functions */

std::string const &Character::getName( void ) const { return this->name; }

void Character::equip( AMateria *m )
{
	int idx;

	if (!m)
	{
		std::cout << "No such Materia." << std::endl;
		return ;
	}


	for (idx = 0; this->slot[idx] && idx < 4; idx++);

	switch (idx)
	{
	case 4:
		std::cout << "No more slot..." << std::endl;
		break;
	default:
		slot[idx] = m;
		std::cout << "Slot " << idx << " is equipped with " << m->getType() << std::endl; 
	}
}

void Character::unequip( int idx )
{
	if (idx < 0 || idx > 3)
		std::cout << "Slot " << idx << " is not exist." << std::endl;
	else if (this->slot[idx] == NULL)
		std::cout << "Slot " << idx << " is already unequiped." << std::endl;
	else
	{
		std::cout << "Slot " << idx << " is unequpped." << std::endl;
		this->slot[idx] = NULL;
	}
}


void Character::use( int idx, ICharacter &target )
{
	if (idx < 0 || idx > 3)
		std::cout << "Slot " << idx << " is not exist." << std::endl;
	else if (this->slot[idx] == NULL)
		std::cout << "Slot "<< idx << " is empty." << std::endl;
	else
		this->slot[idx]->use(target);
}