/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:22:16 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 14:48:59 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string str;
	PhoneBook phoneBook;

	phoneBook.showCmd();
	while (str != "EXIT" && !std::cin.eof())
	{
		std::cout << "May I Help You ? > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			phoneBook.add();
		else if (str == "SEARCH")
			phoneBook.search();
		else if (str == "?")
			phoneBook.showCmd();
		else
			continue;
	}
	std::cout << "exited..." << std::endl;
	return (0);
}
