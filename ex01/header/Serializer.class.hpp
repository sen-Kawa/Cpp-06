#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:

		Serializer(void);
		Serializer(Serializer const &src);
		Serializer&	operator=(Serializer const &assign);
		~Serializer(void);

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
