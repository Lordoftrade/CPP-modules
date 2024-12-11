#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

    std::cout << "==== Test: Object Creation ====" << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2;
    ScavTrap scav3(scav1);

    std::cout << "\n==== Test: Attacking ====" << std::endl;
    scav1.attack("Enemy1");
    scav1.attack("Enemy2");

    for (int i = 0; i < 50; ++i) {
        scav1.attack("Enemy");
    }
    scav1.attack("Enemy3");

    scav1.takeDamage(100);
    scav1.attack("Enemy4");

    std::cout << "\n==== Test: Taking Damage ====" << std::endl;
    scav2.takeDamage(30);
    scav2.takeDamage(100);
    scav2.takeDamage(10);

    std::cout << "\n==== Test: Repairing ====" << std::endl;
    //ScavTrap scav3(scav1);
    scav3.beRepaired(20);
    scav3.beRepaired(5);
    scav3.takeDamage(50);
    scav3.beRepaired(10);

    for (int i = 0; i < 50; ++i)
    {
        scav3.attack("Dummy");
    }
    scav3.beRepaired(10);

    std::cout << "\n==== Test: Guard Gate ====" << std::endl;
    scav3.guardGate();

    std::cout << "\n==== Test: Copy and Assignment ====" << std::endl;
    ScavTrap scav4("CopyTarget");
    scav4 = scav3;
    scav4.attack("Enemy5");
    ScavTrap scav5(scav4);
    scav5.attack("Enemy6");

    std::cout << "\n==== Test: Dynamic Allocation ====" << std::endl;
    ClapTrap* dynamicScav = new ScavTrap("DynamicGuardian");
    dynamicScav->attack("DynamicEnemy");
    delete dynamicScav;

    std::cout << "\n==== Test Finished ====" << std::endl;

    return 0;
}
