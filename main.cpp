/*
 * This file is part of mobile_shop_with_cpp.
 *
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <limits>
#include<string>

using namespace std;

#define MAX_PHONES 1000
struct Mobile
{
    string name;
    string brand;
    int stock;
    int price;
    int sell;
};

/// functions
void add_phone(Mobile *phones, int size);
int  search(string name, string brand, Mobile *phones);
void handle_menu(int menu, Mobile *phones, int size);
void print_phones(Mobile *phones, int size);
void change_mobile_info(Mobile *phones);
void remove(int index, Mobile *phones);
void most_sold_item(Mobile *phones);
void sort_by_price(Mobile *phones);
void sell_a_mobile(Mobile *phones);
void cout_menu(Mobile *phones, int size);





int main()
{
    int size = 0;
    int *s = nullptr;

    /// call menu
    Mobile *phones ;
    cout_menu(phones, size);

    /// delete pointers
    phones = NULL;
    delete phones;
    delete s;

    /// return
    return 0;
}

/**
 * Add `phone` to `phones` array.
 *
 * @param name
 * @param brand
 * @param stock
 *
 * @return void
 */
void add_phone(Mobile *phones, int size) {

    /// get phone detail from user
    string name, brand;
    int stock;

    cout << "Enter the phone name :" << endl;
    cin >> name;

    cout << "Enter the phone brand :" << endl;
    cin >> brand;

    cout << "Enter the phone stock :" << endl;
    cin >> stock;

    /// validate stock input . must be intiger
    while (!std::cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "error : stock must be number" << endl << "Enter the phone stock correctly:" << endl;
        cin >> stock;
    }

    /// add new phone in `phones` array

    if(size == 0) {
        phones = new Mobile[1];
        phones[0] = {name, brand, stock, 0, 0};
        size +=1;
    } else {
        Mobile *old_phones = phones;
        phones = new Mobile[size+1];
        for (int i=0; i < size; i++) {
            phones[i] = old_phones[i];
        }
        phones[size] = {name, brand, stock, 0, 0};
        size +=1;
        delete[] old_phones;
    }

    return cout_menu(phones, size);
}

/**
 * Remove `phone` with index.
 * then shrink `phones` array
 *
 * @param index of `phones` array.
 *
 * @return void
 */
void remove(int index, Mobile *phones) {

}

/**
 * Find `phone` with name and brand.
 *
 * @param name
 * @param brand
 *
 * @return index of `phone`, or -1 if there was no `phone`.
 */
int search(string name, string brand, Mobile *phones) {

}

/**
 * Sort `phones` array by price.
 * without duplicate array
 */
void sort_by_price(Mobile *phones) {

}

/**
 * Change detail of `phone`.
 *
 * @param name
 * @param brand
 */
void change_mobile_info(Mobile *phones) {

}

/**
 * Change detail of `phone`.
 *
 * @param name
 * @param brand
 */
void sell_a_mobile(Mobile *phones) {

}


/**
 * Print `phones` array.
 *
 */
void print_phones(Mobile *phones, int size) {

    /// Check there is a `phone`
    if(size) {

        /// print array in readable format
        for (int j=0;j< size; j++) {
            cout << "-----------------------"             << endl;
            cout <<  "::" << j << "::"                    << endl;
            cout << "name  "  << " | " << phones[j].name  << endl;
            cout << "brand "  << " | " << phones[j].brand << endl;
            cout << "stock "  << " | " << phones[j].stock << endl;
            cout << "price "  << " | " << phones[j].price << endl;
            cout << "-----------------------"             << endl;
        }

    } else {
        cout << "Phone has not been added yet." << endl;
    }

    return cout_menu(phones, size);
}

/**
 * Print `phones` detail sorted by sell.
 *
 */
void most_sold_item(Mobile *phones) {

}

void cout_menu(Mobile *phones, int size) {

    int menu;

    /// print menu for user
    cout << "[1] Add a phone" << endl;
    cout << "[2] Remove phone" << endl;
    cout << "[3] Sort phones by price" << endl;
    cout << "[4] Search a phone" << endl;
    cout << "[5] Change phone info" << endl;
    cout << "[6] Sell a phone" << endl;
    cout << "[7] Print phones" << endl;
    cout << "[8] Print phones sorted by the most sold to the least" << endl;
    cout << "[9] Quit" << endl;
    cin >> menu;

    /// prepare for next use
    cin.clear();
    std::cin.ignore();

    /// Perform the action associated with each menu item
    return handle_menu(menu, phones, size);
}

/**
 * Manage menu items
 * Call suitable function
 *
 * @param menu
 */
void handle_menu(int menu, Mobile *phones, int size) {

    switch(menu) {
        case 1:
            return add_phone(phones, size);
        case 2:
            // code block
            break;
        case 3:
            // code block
            break;
        case 4:
            // code block
            break;
        case 5:
            // code block
            break;
        case 6:
            // code block
            break;
        case 7:
            return print_phones(phones, size);
            break;
        case 8:
            // code block
            break;
        case 9:
            cout << "<<<<--THANK YOU-->>>>" << endl;
            break;
        default:
            {
                cout << "The value entered is incorrect. Please enter the menu number carefully" << endl;
                return cout_menu(phones, size);
            }
    }

}






