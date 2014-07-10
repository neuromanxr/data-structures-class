#include <iostream>
#include <fstream>

/*

CIS 3130 ASSIGNMENT # 3     KELVIN LEE
Linked Lists

*/

using namespace std;

void readInData(float dataArray[][3]);

class List{
private:

    typedef struct node{
        int index;
        char rsp;
        int quantity;
        float price;

        node *next;
    }* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

public:
    List();
    void AddNode(int addData);
    void AddSalesNode(int i, char s, int quant);
    void AddReceiptNode(int i, char r, int quant, float cost);
    void AddPromoNode(int i, char p, float discount);
    void DeleteNode(int i, char rsp);
    void PrintList();
    void CalculateInv();
};

List::List(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

// add node template

//void List::AddNode(int addData)
//{
//    nodePtr n = new node;   // new node n allocated with memory
//    n->next = NULL;         // n points to next element, nothing, end of list
//    n->data = addData;      // n node data
//
//    if(head != NULL) {      // head is pointer, is it pointing to an existing object?
//        curr = head;        // make curr pointer point to same thing as head
//        while(curr->next != NULL){      // Did we reach end of list?
//            curr = curr->next;          // curr pointer points to next node on list till end of list
//        }
//        curr->next = n;     // curr points to next of n node
//    }
//    else    // if we don't have at least one element in list
//    {
//        head = n;   // then head node points to n node, the front of the list
//    }
//
//}

void List::AddSalesNode(int i, char s, int quant)
{
    nodePtr n = new node;   // new node n allocated with memory
    n->next = NULL;         // next is nothing, end of list
    n->rsp = s;             // assign rsp data to s data
    n->quantity = quant;    // assign quantity to quant data
    n->index = i;

    if(head != NULL) {      // is the head pointing to an existing object?
        curr = head;        // curr point to same location as head
        while(curr->next != NULL) {     // go through the list till we reach the end
            curr = curr->next;      // curr pointer points to next node on list till end of list
        }
        curr->next = n;     // curr points to next of n node
    }
    else        // if we don't have at least one element in list
    {
        head = n;   // then head node points to n node, the front of the list
    }
}

void List::AddReceiptNode(int i, char r, int quant, float cost)
{
    nodePtr n = new node;   // new node n allocated with memory
    n->next = NULL;         // next is nothing, end of list
    n->rsp = r;             // assign rsp data to s data
    n->quantity = quant;    // assign quantity to quant data
    n->price = cost;        // assign price to cost parameter
    n->index = i;

    if(head != NULL) {      // is the head pointing to an existing object?
        curr = head;        // if so make curr point to same location as head
        while(curr->next != NULL) {     // go through the list till we reach the end
            curr = curr->next;      // curr pointer points to next node on list till end of list
        }
        curr->next = n;     // curr points to next of n node, adds node to end of the list
    }
    else        // if we don't have at least one element in list
    {
        head = n;   // then head node points to n node, the front of the list
    }
}

void List::AddPromoNode(int i, char p, float discount)
{
    nodePtr n = new node;   // new node n allocated with memory
    n->next = NULL;         // next is nothing, end of list
    n->rsp = p;             // assign rsp member variable to p data
    n->price = discount;    // assign price to discount parameter
    n->index = i;

    if(head != NULL) {      // is the head pointing to an existing object?
        curr = head;        // if so make curr point to same location as head
        while(curr->next != NULL) {     // go through the list till we reach the end
            curr = curr->next;      // curr pointer points to next node on list till end of list
        }
        curr->next = n;     // curr points to next of n node, adds node to end of the list
    }
    else        // if we don't have at least one element in list
    {
        head = n;   // then head node points to n node, the front of the list
    }
}

void List::DeleteNode(int i, char rsp){
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while(curr != NULL && curr->index != i)    // look through the list till we get to NULL
    {                                          // and curr data is not index
        temp = curr;    // goes through list till it finds delData
        curr = curr->next;
//        cout << "curr " << curr->index << endl;
    }
    if (curr == NULL)   // Went through list but didn't find anything
    {
        cout << i << " " << rsp << " was not in the list." << endl;
        delete delPtr;  // delete from memory, clean up
    }
    else    // we found the node we wanted to delete
    {
        delPtr = curr;  // delPtr points to where it needs to delete
        curr = curr->next;     // this patches the hole in the list from deletion
        temp->next = curr;     // this patches the hole in the list from deletion
        if (delPtr == head) {
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout << "The value " << i << " " << rsp << " was deleted." << endl;
    }
}


void List::PrintList(){
    curr = head;    // front of the list
    temp = head;
    int i = 0;

    while (curr != NULL)    // is it the last node? if not keep going till we hit NULL
    {
        if(curr->rsp == 's')    // loop through list for sales records
        {
            cout << "Sales Record" << endl;
            cout << "rsp: " << curr->rsp << endl;
            cout << "quantity: " << curr->quantity << endl;
            cout << endl;
            curr = curr->next;
        }
        else if(curr->rsp == 'p')
        {
            cout << "Promo Record" << endl;
            cout << "rsp: " << curr->rsp << endl;
            cout << "discount: " << curr->price << endl;
            cout << endl;
            curr = curr->next;
        }
        else
        {
            cout << "Receipt Record" << endl;
            cout << "rsp: " << curr->rsp << endl;
            cout << "quantity: " << curr->quantity << endl;
            cout << "price: " << curr->price << endl;
            cout << endl;
            curr = curr->next;
        }
    }
}

void List::CalculateInv()
{
    curr = head;    // front of the list
    temp = head;    // seperate pointer for receipts
    int i = 0;
    int totalRemain = 0;
    float totalSales = 0.0;
    bool promoSwitch = false;
    float promoAmount = 0.0;
    int promoCount = 0;
    float salesAmount = 0.0;
    float totalCosts = 0.0;
    float markup = 1.3;

    while(curr != NULL)
    {
//        cout << "i " << i << endl;
        if(curr->rsp == 'p')    // is there a promo discount?
        {
            promoAmount = curr->price * 0.01;  // set the promo to the promo amount
            promoSwitch = true;     // bool to know when to apply promo
            cout << endl;
            cout << "Promo: " << promoAmount * 100 << "%" << endl;
            cout << endl;
        }

        if(curr->rsp == 's')
        {
            while(temp != NULL && curr->quantity > 0)
            {
                if(temp->rsp == 'r')
                {
                    if(temp->quantity < curr->quantity) // is there enough inventory for sales order?
                    {
                        salesAmount = temp->quantity * temp->price * markup;

                        if(promoSwitch)     // promo for the next two sales orders
                        {
                            salesAmount = salesAmount * promoAmount;
                            if(promoCount >= 2)
                            {
                                promoSwitch = false;
                            }
                            promoCount++;
                        }
                        if(promoCount >= 2)
                        {
                            promoCount = 0;
                        }
                        curr->quantity = curr->quantity - temp->quantity;   // remainder left for sales, not enough inventory
                        cout << "Sales: $" << salesAmount << endl;
                        totalCosts += temp->quantity * temp->price;
                        temp->quantity = temp->quantity - temp->quantity;   // receipt all used, zero
                        totalSales += salesAmount;
                        cout << endl;
                    }
                    else if(temp->quantity > curr->quantity)    // more receipts than sales, more than enough supply
                    {
                        salesAmount = curr->quantity * temp->price * markup;

                        if(promoSwitch)     // promo for the next two sales orders
                        {
                            salesAmount = salesAmount * promoAmount;
                            if(promoCount >= 2)
                            {
                                promoSwitch = false;
                            }
                            promoCount++;
                        }
                        if(promoCount >= 2)
                        {
                            promoCount = 0;
                        }
                        temp->quantity = temp->quantity - curr->quantity;   // find how much receipts are left are selling sales amount
                        cout << "Sales: $" << salesAmount << endl;
                        totalCosts += curr->quantity * temp->price;
                        curr->quantity = curr->quantity - curr->quantity;   // sold all of sales order
                        totalRemain = temp->quantity;
                        totalSales += salesAmount;

                        if(temp->quantity < curr->quantity)
                        {
                            cout << "Not enough widgets." << endl;
                        }

                        break;
                    }
                }
                temp = temp->next;  // next receipt on the list
            }
        }
        curr = curr->next;  // next sales order on the list
        i++;
    }
    cout << "Total Sales: $" << totalSales << endl;
    cout << "Total Costs: $" << totalCosts << endl;
    cout << "Total Remaining Inventory: " << totalRemain << endl;
}

int main()
{
    float dataArray[24][3];

    readInData(dataArray);

    List Widgets;

    for(int i = 0; i < 24; i++)
    {
        if(dataArray[i][0] == 1)    // 1 is r, for receipt
        {
            Widgets.AddReceiptNode(i, 'r', static_cast<int>(dataArray[i][1]), dataArray[i][2]);     // add data to receipt node
        }
        else if(dataArray[i][0] == 2)   // 2 is s, for sales
        {
            Widgets.AddSalesNode(i, 's', static_cast<int>(dataArray[i][1]));     // add data to sales node
        }
        else if(dataArray[i][0] == 3)   // 3 is p, for promo
        {
            Widgets.AddPromoNode(i, 'p', dataArray[i][1]);     // add data to promo node
        }
    }

    Widgets.PrintList();

    Widgets.CalculateInv();

    return 0;
}

void readInData(float dataArray[][3])
{
    ifstream infile("dataset.txt");
    if(infile)
    {
        cout << "File open success." << endl;
        for(int i = 0; i < 24; i++)
        {
            infile >> dataArray[i][0] >> dataArray[i][1] >> dataArray[i][2];
        }
        for(int i = 0; i < 24; i++)
        {
            cout << dataArray[i][0] << " " << dataArray[i][1] << " " << dataArray[i][2] << endl;
        }
        cout << endl;
    }

}

// variation of linked Lists functions

//Book *add_node(Book *in_root);
//void print_list(Book *in_root);

//Book *add_node(Book *in_root)
//{
//    Book *next_ptr = NULL;
//    Book *prev_ptr = NULL;
//
//    if (in_root == NULL)
//    {
//        // list is empty
//        if ((in_root = new Book) != NULL)
//        {
//            next_ptr = in_root;
//
//            cout << "Title: ";
//            cin >> next_ptr->title;
//
//            next_ptr->next = NULL;
//        }
//        else
//        {
//            cout << "ERROR: Unable to allocate memory." << endl;
//            return NULL;
//        }
//        return next_ptr;
//    }
//    else
//    {
//        // list has members
//        next_ptr = in_root;
//        while (next_ptr->next != NULL)
//        {
//            next_ptr = next_ptr->next;
//        }
//        prev_ptr = next_ptr;
//
//        if ((next_ptr = new Book) != NULL)
//        {
//            prev_ptr->next = next_ptr;
//
//            cout << "Title: ";
//            cin >> next_ptr->title;
//
//            next_ptr->next = NULL;
//        }
//        else
//        {
//            cout << "ERROR: Unable to allocate memory." << endl;
//        }
//        return in_root;
//    }
//
//}
//
//void print_list(Book *in_root)
//{
//    Book *next_ptr;
//
//    next_ptr = in_root;
//
//    if (next_ptr == NULL)
//    {
//        cout << "EMPTY LIST: No nodes to print. " << endl;
//    }
//    else
//    {
//        while (next_ptr != NULL)
//        {
//            cout << next_ptr->title << endl;
//            next_ptr = next_ptr->next;
//        }
//    }
//}

//void menu()
//{
//    char choice;
//
//    do{
//        cout << "A)dd node" << endl;
//        cout << "P)rint list" << endl;
//        cout << "Q(uit program" << endl;
//        cin >> choice;
//
//        choice = toupper(choice);
//
//        switch(choice)
//        {
//        case 'A':
//            head = add_node(head);
//            break;
//        case 'P':
//            print_list(head);
//            break;
//        case 'Q':
//            break;
//        default:
//            cout << "Invalid choice. " << endl;
//        }
//    }while(choice != 'Q');
//
//}
