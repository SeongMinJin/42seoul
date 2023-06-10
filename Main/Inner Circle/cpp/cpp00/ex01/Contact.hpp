/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:22:22 by seojin            #+#    #+#             */
/*   Updated: 2022/11/05 14:47:22 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	void setFirstName( void );
	void setLastName( void );
	void setNickName( void );
	void setPhoneNumber( void );
	void setDarkestSecret( void );

	std::string getFirstName( void );
	std::string getLastName( void );
	std::string getNickName( void );
	std::string getPhoneNumber( void );
	std::string getDarkestSecret( void );
};

#endif