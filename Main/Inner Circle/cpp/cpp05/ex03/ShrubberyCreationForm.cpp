/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:28:38 by seojin            #+#    #+#             */
/*   Updated: 2022/11/19 11:38:10 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form( "ShrubberyCreationForm", "No_Target", 145, 147) {}
ShrubberyCreationForm::ShrubberyCreationForm( std::string  target ) : Form( "ShrubberyCreationForm", target, 145, 147 ) {}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &scf ) : Form( scf.getName(), scf.getTarget(), scf.getSignGrade(), scf.getExecuteGrade() ) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &scf )
{
	if (this != &scf)
		this->setIsSigned(scf.getIsSigned());
	return *this;
}

void ShrubberyCreationForm::executeForm( void ) const
{
	std::string _fileName;
	_fileName.append(this->getTarget()).append("_shrubbery");


	std::ofstream _outFile;
	_outFile.open(_fileName, std::ofstream::out);
	if (_outFile.fail())
	{
		std::cout << "Error: Not enough storage." << std::endl;
		return ;
	}

	std::string asciiTree = "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____";
	_outFile << asciiTree;

	_outFile.close();
}
