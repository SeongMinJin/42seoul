/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:29 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 12:41:28 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{

protected:
	std::string name;
	int hitPoint;
	int energyPoint;
	int attackDamage;

public:

	std::string getName( void ) const;
	int getHitPoint( void ) const;
	int getEnergyPoint( void ) const;
	int getAttackDamage( void ) const;

	ClapTrap();
	ClapTrap( std::string name );
	ClapTrap( std::string name, int hitPoint, int nenergyPoint, int attackDamage );
	ClapTrap( const ClapTrap &ct );
	~ClapTrap();

	ClapTrap &operator=( const ClapTrap &ct );

	void attack( const std::string &target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

};


#endif
