#include "BinarySearchTree.h"

int BinarySearchTreeTest()
{
	int a[] = { 1,2,6,3,2,7 };

	BinarySearchTree<int> bst1;

	bst1.InsertNode (&a[0]);
	bst1.InsertNode (&a[1]);
	bst1.InsertNode (&a[2]);
	bst1.InsertNode (&a[3]);
	bst1.InsertNode (&a[4]);
	bst1.InsertNode (&a[5]);


	bst1.FindNode(&a[3]);
	printf("%p\n",bst1.FindNode(&a[5]));
	bst1.MiddleOrder();
	bst1.RemoveNode(&a[2]);
	bst1.MiddleOrder();

	return 0;
}