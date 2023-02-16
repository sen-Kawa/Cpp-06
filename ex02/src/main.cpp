#include "../header/Base.class.hpp"
#include <cstdlib>
#include <ctime>

//Base *generate(void)
void generate(void)
{
	int	whichObject;

	srand((int)time(NULL));
	whichObject = rand() % 3 + 1;
	std::cout << whichObject << std::endl;
}

int main(void)
{
	generate();
	return (0);
}

