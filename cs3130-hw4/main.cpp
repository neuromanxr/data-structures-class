#include <iostream>

/*

CIS 3130 ASSIGNMENT # 4     KELVIN LEE
Binary Trees

*/

using namespace std;

class BinaryTree
{
private:

    struct node
    {
        int key;
        node *left;     // go left
        node *right;    // go right
    };

    node *root; // top of the tree

    void addLeafPrivate(int key, node *ptr);
    node *createLeafPrivate(int key);
    void printPreOrderPrivate(node *ptr);
    void printInOrderPrivate(node *ptr);
    void printPostOrderPrivate(node *ptr);
    node* returnNodePrivate(int key, node *ptr);
    int findSmallestPrivate(node *ptr);
    void removeNodePrivate(int key, node *parent);
    void removeRootMatch();
    void removeMatch(node *parent, node *match, bool left);
    int countAllNodesPrivate(node *ptr);
    int countChildrenPrivate(node *ptr);
    void freeTreePrivate(node *ptr);

public:

    BinaryTree();

    void addLeaf(int key);
    node *createLeaf(int key);  // public interface for createLeaf, calls createLeafPrivate
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    node *returnNode(int key);  // finds a key value and returns it
    int returnRootKey();
    void printChildren(int key);
//    int countChildren(int key);   // not a good child count function
    int countChildren();
    int countAllNodes();
    int findSmallest();
    void removeNode(int key);
    void freeTree();

};

