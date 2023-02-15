#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>
#include <cerrno>
#include <cstring>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <limits.h>
#include <cfloat>
#include <ostream>
#include <stdlib.h>
#include <iomanip>

#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_DOUBLE 3
#define TYPE_PSEUDOS 4

class ScalarConverter
{
	private:

		static int		type;
		static char		theChar;
		static int		theInt;
		static float	theFloat;
		static double	theDouble;

		static int		checkDigit(double temp, std::string toConvert);
		static int		parseString(std::string toConvert);
		static int		pseudoLiterals(std::string toConvert);
		static int		single(std::string toConvert);

		static int		checkInt(double temp, std::string toConvert);	
		static int		checkFloat(double temp, std::string toConvert);
		static int		checkDouble(double temp, std::string toConvert);

		static void		printPseudos(void);

		static void		fromChar(void);
		static void		fromInt(void);
		static void		fromFloat(void);
		static void		fromDouble(void);

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);

	public:

		static void	convert(std::string toConvert);

};

#endif
