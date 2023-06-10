/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:41:53 by seojin            #+#    #+#             */
/*   Updated: 2022/12/07 18:00:04 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	str[0] = "debug";
	str[1] = "info";
	str[2] = "warning";
	str[3] = "error";
	funArr[0] = &Harl::debug;
	funArr[1] = &Harl::info;
	funArr[2] = &Harl::warning;
	funArr[3] = &Harl::error;
}

void Harl::debug( void ) { std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl; }
void Harl::info ( void ) { std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl; }
void Harl::warning( void ) { std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl; }
void Harl::error( void ) { std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; }

void Harl::complain( std::string level )
{
	int idx = 0;

	while (str[idx].compare(level) && idx < 4)
		idx++;

	switch (idx)
	{
	case 4:
		break;
	default:
		(this->*funArr[idx])();
	}
}
