#include "../header/ScalarConverter.class.hpp"

int	ScalarConverter::type = -1;
char	ScalarConverter::theChar = 'c';
int		ScalarConverter::theInt = -1;
float	ScalarConverter::theFloat = 0.0f;
double	ScalarConverter::theDouble = 0.0;

void ScalarConverter::printConversion()
{
	if (theChar != 0)
		std::cout << "Char: Non displayable" << std::endl;
	else
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

		case 1:
			fromInt();
			break ;

		case 2:
			fromFloat();
			break ;

		case 4:
			printPseudos();
			break ;
	}
	return (0);
}

int ScalarConverter::parseString(std::string toConvert)
{
	long double	temp = strtod(toConvert.c_str(), NULL);

	if (toConvert.empty() == true)
	{
		std::cerr << "Invalid empty argument." << std::endl;
		return (-1);
	}
	else if (toConvert.length() == 1 && (single(toConvert) != -1))
		return (type);
	else if (pseudoLiterals(toConvert) == TYPE_PSEUDOS)
		return (type);
	else if ((toConvert.find('.') == std::string::npos) && checkInt(temp) == TYPE_INT)
		return (type);
	else if ((toConvert.find('.') != std::string::npos) && (toConvert.find('f') != std::string::npos) && checkFloat(temp) == TYPE_FLOAT)
		return (type);

	return (0);
}

void ScalarConverter::fromChar()
{
	theInt =  static_cast<int>(theChar);
	theFloat =  static_cast<float>(theChar);
	theDouble =  static_cast<double>(theChar);

	std::cout << "Char: '" << theChar << "'" << std::endl;
	std::cout << "Int: " << theInt << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;
	return ;
}

void ScalarConverter::fromInt()
{
	if (theInt <= 126 && theInt >= 32)
	{
		theChar =  static_cast<char>(theInt);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	else if ((theInt >= 0 && theInt <= 31) || theInt == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;

	theFloat =  static_cast<float>(theInt);
	theDouble =  static_cast<double>(theInt);

	std::cout << "Int: " << theInt << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}

void ScalarConverter::fromFloat()
{
	if (theFloat <= 126 && theFloat >= 32)
	{
		theChar =  static_cast<char>(theFloat);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	else if ((theFloat >= 0 && theFloat <= 31) || theFloat == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;
	if (theFloat > 2147483647.0 || theFloat < -2147483648.0)
		std::cout << "Int: impossible" << std::endl;
	else
	{
		theInt =  static_cast<int>(theFloat);
		std::cout << "Int: " << theInt << std::endl;
	}
	theDouble =  static_cast<double>(theFloat);
	return ;
}

int ScalarConverter::checkInt(long double temp)
{
	if (temp > INT_MAX || temp < INT_MIN)
		return (-1);
	type = TYPE_INT;
	theInt = static_cast<int>(temp);
	return (type);
}

int ScalarConverter::checkFloat(long double temp)
{
	if (abs(temp) > FLT_MAX)
		return (-1);
	type = TYPE_FLOAT;
	theFloat = static_cast<int>(temp);
	return (type);
}

int ScalarConverter::single(std::string toConvert)
{
	if (isdigit(*toConvert.c_str()))
	{
		type = TYPE_INT;
		theInt = atoi(toConvert.c_str());
		return (TYPE_INT);
	}
	else if (isprint(*toConvert.c_str()))
	{
		type = TYPE_CHAR;
		theChar = toConvert[0];
		return (TYPE_CHAR);
	}
	return (-1);
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
		return (TYPE_PSEUDOS);
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
