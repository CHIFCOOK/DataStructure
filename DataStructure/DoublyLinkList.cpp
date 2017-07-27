
#include "DoublyLinkList.h"

int DoublyLinkListTest()
{
	int a[4] = { 1,2,3,4 };

	//List<char> * list1 = new List<char>;
	//list1->add_back(&a[0]);
	//list1->add_back(&a[1]);
	//list1->add_back(&a[2]);
	//list1->add_back(&a[3]);

	List<int> list1;
	list1.AddBack(&a[0]);
	list1.AddBack(&a[1]);
	list1.AddBack(&a[2]);
	list1.AddBack(&a[3]);

	list1.AddByIndex(1, &a[0]);

	list1.Traversal(true);
	cout << endl;
	list1.Traversal(false);
	cout << endl;


	//delete list1;
	//list1 = nullptr;

	return 0;
}

