/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:37:27 by seojin            #+#    #+#             */
/*   Updated: 2022/11/17 12:01:20 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

private:
	std::string ideas[100];

public:
	std::string getIdea( int idx ) const ;
	void setIdea( int idx, std::string idea );

	Brain();
	Brain( const Brain &b );
	~Brain();
	Brain &operator=( const Brain &b );

};

#endif