/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:51:52 by seojin            #+#    #+#             */
/*   Updated: 2022/11/07 21:10:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Constructors & Destructor */
Point::Point() : x(Fixed(0)), y(Fixed(0)) {}
Point::Point( const float x, const float y ) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point( const Point &p ) : x(p.getX()), y(p.getY()) {}
Point::~Point() {}


/* Operator Overloads */
Point &Point::operator=( const Point &p )
{
	if (this != &p)
	{
		// Nothing to be copied...
	}
	return *this;
}

Fixed Point::getX( void ) const { return this->x; }
Fixed Point::getY( void ) const { return this->y; }