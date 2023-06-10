/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:57:43 by seojin            #+#    #+#             */
/*   Updated: 2022/11/06 21:02:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl harl;
		std::string level;

		for (size_t i = 0; i < std::strlen(av[1]); i++)
			av[1][i] = std::tolower(av[1][i]);
		level.append(av[1]);
		harl.complain(level);
	}
	return 0;
}