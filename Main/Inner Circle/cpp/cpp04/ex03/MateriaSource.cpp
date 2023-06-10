/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:12:51 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 10:57:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* Constructors & destructor */
MateriaSource::MateriaSource() : IMateriaSource(), idx(0)
{
	for (int i = 0; i < 4; i++)
	{
		this->source[i] = NULL;
		sourceName[i] = "EMPTY";
	}
}

MateriaSource::MateriaSource( const MateriaSource &m ) : IMateriaSource(), idx(m.idx)
{
	for (int i = 0; i < m.idx; i++)
	{
		this->source[i] = m.copySource(i);
		this->sourceName[i] = m.getSoruceName(i);
	}
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->idx; i++)
	{
		delete this->source[i];
		this->source[i] = NULL;
	}
}

/* Operator overload*/
MateriaSource &MateriaSource::operator=( const MateriaSource &m )
{
	if (this != &m)
	{
		for (int i = 0; i < idx; i++)
		{
			delete this->source[i];
			this->source[i] = NULL;
		}
		for (int i = 0; i < m.idx; i++)
		{
			this->source[i] = m.copySource(i);
			this->sourceName[i] = m.getSoruceName(i);
		}
		this->idx = m.idx;
	}
	return *this;
}




/* Member functions */
std::string MateriaSource::getSoruceName( int idx ) const { return this->sourceName[idx]; }
AMateria *MateriaSource::copySource( int idx ) const { AMateria *newOne = source[idx]->clone(); return newOne; }

void MateriaSource::learnMateria( AMateria *am )
{
	if (this->idx == 4)
		std::cout << "No more Materia can be learned..." << std::endl;
	else
	{
		this->source[idx] = am->clone();
		this->sourceName[idx] = am->getType();
		idx++;
	}
}

AMateria *MateriaSource::createMateria( std::string const &type )
{
	int _idx = 0;

	while (this->sourceName[_idx].compare(type) && _idx < 4)
		_idx++;
	
	switch (_idx)
	{
	case 4:
		std::cout << "No such type of Materia..." << std::endl;
		return NULL;
	default:
		AMateria *newOne = this->source[_idx]->clone();
		return newOne;
	}
}