/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:55:43 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 20:44:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{

private:
	std::string name;

public:

	std::string getName( void ) const;
	void attack( const std::string &target );
	void whoAmI( void ) const;

	DiamondTrap();
	DiamondTrap( std::string name );
	DiamondTrap( const DiamondTrap &dt );
	~DiamondTrap();

	DiamondTrap &operator=( const DiamondTrap &dt );
};

#endif
