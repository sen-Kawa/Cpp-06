#include "../header/Base.class.hpp"
#include "../header/A.class.hpp"
#include "../header/B.class.hpp"
#include "../header/C.class.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int	whichObject;
	Base *base;

	srand((int)time(NULL));
	whichObject = rand() % 3 + 1;
	switch (whichObject)
	{
		case 1:
			base = new A();
			std::cout << "Object A." << std::endl;
			break ;

		case 2:
			base = new B();
			std::cout << "Object B." << std::endl;
			break ;

		case 3:
			base = new C();
			std::cout << "Object C." << std::endl;
			break ;

		default:
			std::cerr << "Error when instantiating." << std::endl;
	}
	std::cout << whichObject << std::endl;
	return (base);
}

int main(void)
{
	generate();
	return (0);
}

