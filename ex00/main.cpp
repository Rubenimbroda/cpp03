#include "ClapTrap.hpp"

int main()
{
	ClapTrap alpha("Alpha");
	ClapTrap beta(alpha);

	alpha.attack("a training dummy");
	alpha.takeDamage(3);
	alpha.beRepaired(2);

	beta.attack("another target");
	beta.takeDamage(50);
	beta.attack("target after death");
	beta.beRepaired(5);

	ClapTrap gamma;
	gamma.attack("empty target");

	return 0;
}
