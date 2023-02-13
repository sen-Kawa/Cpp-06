#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>

class ScalarConverter
{
	private:
	

	public:

		int	getScalarConverter(void) const;

		void	convert(std::string toConvert);

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);
};

#endif

