#include "../header/ScalarConverter.class.hpp"

int arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of arguments" << std::endl;
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (!arg_check(argc, argv))
		return (1);
	// parse string
	return (0);
}

