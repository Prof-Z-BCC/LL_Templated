#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.display();

    list.deleteValue(10);
    list.display();

    std::cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 30: " << (list.search(30) ? "Found" : "Not Found") << std::endl;

    return 0;
}
