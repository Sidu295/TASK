#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string item_code[] = {"CASE_1", "CASE_2", "RAM_1", "RAM_2", "RAM_3", "HDD_1", "HDD_2", "HDD_3", "SSD_1", "SSD_2", "2nd_HDD_1", "2nd_HDD_2", "2nd_HDD_3", "OD_1", "OD_2", "OS_1", "OS_2"};
string item_descriptions[] = {"compact", "tower", "8GB", "16GB", "32GB", "1TB", "2TB", "4TB", "240GB_SSD", "480GB_SSD", "1TB_HDD", "2TB_HDD", "4YB_HDD", "DVD/Blu-RAY Player", "DVD/Blue-Ray Re Writer", "Standard", "Proffesional Version"};
double item_prices[] = {75, 150, 79, 149, 299, 49, 89, 129, 59, 119, 49, 89, 129, 50, 100, 100, 175};

int main()
{
    double base_price = 200.0;
    double total_price = base_price;

    string chosenCase, chosenRAM, chosenHDD;
    cout << "(((<----Welcome TO Ahmed Online Computer Shop---->)))" << endl
         << endl;
    cout << "Choose One case option (CASE_1 or CASE_2): ";
    cin >> chosenCase;
    cout << "Choose one RAM option (RAM_1 or RAM_2 or RAM_3): ";
    cin >> chosenRAM;
    cout << "Choose one HDD option (HDD_1 OR HDD_2 OR HDD_3): ";
    cin >> chosenHDD;

    string additionalItems;
    double discount = 0.0;

    cout << "Do you want to purchase additional items (Y/N)? ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Available additional items:" << endl;
        for (int i = 0; i < 17; i++)
        {
            if (item_code[i] != chosenCase && item_descriptions[i] != chosenRAM && item_code[i] != chosenHDD)
            {
                cout << item_code[i] << " - " << item_descriptions[i] << " - $" << item_prices[i] << endl;
            }
        }
        cout << "Enter the codes of the additional items you want to purchase (separated by spaces): ";
        cin.ignore();
        getline(cin, additionalItems);

        // Split the additionalItems into individual items
        istringstream iss(additionalItems);
        string additionalItemCode;
        bool addedItems[17] = {false};

        while (iss >> additionalItemCode)
        {
            for (int i = 0; i < 17; i++)
            {
                if (additionalItemCode == item_code[i] && !addedItems[i])
                {
                    total_price += item_prices[i];
                    addedItems[i] = true;
                }
            }
        }

        // Calculate the discount based on the number of additional items
        int additionalItemCount = 0;
        for (int i = 0; i < 17; i++)
        {
            if (addedItems[i])
            {
                additionalItemCount++;
            }
        }

        if (additionalItemCount == 1)
        {
            discount = total_price * 0.05;
        }
        else if (additionalItemCount >= 2)
        {
            discount = total_price * 0.10;
        }
    }

    cout << "Chosen Items: " << endl
         << endl;
    cout << "Case you chose: " << chosenCase << endl;
    cout << "RAM you chose: " << chosenRAM << endl;
    cout << "HDD you chose: " << chosenHDD << endl;

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Additional Items: " << additionalItems << endl;
        cout << "Discount Applied: $" << discount << endl;
    }

    cout << "Total price of your computer: $" << (total_price - discount) << endl;
    return 0;
}
