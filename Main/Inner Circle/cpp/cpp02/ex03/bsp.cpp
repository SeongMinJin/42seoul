/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:51:54 by seojin            #+#    #+#             */
/*   Updated: 2022/11/12 15:53:16 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed getArea( Point const a, Point const b, Point const c);

/* public member functions */
bool Point::bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed abcArea = getArea(a, b, c);
	Fixed pabArea = getArea(point, a, b);
	Fixed pbcArea = getArea(point, b, c);
	Fixed pcaArea = getArea(point, c, a);

	if (abcArea.toFloat() == 0)
		return false;
	else if (pabArea.toFloat() == 0)
		return false;
	else if (pbcArea.toFloat() == 0)
		return false;
	else if (pcaArea.toFloat() == 0)
		return false;
	else if ((pabArea + pbcArea + pcaArea) != abcArea)
		return false;
	else
		return true;
}

Fixed getArea( Point const a, Point const b, Point const c)
{
	Fixed ax, ay, bx, by, cx, cy, formA, formB;

	ax = a.getX();
	ay = a.getY();
	bx = b.getX();
	by = b.getY();
	cx = c.getX();
	cy = c.getY();

	formA = ((ax * by) + (bx * cy) + (cx * ay));
	formB = ((bx * ay) + (cx * by) + (ax * cy));

	if (formA > formB)
		return (formA - formB);
	else
		return (formB - formA);
}
