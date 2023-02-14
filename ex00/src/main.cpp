#include "../header/ScalarConverter.class.hpp"

int arg_check(int argc)
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of arguments" << std::endl;
		return (-1);
	}

	return (1);
}

int main(int argc, char **argv)
{
	if (arg_check(argc) == -1)
		return (-1);

	ScalarConverter::convert(argv[1]);

	return (0);
}

