#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

/*

CIS 3130 ASSIGNMENT # 2     KELVIN LEE
Multi-dimension Arrays

*/

using namespace std;

void readInCards(string cardsArray[18][5]);
string intToString(int number);

int main()
{
    int cardsItem1 = 0;
    int cardsItem2 = 0;
    int cardsItem3 = 0;
    int recordItem1 = 0;
    int recordItem2 = 0;
    int recordItem3 = 0;
    int totalItem1 = 0;
    int totalItem2 = 0;
    int totalItem3 = 0;
    float price;
    int mostOfItem;
    string item1;
    string item2;
    string item3;

    string warehouseRecord[5][4] =
    {
        {"NY", "0", "0", "0"},
        {"LA", "0", "0", "0"},
        {"Miami", "0", "0", "0"},
        {"Houston", "0", "0", "0"},
        {"Chicago", "0", "0", "0"}
    };
    float priceOfItems[3] = {2.00, 7.00, 8.50};
    string cardsArray[18][5];
    readInCards(cardsArray);

    for (int i = 0; i < 5; i++)
    {
        for (int n = 0; n < 18; n++)
        {
            if (warehouseRecord[i][0] == cardsArray[n][1])
            {
                if (cardsArray[n][0] == "s")
                {
                    cout << "Shipment read in: " << warehouseRecord[i][0] << " " << cardsArray[n][2] << " " << cardsArray[n][3] << " " << cardsArray[n][4] << endl;
                    cardsItem1 = atoi(cardsArray[n][2].c_str());    // convert cards item 1 to int
                    cardsItem2 = atoi(cardsArray[n][3].c_str());    // convert cards item 2 to int
                    cardsItem3 = atoi(cardsArray[n][4].c_str());    // convert cards item 3 to int
                    recordItem1 = atoi(warehouseRecord[i][1].c_str());
                    recordItem2 = atoi(warehouseRecord[i][2].c_str());
                    recordItem3 = atoi(warehouseRecord[i][3].c_str());
                    totalItem1 = cardsItem1 + recordItem1;  // add shipment to warehouse
                    totalItem2 = cardsItem2 + recordItem2;
                    totalItem3 = cardsItem3 + recordItem3;
                    item1 = intToString(totalItem1);    // convert back to string
                    item2 = intToString(totalItem2);
                    item3 = intToString(totalItem3);
                    warehouseRecord[i][1] = item1;  // put new value to array
                    warehouseRecord[i][2] = item2;
                    warehouseRecord[i][3] = item3;
                    cout << "In warehouse: " << warehouseRecord[i][0] << " " << warehouseRecord[i][1] << " " << warehouseRecord[i][2] << " " << warehouseRecord[i][3] << endl;
                }
                else if (cardsArray[n][0] == "o")
                {
                    cout << "Order read in: " << warehouseRecord[i][0] << " " << cardsArray[n][2] << " " << cardsArray[n][3] << " " << cardsArray[n][4] << endl;
                    cardsItem1 = atoi(cardsArray[n][2].c_str());
                    cardsItem2 = atoi(cardsArray[n][3].c_str());
                    cardsItem3 = atoi(cardsArray[n][4].c_str());
                    recordItem1 = atoi(warehouseRecord[i][1].c_str());
                    recordItem2 = atoi(warehouseRecord[i][2].c_str());
                    recordItem3 = atoi(warehouseRecord[i][3].c_str());
                    if (cardsItem1 < recordItem1)
                    {
                        totalItem1 = recordItem1 - cardsItem1;
                        price = totalItem1 * priceOfItems[0];   // calculate price of item1
                        item1 = intToString(totalItem1);
                        warehouseRecord[i][1] = item1;
                        cout << "Item 1: Order filled. Price of order: $" << price << endl;
                    }
                    else
                    {
                        for(int i = 0; i < 5; i++)  // go through each city warehouse and check for item 1 availability, find the most
                        {
                            cout << "Looking through warehouse in: " << warehouseRecord[i][0] << endl;
                            if (atoi(warehouseRecord[i][1].c_str()) > cardsItem1)   // does this city warehouse have enough of item 1?
                            {
                                // set this warehouse record to be the most and compare it to the order quantity
                                // if the quantity is enough, send from this warehouse to the warehouse that is short on supply
                                cout << "Item 1: Order filled." << endl;
                            }
                            else    // other city warehouses don't have enough of item 1
                            {
                                cout << "Item 1: Order Unfilled" << endl;
                            }
                        }
                    }
                    if (cardsItem2 < recordItem2)
                    {
                        totalItem2 = recordItem2 - cardsItem2;
                        price = totalItem2 * priceOfItems[1];
                        item2 = intToString(totalItem2);
                        warehouseRecord[i][2] = item2;
                        cout << "Item 2: Order filled. Price of order: $" << price << endl;
                    }
                    else
                    {
                        for(int i = 0; i < 5; i++)  // go through each city warehouse and check for item 2 availability, find the most
                        {
                            cout << "Looking through warehouse in: " << warehouseRecord[i][0] << endl;
                            if (atoi(warehouseRecord[i][2].c_str()) > cardsItem2)   // does this city warehouse have enough of item 2?
                            {
                                // set this warehouse record to be the most and compare it to the order quantity
                                // if the quantity is enough, send from this warehouse to the warehouse that is short on supply
                                cout << "Item 2: Order filled." << endl;
                            }
                            else    // other city warehouses don't have enough of item 2
                            {
                                cout << "Item 2: Order Unfilled" << endl;
                            }
                        }
                    }
                    if (cardsItem3 < recordItem3)
                    {
                        totalItem3 = recordItem3 - cardsItem3;
                        price = totalItem3 * priceOfItems[2];
                        item3 = intToString(totalItem3);
                        warehouseRecord[i][3] = item3;
                        cout << "Item 3: Order filled. Price of order: $" << price << endl;
                    }
                    else
                    {
                        for(int i = 0; i < 5; i++)  // go through each city warehouse and check for item 3 availability, find the most
                        {
                            cout << "Looking through warehouse in: " << warehouseRecord[i][0] << endl;
                            if (atoi(warehouseRecord[i][3].c_str()) > cardsItem3)   // does this city warehouse have enough of item 3?
                            {
                                // set this warehouse record to be the most and compare it to the order quantity
                                // if the quantity is enough, send from this warehouse to the warehouse that is short on supply
                                cout << "Item 3: Order filled." << endl;
                            }
                            else    // other city warehouses don't have enough of item 3
                            {
                                cout << "Item 3: Order Unfilled" << endl;
                            }
                        }
                    }
                }
            }
        }

    }

    // What's in the warehouseRecord
    for (int i = 0; i < 5; i++)
    {
        cout << warehouseRecord[i][0] << " " << warehouseRecord[i][1] << " " << warehouseRecord[i][2] << " " << warehouseRecord[i][3] << endl;
    }

    return 0;
}

void readInCards(string cardsArray[18][5])
{
    ifstream cardsIn("cards.txt");
    if (cardsIn)
    {
        cout << "File open successful" << endl;

        // read in cards file
        for (int i = 0; i < 18; i++)
        {
            cardsIn >> cardsArray[i][0] >> cardsArray[i][1] >> cardsArray[i][2] >> cardsArray[i][3] >> cardsArray[i][4];
        }

//        for (int i = 0; i < 18; i++)
//        {
//            cout << cardsArray[i][0] << " " << cardsArray[i][1] << " "  << cardsArray[i][2] << " "  << cardsArray[i][3] << " " << cardsArray[i][4] << endl;
//        }

        cardsIn.close();
    }
}

string intToString(int number)
{
    string numberBackToArray;
    stringstream ss(stringstream::in | stringstream::out);
    ss << number;
    numberBackToArray = ss.str();

    return numberBackToArray;
}
