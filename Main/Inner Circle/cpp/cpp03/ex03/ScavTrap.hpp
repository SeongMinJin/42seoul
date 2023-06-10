/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:15:13 by seojin            #+#    #+#             */
/*   Updated: 2022/12/13 13:11:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
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
