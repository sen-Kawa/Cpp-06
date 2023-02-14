#include "../header/ScalarConverter.class.hpp"
#include <cstdlib>
#include <iomanip>

int	ScalarConverter::type = -1;
char	ScalarConverter::theChar = 'c';
int		ScalarConverter::theInt = -1;
float	ScalarConverter::theFloat = 0.0f;
double	ScalarConverter::theDouble = 0.0;

void ScalarConverter::printConversion()
{
	std::cout << "Char: '" << theChar << "'" << std::endl;
	std::cout << "Int: " << theInt << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;
	return ;
}

void ScalarConverter::printPseudos()
{
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;
	return ;
}

int ScalarConverter::convert(std::string toConvert)
{
	if (parseString(toConvert)== -1)
		return (-1);
	switch(type)
	{
		case 0:
			fromChar();
			break ;

		case 4:
			printPseudos();
			break ;
	}
	return (0);
}

int ScalarConverter::parseString(std::string toConvert)
{
	if (toConvert.empty() == true)
	{
		std::cerr << "Invalid empty argument." << std::endl;
		return (-1);
	}
	else if (toConvert.length() == 1)
		single(toConvert);
	else
		pseudoLiterals(toConvert);
	return (0);
}

void ScalarConverter::fromChar()
{
	theInt =  static_cast<int>(theChar);
	theFloat =  static_cast<float>(theChar);
	theDouble =  static_cast<double>(theChar);
	printConversion();
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
	if (isdigit(*toConvert.c_str()))
	{
		type = TYPE_INT;
		theInt = atoi(toConvert.c_str());
	}
	else if (isprint(*toConvert.c_str()))
	{
		type = TYPE_CHAR;
		theChar = toConvert[0];
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
			break ;
		if (toConvert.compare(pseudoDouble[i]) == 0)
			break ;
	}
	if (i < 3)
	{
		theFloat = strtof(pseudoFloat[i].c_str(), NULL);
		theDouble = strtod(pseudoDouble[i].c_str(), NULL);
		type = TYPE_PSEUDOS;
	}
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
