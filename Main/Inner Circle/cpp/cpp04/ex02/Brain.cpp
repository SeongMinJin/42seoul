/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:49:59 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:13:46 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Coding...";
	std::cout << "Brain default constructor is called." << std::endl;
}
Brain::Brain( const Brain &b )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.getIdea(i);
	std::cout << "Brain copy consturctor is called." << std::endl;
}
Brain::~Brain() { std::cout << "Brain destructor is called." << std::endl; }
Brain &Brain::operator=( const Brain &b )
{
	if (this != &b)
	{
		std::cout << "Brain copy assignment is called." << std::endl;
		for (int i = 0; i < 100; i++)
			this->ideas[i] = b.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea( int idx ) const
{
	if (idx < 0 || idx > 100)
		return "Error: Invalid brain index.";
	else
		return this->ideas[idx];
}

void Brain::setIdea( int idx, std::string idea )
{
	if (idx < 0 || idx > 100)
		std::cout << "Error: Invalid brain index." << std::endl;
	else
		this->ideas[idx] = idea;
}
