#include "../header/ScalarConverter.class.hpp"


int ScalarConverter::convert(std::string toConvert)
{
	if (parseString(toConvert) == -1)
		return (-1);

	return (0);
}

int ScalarConverter::parseString(std::string toConvert)
{
	if (toConvert.empty() == true)
	{
		std::cout << "Invalid empty argument." << std::endl;
		return (-1);
	}
	else if (toConvert.length() == 1)
		single(toConvert);
	else
	{
		pseudoLiterals(toConvert);
	}
	return (0);
}


void ScalarConverter::toChar(std::string toConvert)
{
	int	i = atoi(toConvert.c_str());

	if (isprint(i))
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "Char: " << "Non displayable" << std::endl;
	return ;
}

void ScalarConverter::toInt(std::string toConvert)
{
	int	i = atoi(toConvert.c_str());

	if (i < INT_MAX && i > INT_MIN)
		std::cout << "Int: " << static_cast<int>(i) << std::endl;
	else
		std::cout << "Int: " << "Non displayable" << std::endl;
	return ;
}

void ScalarConverter::single(std::string toConvert)
{
	int	i = atoi(toConvert.c_str());

	if (isprint(i))
	{
		if (isdigit(i))
			type = TYPE_INT;
		else
			type = TYPE_CHAR;
	}
	return ;
}

void ScalarConverter::pseudoLiterals(std::string toConvert)
{
	//compare with pseudo literals
	//make array with possibilities?
	//

	return ;
}

ScalarConverter::ScalarConverter(void)
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
