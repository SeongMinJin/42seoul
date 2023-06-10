/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:12:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 17:43:21 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Nobody") {}
Zombie::Zombie( std::string name ) : name(name) {}
Zombie::~Zombie() { std::cout << getName() << " is dead..." << std::endl; }

void Zombie::announce( void ) { std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

std::string Zombie::getName( void ) { return name; }
