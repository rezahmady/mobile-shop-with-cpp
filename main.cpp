/*
 * This file is part of mobile_shop_with_cpp.
 *
 * Author : Reza ahmadi sabzevar <ahmadireza15@gmail.com>
 * Github link : https://github.com/rezahmady/mobile-shop-with-cpp
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <limits>
#include<string>

using namespace std;

struct Mobile
{
    string name;
    string brand;
    int stock;
    int price;
    int sell;

};

/// functions
bool compareTwoPhonesBySell(Mobile a, Mobile b, Mobile *phones, int size);
void print_a_phone(string name, string brand, Mobile *phones, int size);
void remove_phone(string name, string brand, Mobile *phones, int size);
int  search(string name, string brand, Mobile *phones, int size);
void handle_menu(int menu, Mobile *phones, int size);
void change_mobile_info(Mobile *phones, int size);
void most_sold_item(Mobile *phones, int size);
void sort_by_price(Mobile *phones, int size);
void sell_a_mobile(Mobile *phones, int size);
void print_phones(Mobile *phones, int size);
void add_phone(Mobile *phones, int size);
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

    /// End program without any error :)
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

    /// Check for the absence of a mobile in the `phones` array
    /// with this `name` and `brand` in advance
    int phone_index = search(name, brand, phones, size);
    while(phone_index != -1)
    {
        cin.clear();
        cin.ignore();

        cout << "error : Mobile with these specifications already added. Enter new information" << endl;
        cout << "Enter the phone name :" << endl;
        cin >> name;

        cout << "Enter the phone brand :" << endl;
        cin >> brand;

        cout << "name :" << name << " brand :" << brand << endl;

        phone_index = search(name, brand, phones, size);
    }

    cout << "Enter the phone stock :" << endl;
    cin >> stock;

    /// validate stock input . must be integer
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
 * Remove `phone`.
 * then shrink `phones` array
 *
 * @param index of `phones` array.
 *
 * @return void
 */
void remove_phone(string name, string brand, Mobile *phones,int size) {

    /// check phone exists
    int index = search(name, brand, phones, size);

    if(index == -1) {
        cout << "error : phone not found." << endl;
        return cout_menu(phones, size);
    }

    /// remove phone
    /// Shifting mobiles to the left in the right position
    /// relative to the removed mobile position
    for (int i = index + 1; i < size; ++i) {
        phones[i - 1] = phones[i];
    }

    /// shrink array
    Mobile *old_phones = phones;
    size -= 1;
    phones = new Mobile[size];
    for(int i=0; i<size; i++) {
        phones[i] = old_phones[i];
    }
    old_phones = NULL;
    delete old_phones;

    /// print message
    cout << "phone `" << name << "|" << brand << "` deleted successfully." << endl;
    return cout_menu(phones, size);

}

/**
 * Find `phone` with name and brand.
 *
 * @param name
 * @param brand
 *
 * @return index of `phone`, or -1 if there was no `phone`.
 */
int search(string name, string brand, Mobile *phones, int size) {
    int index = -1;
    for(int i=0; i<size; i++) {
        if((phones[i].name == name) && (phones[i].brand == brand)) {
            index = i;
            break;
        }
    }
    return index;
}



/**
 * Sort `phones` array by price.
 * without duplicate array
 */
void sort_by_price(Mobile *phones, int size) {

    Mobile temp;
    int i,j;

    bool swapped = false;

    /// loop through all numbers
    if(size > 1) for(i = 0; i < size-1; i++) {
        swapped = false;

        /// loop through numbers falling ahead
        for(j = 0; j < size-1-i; j++) {
            if(phones[j].price < phones[j+1].price) {
                temp = phones[j];
                phones[j] = phones[j+1];
                phones[j+1] = temp;
                swapped = true;
            }
        }

        /// if no number was swapped that means
        /// array is sorted now, break the loop.
        if(!swapped) {
            break;
        }
    }
    cout << "all phones sorted by price successfully." << endl;
    return cout_menu(phones, size);
}

/**
 * Change detail of `phone`.
 *
 * @param name
 * @param brand
 */
void change_mobile_info(Mobile *phones, int size) {

}

/**
 * Change detail of `phone`.
 *
 * @param name
 * @param brand
 */
void sell_a_mobile(Mobile *phones, int size) {
    /// get detail from user
    string name, brand;
    cout << "Enter the phone name :" << endl;
    cin >> name;

    cout << "Enter the phone brand :" << endl;
    cin >> brand;

    int index = search(name, brand, phones, size );

    if(index == -1) {
        cout << "error : phone not found." << endl;
        return cout_menu(phones, size);
    }
    else{
        phones[index].stock -= 1;
        phones[index].sell += 1;
        cout << "Sales were registered successfully." << endl;
        return print_a_phone(name, brand, phones, size);
    }
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
            cout << "sell  "  << " | " << phones[j].sell  << endl;
            cout << "-----------------------"             << endl;
        }

    } else {
        cout << "Phone has not been added yet." << endl;
    }
}

/**
 * Print a `phone`.
 *
 */
void print_a_phone(string name, string brand, Mobile *phones, int size) {

    /// Check there is a `phone`
    if(size) {
        int index = search(name, brand, phones, size );

        if(index == -1)
            cout << "error : phone not found." << endl;
        else{
            cout << "-----------------------"                 << endl;
            cout <<  "::" << index << "::"                    << endl;
            cout << "name  "  << " | " << phones[index].name  << endl;
            cout << "brand "  << " | " << phones[index].brand << endl;
            cout << "stock "  << " | " << phones[index].stock << endl;
            cout << "price "  << " | " << phones[index].price << endl;
            cout << "sell  "  << " | " << phones[index].sell  << endl;
            cout << "-----------------------"                 << endl;
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
void most_sold_item(Mobile *phones, int size) {
    Mobile *sorted_by_sold = phones;

    Mobile temp;
    int i,j;

    bool swapped = false;

    /// loop through all numbers
    if(size > 1) for(i = 0; i < size-1; i++) {
        swapped = false;

        /// loop through numbers falling ahead
        for(j = 0; j < size-1-i; j++) {
            if(sorted_by_sold[j].sell < sorted_by_sold[j+1].sell) {
                temp = sorted_by_sold[j];
                sorted_by_sold[j] = sorted_by_sold[j+1];
                sorted_by_sold[j+1] = temp;
                swapped = true;
            }
        }

        /// if no number was swapped that means
        /// array is sorted now, break the loop.
        if(!swapped) {
            break;
        }
    }

    /// print phones sorted by sell
    print_phones(sorted_by_sold, size);

    /// delete extra pointer
    sorted_by_sold = NULL;
    delete sorted_by_sold;

    /// print main menu
    return cout_menu(phones, size);
}

/**
 * Print main menu.
 *
 */
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
            {
                string name, brand;
                cout << "Enter the phone name :" << endl;
                cin >> name;

                cout << "Enter the phone brand :" << endl;
                cin >> brand;

                return remove_phone(name, brand, phones, size);
            }
        case 3:
            return sort_by_price(phones, size);
        case 4:
            {
                /// get data from  user
                string name, brand;
                cout << "Enter the phone name :" << endl;
                cin >> name;

                cout << "Enter the phone brand :" << endl;
                cin >> brand;

                /// search and print phone
                return print_a_phone(name, brand, phones, size);
            }
        case 5:
            // code block
            break;
        case 6:
            return sell_a_mobile(phones, size);
        case 7:
            {
                /// print all phones
                print_phones(phones, size);

                /// print main menu
                return cout_menu(phones, size);
            }
        case 8:
            return most_sold_item(phones, size);
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






