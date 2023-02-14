#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits.h>

#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_DOUBLE 3

class ScalarConverter
{
	private:

		static int		type;

		static int		parseString(std::string toConvert);
		static void		pseudoLiterals(std::string toConvert);
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

