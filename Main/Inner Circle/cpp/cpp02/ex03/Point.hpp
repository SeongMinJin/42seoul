/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:51:50 by seojin            #+#    #+#             */
/*   Updated: 2022/11/13 13:31:32 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{

private:
	const Fixed x;
	const Fixed y;


public:
	Fixed getX( void ) const;
	Fixed getY( void ) const;


	static bool bsp( Point const a, Point const b, Point const c, Point const point);


	Point();
	Point(const float x, const float y );
	Point( const Point &p );
	~Point();

	Point &operator=( const Point &p );

};


#endif