int main()
{
//    int input = 0;
    int treeKeys[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    BinaryTree myTree;

    cout << "Printing the tree in order\nBefore adding numbers\n";
    myTree.printInOrder();
    cout << endl;

    for(int i = 0; i < 20; i++)
    {
        myTree.addLeaf(treeKeys[i]);
    }

    cout << "Printing the tree in pre-order\n";
    myTree.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree.countChildren() << endl;

    cout << "All Nodes Count: " << myTree.countAllNodes() << endl;
    cout << endl;

    myTree.addLeaf(21);
    myTree.removeNode(1);
    myTree.addLeaf(0);
    myTree.removeNode(10);
    myTree.removeNode(11);
    myTree.removeNode(5);
    myTree.removeNode(2);
    myTree.addLeaf(10);
    cout << endl;

    cout << "Printing the tree in pre-order\n";
    myTree.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree.countChildren() << endl;

    cout << "All Nodes Count: " << myTree.countAllNodes() << endl;
    cout << endl;
    myTree.freeTree();

    int treeKeys2[3] = {3, 1, 5};
    BinaryTree myTree2;

    for(int i = 0; i < 3; i++)
    {
        myTree2.addLeaf(treeKeys2[i]);
    }

    cout << "Printing the tree in pre-order\n";
    myTree2.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree2.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree2.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree2.countChildren() << endl;

    cout << "All Nodes Count: " << myTree2.countAllNodes() << endl;
    cout << endl;

    myTree2.removeNode(3);
    myTree2.removeNode(1);
    cout << endl;

    cout << "Printing the tree in pre-order\n";
    myTree2.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree2.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree2.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree2.countChildren() << endl;

    cout << "All Nodes Count: " << myTree2.countAllNodes() << endl;
    cout << endl;
    myTree2.freeTree();

    BinaryTree myTree3;

    cout << "Printing the tree in pre-order\n";
    myTree3.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree3.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree3.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree3.countChildren() << endl;

    cout << "All Nodes Count: " << myTree3.countAllNodes() << endl;
    cout << endl;

    myTree3.removeNode(15);
    myTree3.addLeaf(30);
    myTree3.addLeaf(5);
    myTree3.addLeaf(10);
    myTree3.addLeaf(20);
    myTree3.removeNode(20);
    myTree3.removeNode(10);
    myTree3.removeNode(5);
    myTree3.removeNode(15);
    myTree3.removeNode(30);
    cout << endl;

    cout << "Printing the tree in pre-order\n";
    myTree3.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree3.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree3.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree3.countChildren() << endl;

    cout << "All Nodes Count: " << myTree3.countAllNodes() << endl;
    cout << endl;
    myTree3.freeTree();

    int treeKeys3[1] = {2};
    BinaryTree myTree4;

    for(int i = 0; i < 1; i++)
    {
        myTree4.addLeaf(treeKeys3[i]);
    }

    cout << "Printing the tree in pre-order\n";
    myTree4.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree4.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree4.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree4.countChildren() << endl;

    cout << "All Nodes Count: " << myTree4.countAllNodes() << endl;
    cout << endl;

    myTree4.removeNode(2);
    cout << endl;

    cout << "Printing the tree in pre-order\n";
    myTree4.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree4.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree4.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree4.countChildren() << endl;

    cout << "All Nodes Count: " << myTree4.countAllNodes() << endl;
    cout << endl;
    myTree4.freeTree();

    int treeKeys4[15] = {11, 25, 75, 12, 37, 60, 90, 8, 15, 32, 45, 50, 67, 97, 95};
    BinaryTree myTree5;

    for(int i = 0; i < 15; i++)
    {
        myTree5.addLeaf(treeKeys4[i]);
    }

    cout << "Printing the tree in pre-order\n";
    myTree5.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree5.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree5.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree5.countChildren() << endl;

    cout << "All Nodes Count: " << myTree5.countAllNodes() << endl;
    cout << endl;

    myTree5.removeNode(37);
    myTree5.removeNode(15);
    myTree5.addLeaf(40);
    myTree5.addLeaf(99);
    cout << endl;

    cout << "Printing the tree in pre-order\n";
    myTree5.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree5.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree5.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree5.countChildren() << endl;

    cout << "All Nodes Count: " << myTree5.countAllNodes() << endl;
    cout << endl;
    myTree5.freeTree();

    int treeKeys5[9] = {50, 40, 60, 30, 70, 20, 80, 10, 90};
    BinaryTree myTree6;

    for(int i = 0; i < 9; i++)
    {
        myTree6.addLeaf(treeKeys5[i]);
    }

    cout << "Printing the tree in pre-order\n";
    myTree6.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree6.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree6.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree6.countChildren() << endl;

    cout << "All Nodes Count: " << myTree6.countAllNodes() << endl;
    cout << endl;
    myTree6.freeTree();

    int treeKeys6[5] = {30, 40, 20, 10, 50};
    BinaryTree myTree7;

    for(int i = 0; i < 5; i++)
    {
        myTree7.addLeaf(treeKeys6[i]);
    }

    cout << "Printing the tree in pre-order\n";
    myTree7.printPreOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in order\nAfter adding numbers\n";
    myTree7.printInOrder();
    cout << endl;
    cout << endl;

    cout << "Printing the tree in post-order\n";
    myTree7.printPostOrder();
    cout << endl;

    cout << "Child Count: " << myTree7.countChildren() << endl;

    cout << "All Nodes Count: " << myTree7.countAllNodes() << endl;
    cout << endl;

//    for(int i = 0; i < 16; i++)     // count the children
//    {
//        childCount += myTree.countChildren(treeKeys[i]);
//    }
//    cout << "Child Count: " << childCount << endl;

//    myTree.printChildren(myTree.returnRootKey());   // print children of root
//    cout << endl;
//
//    for(int i = 0; i < 16; i++)     // print all the children
//    {
//        myTree.printChildren(treeKeys[i]);
//        cout << endl;
//    }

//    // find smallest value in tree
//    cout << "The smallest value in the tree is " << myTree.findSmallest() << endl;

//    cout << "Enter a key value to delete. Enter -1 to stop the process.\n";
//    while(input != -1)
//    {
//        cout << "Delete Node: ";
//        cin >> input;
//        {
//            if(input != -1)
//            {
//                cout << endl;
//                myTree.removeNode(input);
//                myTree.printInOrder();
//                cout << endl;
//            }
//        }
//    }

    return 0;
}

BinaryTree::BinaryTree()   // constructor
{
    root = NULL;    // make sure root pointing to null when initialized
}

BinaryTree::node *BinaryTree::createLeafPrivate(int key)
{
    node *n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

BinaryTree::node *BinaryTree::createLeaf(int key)
{
    return createLeafPrivate(key);
}

void BinaryTree::addLeaf(int key)
{
    addLeafPrivate(key, root);
}


void BinaryTree::addLeafPrivate(int key, node *ptr)
{
    if(root == NULL)    // is tree empty?
    {
        root = createLeaf(key);
    }
    else if(key < ptr->key)
    {
        if(ptr->left != NULL)   // is left pointer pointing to anything?
        {
            addLeafPrivate(key, ptr->left);     // recursive
        }
        else
        {
            ptr->left = createLeaf(key);
        }
    }
    else if(key > ptr->key)
    {
        if(ptr->right != NULL)   // is right pointer pointing to anything?
        {
            addLeafPrivate(key, ptr->right);    // yes, then recursive
        }
        else
        {
            ptr->right = createLeaf(key);   // add new leaf to tree
        }
    }
    else    // key equal to an existing key
    {
        cout << "The key " << key << " has already been added to the tree." << endl;
    }
}

void BinaryTree::printPreOrder()
{
    printPreOrderPrivate(root);
}

void BinaryTree::printPreOrderPrivate(node *ptr)
{
    if(root != NULL)
    {
        cout << ptr->key << " ";    // print the root key
        if(ptr->left != NULL)   // go left
        {
            printPreOrderPrivate(ptr->left);
        }
        if(ptr->right != NULL)  // go right
        {
            printPreOrderPrivate(ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty." << endl;
    }
}

void BinaryTree::printInOrder()
{
    printInOrderPrivate(root);
}

void BinaryTree::printInOrderPrivate(node *ptr)
{
    if(root != NULL)
    {
        if(ptr->left != NULL)   // go left part
        {
            printInOrderPrivate(ptr->left);
        }
        cout << ptr->key << " ";    // print the key
        if(ptr->right != NULL)  // go right part
        {
            printInOrderPrivate(ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty." << endl;
    }
}

void BinaryTree::printPostOrder()
{
    printPostOrderPrivate(root);
}

void BinaryTree::printPostOrderPrivate(node *ptr)
{
    if(root != NULL)
    {
        if(ptr->left != NULL)   // go left
        {
            printPostOrderPrivate(ptr->left);
        }
        if(ptr->right != NULL)  // go right
        {
            printPostOrderPrivate(ptr->right);
        }
        cout << ptr->key << " ";    // print the root key
    }
    else
    {
        cout << "The tree is empty." << endl;
    }
}

BinaryTree::node *BinaryTree::returnNode(int key)
{
    return returnNodePrivate(key, root);
}

BinaryTree::node* BinaryTree::returnNodePrivate(int key, node *ptr)
{
    if(ptr != NULL)
    {
        if(ptr->key == key) // is the key I'm looking for here?
        {
            return ptr;     // pointing to correct node
        }
        else
        {
            if(key < ptr->key)  // go left
            {
                return returnNodePrivate(key, ptr->left);
            }
            else
            {
                return returnNodePrivate(key, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int BinaryTree::returnRootKey()
{
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return -1000;
    }
}

void BinaryTree::printChildren(int key)
{
    node *ptr = returnNode(key);

    if(ptr != NULL)
    {
        cout << "Parent Node = " << ptr->key << endl;

        if(ptr->left == NULL)     // left child
        {
            cout << "Left Child = NULL\n";
        }
        else
        {
            cout << "Left Child = " << ptr->left->key << endl;
        }
        if(ptr->right == NULL)    // right child
        {
            cout << "Right Child = NULL\n";
        }
        else
        {
            cout << "Right Child = " << ptr->right->key << endl;
        }
    }
    else
    {
        cout << "Key " << key << " is not in the tree.\n";
    }
}

//int BinaryTree::countChildren(int key)
//{
//    node *ptr = returnNode(key);
//    int childCount = 0;
//
//    if(ptr != NULL)
//    {
//        if(ptr->left != NULL)
//        {
//            childCount++;
//        }
//        if(ptr->right != NULL)
//        {
//            childCount++;
//        }
//    }
//    return childCount;
//}

int BinaryTree::countChildren()
{
    return countChildrenPrivate(root);
}

int BinaryTree::countChildrenPrivate(node *ptr)
{
    int childCount = 0;
    if(ptr != NULL)
    {
        if(ptr->left != NULL)
        {
            childCount += countAllNodesPrivate(ptr->left);
        }
        if(ptr->right != NULL)
        {
            childCount += countAllNodesPrivate(ptr->right);
        }
    }
    return childCount;
}

int BinaryTree::countAllNodes()
{
    return countAllNodesPrivate(root);
}

int BinaryTree::countAllNodesPrivate(node *ptr)
{
    int nodeCount = 0;
    if(ptr != NULL)
    {
        nodeCount = 1 + countAllNodesPrivate(ptr->left) + countAllNodesPrivate(ptr->right);
    }

    return nodeCount;
}

int BinaryTree::findSmallest()
{
    return findSmallestPrivate(root);
}

void BinaryTree::freeTree()
{
    freeTreePrivate(root);
}

void BinaryTree::freeTreePrivate(node *ptr)
{
    if(ptr != NULL)
    {
        freeTreePrivate(ptr->left);
        freeTreePrivate(ptr->right);
        delete ptr;
    }
}

int BinaryTree::findSmallestPrivate(node *ptr)
{
    if(root == NULL)
    {
        cout << "The tree is empty\n";
        return -1000;
    }
    else
    {
        if(ptr->left != NULL)   // left side, don't need to look at the right because its largest
        {
            return findSmallestPrivate(ptr->left);
        }
        else
        {
            return ptr->key;
        }
    }
}

void BinaryTree::removeNode(int key)
{
    removeNodePrivate(key, root);
}

void BinaryTree::removeNodePrivate(int key, node *parent)
{
    if(root != NULL)
    {
        if(root->key == key)    // if we have a match in the root
        {
            removeRootMatch();
        }
        else    // if root doesn't contain match
        {
            if(key < parent->key && parent->left != NULL)   // if key we want to remove is less than value of current node as long as the left pointer is pointing to something
            {
                parent->left->key == key ?
                removeMatch(parent, parent->left, true) :
                removeNodePrivate(key, parent->left);
            }
            else if(key > parent->key && parent->right != NULL)   // if key we want to remove is less than value of current node as long as the left pointer is pointing to something
            {
                parent->right->key == key ?
                removeMatch(parent, parent->right, false) :
                removeNodePrivate(key, parent->right);
            }
            else    // key looking for is not in the tree
            {
                cout << "The key " << key << " was not found in tree.\n";
            }
        }
    }
    else    // if tree is empty
    {
        cout << "The tree is empty/n";
    }
}

void BinaryTree::removeRootMatch()
{
    if(root != NULL)    // if tree is not empty
    {
        node *delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // case 0 - 0 children
        if(root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }
        // case 1 - 1 child
        else if(root->left == NULL && root->right != NULL)  // child attached to right pointer
        {
            root = root->right;     // new root points to right node
            delPtr->right = NULL;   // disconnect old root from tree
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted." << " The new root contains key " << root->key << endl;

        }
        else if(root->left != NULL && root->right == NULL)  // child attached to left pointer
        {
            root = root->left;     // root points to left
            delPtr->left = NULL;   // disconnect old root from tree
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted." << " The new root contains key " << root->key << endl;

        }

        // case 2 - 2 children
        else
        {
            smallestInRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestInRightSubtree, root);    // remove the smallest node of right subtree
            root->key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
        }
    }
    else
    {
        cout << "Can not remove root. The tree is empty.\n";
    }
}

void BinaryTree::removeMatch(node *parent, node *match, bool left)
{
    if(root != NULL)
    {
        node *delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // case 0 - 0 children
        if(match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed.\n";
        }

        // case 1 - 1 child
        else if(match->left == NULL && match->right != NULL)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed.\n";
        }
        else if(match->left != NULL && match->right == NULL)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed.\n";
        }

        // case 2 - 2 children
        else
        {
            smallestInRightSubtree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;    // overwrite match key
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty.\n";
    }
}


