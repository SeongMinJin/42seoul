/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:54:58 by seojin            #+#    #+#             */
/*   Updated: 2022/12/14 11:42:50 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{

private:
	unsigned int len;
	T *arr;

public:

	unsigned int size( void ) const { return this->len; }

	Array() : len(0), arr(NULL)
	{
		std::cout << "Default constructor is called." << std::endl;
	}
	Array( unsigned int n ) : len(n)
	{
		std::cout << "Unsigned int constructor is called." << std::endl;
		arr = new T[n];
	}
	Array( const Array &a ) : len(a.size())
	{
		std::cout << "Copy constructor is called." << std::endl;
		if (a.size() == 0)
			arr = NULL;
		else
		{
			arr = new T[a.size()];
			for (unsigned int i = 0; i < a.size(); i++)
				arr[i] = a.arr[i];
		}
	}
	~Array()
	{
		std::cout << "Destructor is called." << std::endl;
		if (arr)
			delete [] arr;
	}

	Array &operator=( const Array &a )
	{
		if (this != &a)
		{
			if (arr)
				delete [] arr;

			this->len = a.size();
			if (a.size() == 0)
				arr = NULL;
			else
			{
				arr = new T[a.size()];
				for (unsigned int i = 0; i < a.size(); i++)
					arr[i] = a.arr[i];
			}
		}
		return *this;
	}

	T &operator[]( unsigned int idx ) const
	{
		try
		{
			if (len < idx || len == idx || !arr)
				throw Array<T>::Error();
		}
		catch(const std::exception& e)
		{
			throw Array<T>::Error();
		}
		return arr[idx];
	}

	class Error : public std::exception
	{
		virtual const char *what( void ) const throw () { return "Invaild Index."; }
	};

};


#endif

