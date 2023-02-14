#include "../header/ScalarConverter.class.hpp"

int ScalarConverter::parseString(std::string toConvert)
{
	if (toConvert.empty() == true)
	{
		std::cout << "Invalid empty argument." << std::endl;
		return (-1);
	}
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

