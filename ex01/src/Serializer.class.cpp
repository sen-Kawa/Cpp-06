#include "../header/Serializer.class.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
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
