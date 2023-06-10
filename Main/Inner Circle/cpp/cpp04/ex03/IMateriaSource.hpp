/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:19:01 by seojin            #+#    #+#             */
/*   Updated: 2022/11/12 14:28:41 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{

public:

	virtual ~IMateriaSource() {}
	virtual void learnMateria( AMateria *) = 0;
	virtual AMateria *createMateria( std::string const &type ) = 0;


};


#endif

