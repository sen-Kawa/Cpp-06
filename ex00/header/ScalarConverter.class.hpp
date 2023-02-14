#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>

class ScalarConverter
{
	private:

		std::string	toConvert;
	
		int		parseString(std::string toConvert);
		void	toChar(std::string toConvert);	
		void	toFloat(std::string toConvert);	
		void	toInt(std::string toConvert);	
		void	toDouble(std::string toConvert);	

	public:

		int	convert(void);

		ScalarConverter(void);
		ScalarConverter(std::string toConvert);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);
};

#endif

