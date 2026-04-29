#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap base("Base");
	ScavTrap scav("GateKeeper");
	FragTrap frag("HighFive");
	FragTrap fragCopy(frag);
	FragTrap fragDefault;

	base.attack("dummy target");

	scav.attack("training dummy");
	scav.guardGate();

	frag.attack("boss target");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();

	fragCopy.attack("copy target");
	fragDefault.highFivesGuys();

	return 0;
}
