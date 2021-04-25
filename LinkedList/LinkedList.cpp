#include "LinkedList.h"
#include <memory>

int main() {
	int data[] = {10,11,12,13,14,15,16,17,18,19,20};

	cout<<"Linked List program has been started"<<endl;
    auto list { make_unique<LinkedList<int>>() };

    for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
    	list->push_back(data[i]);
    }

    list->print();
	return 0;
}