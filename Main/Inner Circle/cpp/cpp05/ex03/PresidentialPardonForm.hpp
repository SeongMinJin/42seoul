/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:28:36 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:35:34 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	virtual void executeForm( void ) const;

public:
	PresidentialPardonForm();
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm &ppf );
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=( const PresidentialPardonForm &ppf );
};

#endif
