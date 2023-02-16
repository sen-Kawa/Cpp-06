#include "../header/Base.class.hpp"
#include "../header/A.class.hpp"
#include "../header/B.class.hpp"
#include "../header/C.class.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int	whichObject;
	Base *p;

	srand((int)time(NULL));
	whichObject = rand() % 3 + 1;
	std::cout << "Generating...\n" << std::endl;
	switch (whichObject)
	{
		case 1:
			p = new A();
			std::cout << "Object A." << std::endl;
			break ;

		case 2:
			p = new B();
			std::cout << "Object B." << std::endl;
			break ;

		case 3:
			p = new C();
			std::cout << "Object C." << std::endl;
			break ;

		default:
			p = NULL;
			std::cerr << "Error when instantiating." << std::endl;
	}
	return (p);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	
	std::cout << "Identifying...\n" << std::endl;
	if (a != NULL)
		std::cout << "Identified: Object type A." << std::endl;
	if (b != NULL)
		std::cout << "Identified: Object type B." << std::endl;
	if (c != NULL)
		std::cout << "Identified: Object type C." << std::endl;
}

int main(void)
{
	Base *p = generate();
	identify(p);
	return (0);
}

