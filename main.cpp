#include <iostream>
#include <string>
#include <limits>
#include "ServiceList.h"
#include "ServiceFunctions.h"
using namespace std;

void ReadDetails(string& name, string& type, string& phone) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Service Type (Repair/Maintenance): ";
    getline(cin, type);

    cout << "Enter Contact Number: ";
    getline(cin, phone);
}

int main() {
    ServiceList services;
    int choice;

    do {
        cout << "\n===== SERVICE CENTER MANAGEMENT SYSTEM =====\n";
        cout << "1. Display All Services\n";
        cout << "2. Add Service at Head\n";
        cout << "3. Remove Service from Head\n";
        cout << "4. Insert Service at Index\n";
        cout << "5. Remove Service at Index\n";
        cout << "6. Swap Services by ID\n";
        cout << "7. Sort Services by ID\n";
        cout << "8. Reverse Service List\n";
        cout << "9. Check List Status\n";
        cout << "10. Count Total Services\n";
        cout << "11. Search Service by ID\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                services.Print();
                break;

            case 2: {
                int id;
                string name, type, phone;

                cout << "Enter Service ID: ";
                cin >> id;
                ReadDetails(name, type, phone);

                services.Insert(id, name, type, phone);
                break;
            }

            case 3:
                services.Remove();
                break;

            case 4: {
                int index, id;
                string name, type, phone;

                cout << "Enter index (starting from 0): ";
                cin >> index;

                cout << "Enter Service ID: ";
                cin >> id;

                ReadDetails(name, type, phone);

                services.InsertAt(index, id, name, type, phone);
                break;
            }

            case 5: {
                int index;

                cout << "Enter index (starting from 0): ";
                cin >> index;

                services.RemoveAt(index);
                break;
            }

            case 6: {
                int id1, id2;

                cout << "Enter first Service ID: ";
                cin >> id1;

                cout << "Enter second Service ID: ";
                cin >> id2;

                services.Swap(id1, id2);
                break;
            }

            case 7:
                services.Sort();
                break;

            case 8:
                services.Reverse();
                break;

            case 9:
                if (services.IsEmpty()) {
                    cout << "The service list is empty.\n";
                } else {
                    cout << "The service list is not empty.\n";
                }
                break;

            case 10:
                ShowTotalServices(services);
                break;

            case 11:
                SearchService(services);
                break;

            case 12:
                cout << "Exiting Service Center Management System.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 12);

    return 0;
}