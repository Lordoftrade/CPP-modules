
#include "MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }


int main() {
    std::cout << "MutantStack std::deque" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "MutantStack elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

	std::cout << "------------------------" << std::endl;
    std::cout << "MutantStack std::vector:" << std::endl;
    MutantStack<int, std::vector<int> > mstackVec;
    mstackVec.push(5);
    mstackVec.push(17);
	std::cout << "Top: " << mstackVec.top() << std::endl;
	mstackVec.pop();
	std::cout << "Size: " << mstackVec.size() << std::endl;
    mstackVec.push(3);
	mstackVec.push(5);
	mstackVec.push(737);
	mstackVec.push(0);

    for (MutantStack<int, std::vector<int> >::iterator it = mstackVec.begin(); it != mstackVec.end(); ++it) {
        std::cout << *it << std::endl;;
    }
    std::cout << std::endl;

	std::cout << "------------------------" << std::endl;
    std::cout << "std::list:" << std::endl;
    std::list<int> listStack;
    listStack.push_back(5);
    listStack.push_back(17);

	std::cout << "Top: " << listStack.back() << std::endl;
	listStack.pop_back();
	std::cout << "Size: " << listStack.size() << std::endl;
    listStack.push_back(3);
	listStack.push_back(35);
	listStack.push_back(737);
	listStack.push_back(0);

    for (std::list<int>::iterator it = listStack.begin(); it != listStack.end(); ++it) {
        std::cout << *it << std::endl;
    }




	std::cout << "📌 MutantStack (std::list)" << std::endl;
    MutantStack<int, std::list<int> > mstackList;
    mstackList.push(100);
    mstackList.push(200);
    mstackList.push(300);
    std::cout << "Top: " << mstackList.top() << std::endl;
    mstackList.pop();
    std::cout << "Size: " << mstackList.size() << std::endl;
    mstackList.push(400);
    mstackList.push(500);
    mstackList.push(600);

    std::cout << "MutantStack elements:" << std::endl;
    for (MutantStack<int, std::list<int> >::iterator it = mstackList.begin(); it != mstackList.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "------------------------" << std::endl;


    return 0;
}
