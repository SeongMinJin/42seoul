/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:29:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 20:56:31 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
#define HUMANB

#include <iostream>
#include "Weapon.hpp"

class HumanB
{

private:
	std::string name;
	Weapon		*weapon;


public:
	void		attack( void );
	void		setWeapon( Weapon &weapon );
	std::string getName( void );

	HumanB();
	HumanB( std::string name );
	HumanB( std::string name, std::string type );
	HumanB( std::string name, Weapon weapon );
	~HumanB();

};

#endif