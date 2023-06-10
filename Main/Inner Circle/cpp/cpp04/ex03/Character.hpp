/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:24:52 by seojin            #+#    #+#             */
/*   Updated: 2022/11/12 14:26:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{

private:
	const std::string name;
	AMateria *slot[4];

public:

	std::string const &getName( void ) const;
	void equip( AMateria *m );
	void unequip( int idx );
	void use( int idx, ICharacter &target );

	Character();
	Character( std::string name );
	Character( const Character &c );
	~Character();
	Character &operator=( const Character &c );

};


#endif