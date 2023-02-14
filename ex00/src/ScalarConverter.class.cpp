#include "../header/ScalarConverter.class.hpp"
#include <cctype>
#include <cstdlib>

void ScalarConverter::toChar(std::string toConvert)
{
	int	i = atoi(toConvert.c_str());

	std::cout << i << std::endl;
	if (isprint(i))
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "Char: " << "Non displayable" << std::endl;
	return ;
}

int ScalarConverter::parseString(std::string toConvert)
{
	if (toConvert.empty() == true)
	{
		std::cout << "Invalid empty argument." << std::endl;
		return (-1);
	}
	toChar(toConvert);
	return (0);
}

int ScalarConverter::convert(void)
{
	if (parseString(toConvert) == -1)
		return (-1);

	return (0);
}

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(std::string toConvert) : toConvert(toConvert)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	return ;
}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

