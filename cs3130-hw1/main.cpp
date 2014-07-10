#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

/*

CIS 3130 ASSIGNMENT # 1     KELVIN LEE
Multi-dimension Arrays

*/

using namespace std;

string floatToString(float number);
void readInTransact(string transactArray[35][6]);
void readInMaster(string masterArray[7][4]);
void writeToMaster(string masterArray[7][4]);

int main()
{
    string masterArray[7][4];
    string transactArray[35][6];

    readInMaster(masterArray);
    readInTransact(transactArray);

    int quantity = 0;
    string oldBalance;
    string newBalance;
    float balance = 0;
    float cost;
    float payment;
    float orderAmount;
    float totalCost;
    double grandTotal = 0;
    string totalCostString;

    // go through transactArray and check for "o" and "p" and do calculations
    for (int i = 0; i < 7; i++)
    {
        oldBalance = masterArray[i][3];
        cout << masterArray[i][1] << " " << masterArray[i][2] << " " << masterArray[i][0] << endl;
        cout << "Previous Balance: " << oldBalance << endl;
        for (int n = 0; n < 35; n++)
        {
            if (transactArray[n][1] == masterArray[i][0])
            {
                if (transactArray[n][0] == "o")
                {
                    balance = atof(masterArray[i][3].c_str());  // convert current balance to float for calculation
                    quantity = atof(transactArray[n][4].c_str());   //convert quantity to float
                    cost = atof(transactArray[n][5].c_str());   // convert cost of item to float
                    orderAmount = quantity * cost;
                    totalCost = orderAmount + balance;  // calculate total cost
                    totalCostString = floatToString(totalCost); // convert back to string so it can go back to array
                    masterArray[i][3] = totalCostString;    // assign new value to master array
                    cout << "Trans #: " << transactArray[n][2] << " " << setw(10) << left << transactArray[n][3] << setw(5) << right << orderAmount << endl;
                }
                else if (transactArray[n][0] == "p")
                {
                    balance = atof(masterArray[i][3].c_str());  // convert current balance to float for calculation
                    payment = atof(transactArray[n][5].c_str());    // convert payment to float
                    totalCost = balance - payment;
                    totalCostString = floatToString(totalCost);
                    masterArray[i][3] = totalCostString;
                    newBalance = totalCostString;
                    cout << "Trans #: " << transactArray[n][2] << " " << setw(10) << left << "Payment: " << setw(5) << right << payment << endl;
                }
            }
        }
        cout << "Balance Due: " << newBalance << endl;
        cout << endl;
    }

    writeToMaster(masterArray);

    // check array for correct values
    for (int i = 0; i < 7; i++)
    {
        grandTotal += atof(masterArray[i][3].c_str());
        //cout << masterArray[i][0] << " " << masterArray[i][1] << " "  << masterArray[i][2] << " "  << masterArray[i][3] << endl;
    }

    cout << "Current total balance: " << grandTotal << endl;

    return 0;
}

void readInTransact(string transactArray[35][6])
{
    ifstream transactIn("transact.txt");
    if (transactIn)
    {
//        cout << "File open successful" << endl;

        // read in transact file to array
        for (int i = 0; i < 35; i++)
        {
            transactIn >> transactArray[i][0] >> transactArray[i][1] >> transactArray[i][2] >> transactArray[i][3] >> transactArray[i][4] >> transactArray[i][5];
        }

//        for (int i = 0; i < 35; i++)
//        {
//            cout << transactArray[i][0] << " " << transactArray[i][1] << " "  << transactArray[i][2] << " "  << transactArray[i][3] << " "  << transactArray[i][4] << " "  << transactArray[i][5] << endl;
//        }

        transactIn.close();
    }
}

void readInMaster(string masterArray[7][4])
{
    ifstream masterIn("master.txt");
    if (masterIn)
    {
//        cout << "File open successful" << endl;

        // read in master file
        for (int i = 0; i < 7; i++)
        {
            masterIn >> masterArray[i][0] >> masterArray[i][1] >> masterArray[i][2] >> masterArray[i][3];
        }

//        for (int i = 0; i < 7; i++)
//        {
//            cout << masterArray[i][0] << " " << masterArray[i][1] << " "  << masterArray[i][2] << " "  << masterArray[i][3] << endl;
//        }

        masterIn.close();
    }
}

void writeToMaster(string masterArray[7][4])
{
    ofstream masterOut("master.txt");

    if (masterOut)
    {
//        cout << "File open successful" << endl;

        for (int i = 0; i < 7; i++)
        {
            masterOut << masterArray[i][0] << " " << masterArray[i][1] << " " << masterArray[i][2] << " " << masterArray[i][3] << endl;
        }

        masterOut.close();
    }

}

string floatToString(float number)
{
    string numberBackToArray;
    stringstream ss(stringstream::in | stringstream::out);
    ss << number;
    numberBackToArray = ss.str();

    return numberBackToArray;

}
