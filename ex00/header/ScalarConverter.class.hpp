#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits.h>
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

		static int		parseString(std::string toConvert);
		static int		pseudoLiterals(std::string toConvert);
		static int		single(std::string toConvert);
		static int		checkInt(double temp);	

		static void		printPseudos(void);
		static void		printConversion(void);

		static void		toChar(std::string toConvert);	
		static void		toFloat(std::string toConvert);	
		static void		toInt(std::string toConvert);	
		static void		toDouble(std::string toConvert);	

		static void		fromChar(void);
		static void		fromInt(void);

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);

	public:

		static int	convert(std::string toConvert);

};

#endif
