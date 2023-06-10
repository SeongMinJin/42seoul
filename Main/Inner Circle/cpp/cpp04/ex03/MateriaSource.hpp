/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:27:03 by seojin            #+#    #+#             */
/*   Updated: 2022/11/11 18:46:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
private:
	int idx;
	AMateria *source[4];
	std::string sourceName[4];

	/* getter */
	std::string getSoruceName( int idx ) const;
	AMateria *copySource( int idx ) const;
public:


	/* else */
	void learnMateria( AMateria * );
	AMateria *createMateria( std::string const &type );


	/* initialize */
	MateriaSource();
	MateriaSource( const MateriaSource &m );
	~MateriaSource();
	MateriaSource &operator=( const MateriaSource &m );

};

#endif