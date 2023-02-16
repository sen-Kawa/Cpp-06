#include "../header/Base.class.hpp"
#include "../header/A.class.hpp"
#include "../header/B.class.hpp"
#include "../header/C.class.hpp"
#include <cstdlib>
#include <exception>
#include <ctime>

#define YELLOW "\033[2;33m"
#define RED "\033[2;31m"
#define CYAN "\033[2;36m"
#define DEF "\033[0m"

Base *generate(void)
{
	int	whichObject;
	Base *p;

	srand((int)time(NULL));
	whichObject = rand() % 3 + 1;
	std::cout << YELLOW << ">> Generating...\n" << DEF << std::endl;
	switch (whichObject)
	{
		case 1:
			p = new A();
			std::cout << CYAN << "Generated: " << DEF << "Object type A.";
			break ;

		case 2:
			p = new B();
			std::cout << CYAN << "Generated: " << DEF << "Object type B.";
			break ;

		case 3:
			p = new C();
			std::cout << CYAN << "Generated: " << DEF << "Object type C.";
			break ;

		default:
			p = NULL;
			std::cerr << RED << "Error when instantiating." << DEF;
	}
	std::cout  << std::endl << std::endl;
	return (p);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	
	std::cout << YELLOW << ">> Identifying from pointer...\n" << DEF << std::endl;
	if (a != NULL)
		std::cout << CYAN << "Identified: " << DEF << "Object type A.";
	if (b != NULL)
		std::cout << CYAN << "Identified: " << DEF << "Object type B.";
	if (c != NULL)
		std::cout << CYAN << "Identified: " << DEF << "Object type C.";
	std::cout  << std::endl << std::endl;
	return ;
}

void identify(Base &p)
{
	std::cout << YELLOW << ">> Identifying from reference...\n" << DEF << std::endl;

	try
	{
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << CYAN << "Identified: " << DEF << "Object type A.";
	}
	catch (std::exception &bc)
	{
		std::cerr << RED << bc.what() << DEF;
	}
	std::cout  << std::endl << std::endl;
	return ;
}

int main(void)
{
	std::cout << CYAN << "Identify real type ex02\n" << DEF << std::endl;
	Base *p = generate();
	identify(p);
	identify(*p);
	return (0);
}
