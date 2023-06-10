/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:14:33 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 20:59:00 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("None") {}
Weapon::Weapon( std::string type ) : type(type) { std::cout << getType() << " is spawned." << std::endl; }
Weapon::~Weapon() { std::cout << getType() << " is broken.." << std::endl; }

std::string Weapon::getType( void )
{
	const std::string &refType = type;

	return (refType);
}

void Weapon::setType( std::string type ) { this->type = type; }
