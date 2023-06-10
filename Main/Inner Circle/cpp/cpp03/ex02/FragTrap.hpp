/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:44:07 by seojin            #+#    #+#             */
/*   Updated: 2022/11/16 20:45:33 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( const FragTrap &ft );
	~FragTrap();

	FragTrap &operator=( const FragTrap &ft );

	void attack( const std::string &target );
	void highFivesGuys( void ) const;


};

#endif

