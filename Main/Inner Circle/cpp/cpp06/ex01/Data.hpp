/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:55:12 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 20:07:17 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <cstdint>

typedef struct Data
{
	std::string name;
	int age;
	bool isBoy;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);


#endif
