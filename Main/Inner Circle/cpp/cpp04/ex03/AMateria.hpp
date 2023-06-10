/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:52:47 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 10:30:09 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Character.hpp"

class AMateria
{
protected:
	const std::string type;

public:
	AMateria( std::string const &type );
	virtual ~AMateria();

	std::string const &getType( void ) const;
	virtual AMateria *clone( void ) const = 0;
	virtual void use( ICharacter &target );

};


class Ice : public AMateria
{
	
public:
	AMateria *clone( void ) const;
	void use( ICharacter &target );

	Ice();
	Ice( const Ice &ice );
	~Ice();
	Ice &operator=( const Ice &ice );
};


class Cure : public AMateria
{

public:
	AMateria *clone( void ) const;
	void use( ICharacter &target );

	Cure();
	Cure( const Cure &cure );
	~Cure();
	Cure &operator=( const Cure &cure );
};



#endif
