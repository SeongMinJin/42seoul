/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:46:57 by seojin            #+#    #+#             */
/*   Updated: 2022/11/23 07:41:29 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T t, int N)
{
	typename T::iterator tmp = std::find(t.begin(), t.end(), N);

	if (tmp == t.end())
		throw std::exception();
	return tmp;
}

#endif