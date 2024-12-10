#include "FragTrap.hpp"

int main()
{
    std::cout << "==== Test: FragTrap Creation ====" << std::endl;
    FragTrap frag1("Fraggy");

    FragTrap frag2;

    FragTrap frag3(frag1);

    std::cout << "\n==== Test: FragTrap Methods ====" << std::endl;
    frag1.attack("Target1");
    frag1.takeDamage(30);
    frag1.beRepaired(20);
    frag1.highFivesGuys();

    std::cout << "\n==== Test: FragTrap Assignment ====" << std::endl;
    frag2 = frag1;

    std::cout << "\n==== Test: Dynamic Allocation ====" << std::endl;
    ClapTrap* dynamicFrag = new FragTrap("DynamicFraggy");
    dynamicFrag->attack("DynamicTarget");
    delete dynamicFrag;

    std::cout << "\n==== Test Finished ====" << std::endl;

    return 0;
}
