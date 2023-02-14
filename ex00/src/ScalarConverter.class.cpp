#include "../header/ScalarConverter.class.hpp"

int	ScalarConverter::type = -1;

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
		if (pseudoLiterals(toConvert) == 1)
			// write imposibble in char and int;
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
			ScalarConverter::type = TYPE_INT;
		else
			ScalarConverter::type = TYPE_CHAR;
	}
	return ;
}

int ScalarConverter::pseudoLiterals(std::string toConvert)
{
	std::string	pseudoFloat[3] = {"-inff", "+inff", "nanf"};
	std::string	pseudoDouble[3] = {"-inf", "+inf", "nan"};
	int i;

	for (i = 0; i < 3; i++)	
	{
		if (toConvert.compare(pseudoFloat[i]) == 0)
		{
			ScalarConverter::type = TYPE_FLOAT;
			break ;
		}
		if (toConvert.compare(pseudoDouble[i]) == 0)
		{
			ScalarConverter::type = TYPE_DOUBLE;
			break ;
		}
	}
	if (i < 3)
		return (1);
	return (0);
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
