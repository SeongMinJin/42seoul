/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:09:34 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 18:07:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{

private:
	std::string name;

public:
	void 		announce( void );
	void 		randomChump( std::string name );
	Zombie		*newZombie( std::string name );
	std::string	getName( void );

	Zombie();
	Zombie( std::string name);
	~Zombie();

};

#endif