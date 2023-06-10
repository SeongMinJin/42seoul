/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:56 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 17:48:09 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

int main()
{
	Base *p = Base::generate();
	Base &refP = *p;


	Base::identify(p);
	Base::identify(refP);

	delete p;
	return 0;
}
