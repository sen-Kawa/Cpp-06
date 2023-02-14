#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits.h>
#include <ostream>
#include <stdlib.h>

#define TYPE_CHAR "char"
#define TYPE_INT "int"
#define TYPE_FLOAT "float"
#define TYPE_DOUBLE "double"

class ScalarConverter
{
	private:

		static std::string	type;
		static char			theChar;
		static int			theInt;
		static float		theFloat;
		static double		theDouble;

		static int		parseString(std::string toConvert);
		static int		pseudoLiterals(std::string toConvert);
		static void		single(std::string toConvert);
		static void		toChar(std::string toConvert);	
		static void		toFloat(std::string toConvert);	
		static void		toInt(std::string toConvert);	
		static void		toDouble(std::string toConvert);	

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);

	public:

		static int	convert(std::string toConvert);

};

#endif
