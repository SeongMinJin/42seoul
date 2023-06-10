/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:29:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 20:58:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{

private:
	std::string	name;
	Weapon		&weapon;


public:
	void		attack( void );
	std::string getName( void );

	HumanA( std::string name, Weapon &weapon);
	~HumanA();
};

#endif