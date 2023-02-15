#include "../header/Serializer.class.hpp"
#include <cstdint>

uintptr_t Serializer::serialize(Data *ptr)
{
	return ();
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return ();
}

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
	return ;
}

Serializer &	Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return (*this);
}

Serializer::~Serializer(void)
{
	return ;
}
