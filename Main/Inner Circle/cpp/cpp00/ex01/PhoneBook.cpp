/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:22:26 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 14:49:36 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static int get_value(std::string str);

PhoneBook::PhoneBook()
{
	this->oldest = 0;
	this->num = 0;
}

void PhoneBook::showCmd( void )
{
	std::cout << "===================================" << std::endl;
	std::cout << "            COMMNAD LIST           " << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "1. ADD     - add new contact." << std::endl;
	std::cout << "2. SHEARCH - serach contacts in phonebook." << std::endl;
	std::cout << "3. EXIT    - exit this program." << std::endl;
}

void PhoneBook::add( void )
{
	if (oldest == 8)
		oldest = 0;
	this->contacts[oldest].setFirstName();
	this->contacts[oldest].setLastName();
	this->contacts[oldest].setNickName();
	this->contacts[oldest].setPhoneNumber();
	this->contacts[oldest].setDarkestSecret();
	std::cout << "Successfully Saved!" << std::endl;
	this->oldest++;
	if (this->num < 8)
		this->num++;
}

void PhoneBook::search( void )
{
	int idx;
	std::string str;
	std::string firstName;
	std::string lastName;
	std::string nickName;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nick Name" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->num; i++)
	{
		firstName = contacts[i].getFirstName();
		lastName = contacts[i].getLastName();
		nickName = contacts[i].getNickName();
		if (firstName.size() > 10)
		{
			firstName.resize(10);
			firstName.back() = '.';
		}
		if (lastName.size() > 10)
		{
			lastName.resize(10);
			lastName.back() = '.';
		}
		if (nickName.size() > 10)
		{
			nickName.resize(10);
			nickName.back() = '.';
		}
		std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickName << "|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	if (this->num == 0)
	{
		std::cout << "There is No one..." << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Which contact do you want ?(42: quit) : ";
		getline(std::cin, str);
		idx = get_value(str);
		if (str.size() == 0)
			continue;
		else if (idx == 42)
			break ;
		else if (idx > this->num - 1 || idx < 0)
			std::cout << "No such contact." << std::endl;
		else
		{
			std::cout << "|  First Name     : " << this->contacts[idx].getFirstName() << std::endl;
			std::cout << "|  Last Name      : " << this->contacts[idx].getLastName() << std::endl;
			std::cout << "|  Nick Name      : " << this->contacts[idx].getNickName() << std::endl;
			std::cout << "|  Phone Number   : " << this->contacts[idx].getPhoneNumber() << std::endl;
			std::cout << "|  Darkest Secret : " << this->contacts[idx].getDarkestSecret() << std::endl;
			break ;
		}
	}
}

static int get_value( std::string str )
{
	if (str == "0")
		return 0;
	else if (str == "1")
		return 1;
	else if (str == "2")
		return 2;
	else if (str == "3")
		return 3;
	else if (str == "4")
		return 4;
	else if (str == "5")
		return 5;
	else if (str == "6")
		return 6;
	else if (str == "7")
		return 7;
	else if (str == "42")
		return (42);
	else
		return -1;
}
