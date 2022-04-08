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

using namespace std;

/// functions
void add_phone(string name, string brand, int stock);
int  search(string name, string brand);
void handle_menu(int menu);
void change_mobile_info();
void remove(int index);
void most_sold_item();
void sort_by_price();
void sell_a_mobile();
void cout_menu();


int main()
{
    cout_menu();
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
void add_phone(string name, string brand, int stock) {

    return cout_menu();
}

/**
 * Remove `phone` with index.
 * then shrink `phones` array
 *
 * @param index of `phones` array.
 *
 * @return void
 */
void remove(int index) {

}

/**
 * Find `phone` with name and brand.
 *
 * @param name
 * @param brand
 *
 * @return index of `phone`, or -1 if there was no `phone`.
 */
int search(string name, string brand) {

}

/**
 * Sort `phones` array by price.
 * without duplicate array
 */
void sort_by_price() {

}

/**
 * Change detail of `phone`.
 *
 * @param name
 * @param brand
 */
void change_mobile_info() {

}

/**
 * Change detail of `phone`.
 *
 * @param name
 * @param brand
 */
void sell_a_mobile() {

}

/**
 * Print `phones` detail sorted by sell.
 *
 */
void most_sold_item() {

}

void cout_menu() {

    int menu;

    /// print menu for user
    cout << "1- Add a phone" << endl;
    cout << "2- Remove phone" << endl;
    cout << "3- Sort phones by price" << endl;
    cout << "4- Search a phone" << endl;
    cout << "5- Change phone info" << endl;
    cout << "6- Sell a phone" << endl;
    cout << "7- Print phones" << endl;
    cout << "8- Print phones sorted by the most sold to the least" << endl;
    cout << "9- Quit" << endl;
    cin >> menu;

    /// prepare for next use
    cin.clear();
    std::cin.ignore();

    /// Perform the action associated with each menu item
    return handle_menu(menu);
}

/**
 * Manage menu items
 * Call suitable function
 *
 * @param menu
 */
void handle_menu(int menu) {

    switch(menu) {
        case 1:
            {
                /// get phone detail from user
                string name, brand;
                int stock;

                cout << "Enter the phone name" << endl;
                cin >> name;

                cout << "Enter the phone brand" << endl;
                cin >> brand;

                cout << "Enter the phone stock" << endl;
                cin >> stock;

                /// call function
                return add_phone(name, brand, stock);
            }
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
            // code block
            break;
        case 8:
            // code block
            break;
        case 9:
            cout << "The End ...." << endl;
            break;
        default:
            {
                cout << "The value entered is incorrect. Please enter the menu number carefully" << endl;
                return cout_menu();
            }
    }

}




