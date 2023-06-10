/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:53:59 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 12:56:39 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
	Data data;

	data.name = "seojin";
	data.age = 16;
	data.isBoy = true;

	std::cout << "data's memory address :" << &data << std::endl;
	std::cout << "data's memory address :" << deserialize(serialize(&data)) << std::endl;
	std::cout << "data's unsigned int v :" << serialize(&data) << std::endl;
	return 0;
}

