#include "../header/Serializer.class.hpp"
#include "../header/Data.hpp"
#include <stdint.h>

int main(void)
{
	Data	*obj = new Data();
	std::cout << "> Data object created\n" << std::endl;

	obj->galaxyMorpholophy = "Elliptical galaxy";
	std::cout << "Data member: " << obj->galaxyMorpholophy << std::endl;
	std::cout << "Address: " << obj << std::endl;

	uintptr_t	raw = Serializer::serialize(obj);
	std::cout << "\n> Serialized: " << raw << std::endl;

	obj = Serializer::deserialize(raw);
	std::cout << "\n> After deserialize: " << std::endl;

	std::cout << "\nData member: " << obj->galaxyMorpholophy << std::endl;
	std::cout << "Address: " << obj << std::endl;

	delete obj;
	return (0);
}

