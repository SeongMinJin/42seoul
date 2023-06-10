/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:28:36 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:36:11 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
private:
	virtual void executeForm( void ) const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm &rrf );
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=( const RobotomyRequestForm &rrf );
};


#endif
