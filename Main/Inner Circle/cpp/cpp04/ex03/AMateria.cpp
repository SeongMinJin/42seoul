/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:29:14 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:55:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* for AMateria */
AMateria::AMateria( std::string const &type ) : type(type) {}
AMateria::~AMateria() {}
std::string const &AMateria::getType( void ) const { return this->type; }
void AMateria::use( ICharacter &target ) { std::cout << "Nothing to do with " << target.getName() << std::endl; }


/* for Ice */
Ice::Ice() : AMateria( "ice" ) {}
Ice::Ice ( const Ice &ice ) : AMateria( ice.getType() ) {}
Ice::~Ice() {}
Ice &Ice::operator=( const Ice &ice ) { (void)ice; return *this; }

AMateria *Ice::clone( void ) const { AMateria *newOne = new Ice(); return newOne; }
void Ice::use( ICharacter &target ) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }


/* for Cure */
Cure::Cure() : AMateria( "cure" ) {}
Cure::Cure( const Cure &cure ) : AMateria( cure.getType() ) {}
Cure::~Cure() {}
Cure &Cure::operator=( const Cure &cure ) { (void)cure; return *this; }

AMateria *Cure::clone( void ) const { AMateria *newOne = new Cure(); return newOne; }
void Cure::use( ICharacter &target ) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
