/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:11:43 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 20:58:53 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{

private:
	std::string	type;

public:
	std::string getType( void );
	void		setType( std::string type );


	Weapon();
	Weapon( std::string type );
	~Weapon();

};

#endif
