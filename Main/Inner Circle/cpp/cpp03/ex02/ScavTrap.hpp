/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:15:13 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 20:45:55 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
	void guardGate( void ) const;
	void attack( const std::string &target );


	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap &ct );
	~ScavTrap();

	ScavTrap &operator=( const ScavTrap &st );

};


#endif
