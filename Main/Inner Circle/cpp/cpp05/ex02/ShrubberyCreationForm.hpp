/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:28:34 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:36:00 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"


class ShrubberyCreationForm : public Form
{
private:
	virtual void executeForm( void ) const;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm &scf );
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &scf );
};

#endif
