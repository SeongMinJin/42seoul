/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:41:37 by seojin            #+#    #+#             */
/*   Updated: 2022/12/07 17:46:37 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{

private:

	std::string str[4];

	void	(Harl::*funArr[4])(void);
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );


public:

	void	complain( std::string level );

	Harl();
};


#endif
