#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

#include <iostream>

class Serializer
{
	private:

		Serializer(void);
		Serializer(Serializer const &src);
		Serializer&	operator=(Serializer const &assign);
		~Serializer(void);

	public:

		int	getSerializer(void) const;

};

#endif
