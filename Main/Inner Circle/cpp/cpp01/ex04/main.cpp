/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:02:06 by seojin            #+#    #+#             */
/*   Updated: 2022/11/08 19:43:06 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Error: Invalid Arguments" << std::endl;
	else
		Data::replace(av[1], av[2], av[3]);
	return 0;
}
