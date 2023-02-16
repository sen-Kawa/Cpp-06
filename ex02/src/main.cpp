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
}

int main(void)
{
	generate();
	return (0);
}

