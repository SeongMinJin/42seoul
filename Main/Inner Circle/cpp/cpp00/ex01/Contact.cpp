/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:22:24 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 14:44:03 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setFirstName( void )
{
	std::string str;

	while (!std::cin.eof() && str.size() == 0)
	{
		std::cout << "First Name     : ";
		getline(std::cin, str);
	}
	this->firstName = str;
}

void Contact::setLastName( void )
{
	std::string str;

	while (!std::cin.eof() && str.size() == 0)
	{
		std::cout << "Last Name      : ";
		getline(std::cin, str);
	}
	this->lastName = str;
}

void Contact::setNickName( void )
{
	std::string str;

	while (!std::cin.eof() && str.size() == 0)
	{
		std::cout << "Nick Name      : ";
		getline(std::cin, str);
	}
	this->nickName = str;
}

void Contact::setPhoneNumber( void )
{
	std::string str;

	while (!std::cin.eof() && str.size() == 0)
	{
		std::cout << "Phone Number   : ";
		getline(std::cin, str);
	}
	this->phoneNumber = str;
}

void Contact::setDarkestSecret( void )
{
	std::string str;

	while (!std::cin.eof() && str.size() == 0)
	{
		std::cout << "Darkest Secret : ";
		getline(std::cin, str);
	}
	this->darkestSecret = str;
}

std::string Contact::getFirstName( void )
{
	return (this->firstName);
}

std::string Contact::getLastName( void )
{
	return (this->lastName);
}

std::string Contact::getNickName( void )
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber( void )
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret( void )
{
	return (this->darkestSecret);
}
