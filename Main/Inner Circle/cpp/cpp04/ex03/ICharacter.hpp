/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:11:32 by seojin            #+#    #+#             */
/*   Updated: 2022/11/12 10:49:13 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter
{

public:
	virtual ~ICharacter() {}
	virtual std::string const &getName( void ) const = 0;
	virtual void equip( AMateria *m ) = 0;
	virtual void unequip( int idx ) = 0;
	virtual void use( int idx, ICharacter &target ) = 0;
};

#endif
