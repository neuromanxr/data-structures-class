#include <iostream>
#include <vector>

/*

CIS 3130 ASSIGNMENT # 5     KELVIN LEE
More Binary Trees

*/

using namespace std;

class BinaryTree
{
private:

    struct node
    {
        string key;
        node *left;     // go left
        node *right;    // go right
        vector<node *>children;
    };

    node *root; // top of the tree
    node *temp;

    void addLeafPrivate(string key, node *ptr);
    node *createLeafPrivate(string key);
    void printPreOrderPrivate(node *ptr);
    void printInOrderPrivate(node *ptr);
    void printPostOrderPrivate(node *ptr);
    node* returnNodePrivate(string key, node *ptr);
    string findSmallestPrivate(node *ptr);
    void removeNodePrivate(string key, node *parent);
    void removeRootMatch();
    void removeMatch(node *parent, node *match, bool left);
    int countAllNodesPrivate(node *ptr);
    int countChildrenPrivate(node *ptr);
    void freeTreePrivate(node *ptr);
    void addNodePrivate(string key, vector<node *>children, node *ptr);

public:

    BinaryTree();

    void addLeaf(string key);
    node *createLeaf(string key);  // public interface for createLeaf, calls createLeafPrivate
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    node *returnNode(string key);  // finds a key value and returns it
    string returnRootKey();
    void printChildren(string key);
    int countChildren();
    int countAllNodes();
    string findSmallest();
    void removeNode(string key);
    void freeTree();
    void addNode(string key, vector<node *>child);

};

int main()
{
    string familyMembers[9] = {"Jones Parent", "Bob", "Dan Sibling", "Alex"};

    BinaryTree familyTree;

    for(int i = 0; i < 4; i++)
    {
        familyTree.addLeaf(familyMembers[i]);
    }

    cout << "Who is the father of Bob?" << endl;
    cout << familyTree.returnRootKey() << endl;

    cout << "Who are all the sons of Jones?" << endl;
    familyTree.printPreOrder();     // modified, not preorder
    cout << endl;

    cout << "Who are all the brothers of Bob?" << endl;
    familyTree.printInOrder();      // modified, not inorder
    cout << endl;

    cout << endl;
    familyTree.printChildren("Jones Parent");
    familyTree.printChildren("Bob");
    cout << endl;


    return 0;
}

BinaryTree::BinaryTree()   // constructor
{
    root = NULL;    // make sure root pointing to null when initialized
}

BinaryTree::node *BinaryTree::createLeafPrivate(string key)
{
    node *n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

BinaryTree::node *BinaryTree::createLeaf(string key)
{
    return createLeafPrivate(key);
}

void BinaryTree::addNode(string key, vector<node *>child)
{
    addNodePrivate(key, child, root);
}

void BinaryTree::addNodePrivate(string key, vector<node *>children, node *ptr)
{
    createLeafPrivate(key);
}

void BinaryTree::addLeaf(string key)
{
    addLeafPrivate(key, root);
}


void BinaryTree::addLeafPrivate(string key, node *ptr)
{
    if(root == NULL)    // is tree empty?
    {
        root = createLeaf(key);
        temp = root;
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
//        cout << ptr->key << " ";    // print the root key
        if(ptr->left != NULL)   // go left
        {
            ptr = ptr->left;
            cout << ptr->key << ", ";
//            printPreOrderPrivate(ptr->left);
        }
        if(ptr->right != NULL)  // go right
        {
            ptr = ptr->right;
            cout << ptr->key << ", ";
//            printPreOrderPrivate(ptr->right);
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
            ptr = ptr->left;
//            printInOrderPrivate(ptr->left);
        }
//        cout << ptr->key << " ";    // print the key
        if(ptr->right != NULL)  // go right part
        {
            ptr = ptr->right;
            cout << ptr->key << ", ";
//            printInOrderPrivate(ptr->right);
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

BinaryTree::node *BinaryTree::returnNode(string key)
{
    return returnNodePrivate(key, root);
}

BinaryTree::node* BinaryTree::returnNodePrivate(string key, node *ptr)
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

string BinaryTree::returnRootKey()
{
    if(root != NULL)
    {
        return root->key;
    }
    else
    {
        return "null";
    }
}

void BinaryTree::printChildren(string key)
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
            cout << "Right Sibling = NULL\n";
        }
        else
        {
            cout << "Right Sibling = " << ptr->right->key << endl;
        }
    }
    else
    {
        cout << "Key " << key << " is not in the tree.\n";
    }
}

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

string BinaryTree::findSmallest()
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

string BinaryTree::findSmallestPrivate(node *ptr)
{
    if(root == NULL)
    {
        cout << "The tree is empty\n";
        return "null";
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

void BinaryTree::removeNode(string key)
{
    removeNodePrivate(key, root);
}

void BinaryTree::removeNodePrivate(string key, node *parent)
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
        string rootKey = root->key;
        string smallestInRightSubtree;

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
        string matchKey = match->key;
        string smallestInRightSubtree;

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
