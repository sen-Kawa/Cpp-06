//#include "../header/ScalarConverter.class.hpp"
#include <iostream>

int arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong amount of arguments" << std::endl;
		return (-1);
	}

	return (1);
}

int parse_string(std::string input)
{
	if (input.empty() == true)
	{
		std::cout << "Invalid empty argument" << std::endl;
		return (-1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (arg_check(argc, argv) == -1)
		return (-1);
	std::string	input = argv[1];
	if (parse_string(input) == -1)
		return (-1);
	// parse string
	return (0);
}

