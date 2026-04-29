#include "ScavTrap.hpp"

int main()
{
	ClapTrap base("Base");
	ScavTrap a("Alpha");
	ScavTrap b(a);
	ScavTrap c;

	base.attack("dummy target");
	a.attack("training dummy");
	a.guardGate();
	b.attack("copy target");
	c.attack("default target");
	c.guardGate();

	return 0;
}
