#include "Data.hpp"

void Data::replace( char *filePath, char *target, char *substitute )
{

	std::ifstream	_inFile;
	_inFile.open(filePath, std::ifstream::in);
	if (_inFile.fail())
	{
		std::cout << "Error: Invalid file path." << std::endl;
		return ;
	}


	std::string		_outFileName;
	_outFileName.append(filePath).append(".replace");


	std::ofstream	_outFile;
	_outFile.open(_outFileName, std::ofstream::out);
	if (_outFile.fail())
	{
		std::cout << "Error: Not enough storage." << std::endl;
		return ;
	}


	std::string 	_target;
	_target.append(target);

	std::string		_substitute;
	_substitute.append(substitute);


	char			_c;
	std::string		_line;
	size_t			_pos;
	size_t			_at;
	while (_inFile.get(_c))
		_line.push_back(_c);

	_at = 0;
	while ((_pos = _line.find(_target, _at)) != std::string::npos)
	{
		_line.erase(_pos, _target.length());
		_line.insert(_pos, _substitute);
		_at = _pos + _substitute.length();
	}
	_outFile << _line;


	_inFile.close();
	_outFile.close();
}
