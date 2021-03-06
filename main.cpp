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
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


// enums
enum OS
{
    OS_NULL, // for default value
    ios,
    Android,
    WindowsPhone
};

enum Ram
{
    R_NULL, // for default value
    R_2GB,
    R_4GB,
    R_6GB,
    R_8GB,
    R_12GB,
    R_16GB,
    R_32GB,
    R_64GB
};

enum Storage
{
    S_NULL, // for default value
    S_16GB,
    S_32GB,
    S_64GB,
    S_128GB,
    S_256GB,
    S_512GB,
    S_1TB,
    S_2TB
};

enum Color
{
    C_NULL, // for default value
    Black,
    Gray,
    Green,
    Blue,
    White,
    Red,
    Yellow
};

// Mobile Structure
struct Mobile
{
    string name;
    string brand;
    OS os;
    Ram ram;
    Storage storage;
    int stock;
    int price;
    int sell;
    Color color;

    // functions
    void print();
    string display_os();
    string display_ram();
    string display_storage();
    string display_color();
};

// print mobile details
void Mobile::print() {
    cout << "-----------------------"                 << endl;
    cout << "name    "  << " | " << name              << endl;
    cout << "brand   "  << " | " << brand             << endl;
    cout << "os      "  << " | " << display_os()      << endl;
    cout << "ram     "  << " | " << display_ram()     << endl;
    cout << "storage "  << " | " << display_storage() << endl;
    cout << "stock   "  << " | " << stock             << endl;
    cout << "price   "  << " | " << price             << endl;
    cout << "sell    "  << " | " << sell              << endl;
    cout << "color   "  << " | " << display_color()   << endl;
    cout << "-----------------------"                 << endl;

}

// display readable value for OS
string Mobile::display_os() {
    string labels[4] = {"-", "iOS", "Android", "WindowsPhone"};
    return labels[os];
}

// display readable value for Ram
string Mobile::display_ram() {
    string labels[9] = {"-", "2GB", "4GB", "6GB", "8GB", "12GB", "16GB", "32GB", "32GB"};
    return labels[ram];
}

// display readable value for Strorage
string Mobile::display_storage() {
    string labels[9] = {"-", "16GB", "32GB", "64GB", "128GB", "256GB", "512GB", "1TB", "2TB"};
    return labels[storage];
}

// display readable value for Color
string Mobile::display_color() {
    string labels[8] = {"-", "Black", "Gray", "Green", "Blue", "White", "Red", "Yellow"};
    return labels[color];
}

// functions
void remove_phone(string name, string brand, Mobile *phones, int size);
int  search(string name, string brand, Mobile *phones, int size);
void handle_menu(int menu, Mobile *phones, int size);
void edit_menu (int index, Mobile *phones, int size);
void change_mobile_info(Mobile *phones, int size);
void save_into_a_file(Mobile *phones, int size);
void load_from_a_file(Mobile *phones, int size);
void most_sold_item(Mobile *phones, int size);
void sort_by_price(Mobile *phones, int size);
void sell_a_mobile(Mobile *phones, int size);
void print_phones(Mobile *phones, int size);
void add_phone(Mobile *phones, int size);
void cout_menu(Mobile *phones, int size);

/**
 * App start
 *
 */
int main()
{
    // initialize size of phones array
    // It basically stores the number of phones
    int size = 0;
    int *s = nullptr;

    // An array containing all mobiles
    Mobile *phones ;

    // load saved phones from file
    // then print main menu
    load_from_a_file(phones, size);

    // delete pointers
    phones = NULL;
    delete phones;
    delete s;

    // End program without any error :)
    return 0;
}

/**
 * Save `phones` array in text file.
 *
 * @param phones
 * @param size
 *
 * @return void
 */
void save_into_a_file(Mobile *phones, int size)
{
    ofstream myfile ("phones.txt");
    if (myfile.is_open())
    {
        if(size > 0) {
            myfile << size << endl;
            for(int row = 0; row < size; row ++){
                myfile
                    << phones[row].name     << "\t"
                    << phones[row].brand    << "\t"
                    << phones[row].os       << "\t"
                    << phones[row].ram      << "\t"
                    << phones[row].storage  << "\t"
                    << phones[row].stock    << "\t"
                    << phones[row].price    << "\t"
                    << phones[row].sell     << "\t"
                    << phones[row].color    << "\t"
                    << endl ;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

/**
 * load `phones` array from text file.
 *
 * @param phones
 * @param size
 *
 * @return void
 */
void load_from_a_file(Mobile *phones, int size)
{
    int os_in_file, ram_in_file,storage_in_file,color_in_file;

    ifstream myfile("phones.txt");
    if (!myfile.is_open()) {
        cout << "Unable to open file";
        return cout_menu(phones, size);
    }

    // set array size from first line in file
    myfile >> size;
    phones = new Mobile[size];

    // loop until we reach the end of file, or until we hit size records,
    // whichever comes first
    for (int i=0; i<size; i++)
    {
        myfile
          >> phones[i].name
          >> phones[i].brand
          >> os_in_file
          >> ram_in_file
          >> storage_in_file
          >> phones[i].stock
          >> phones[i].price
          >> phones[i].sell
          >> color_in_file ;

        // Enum
        OS os_value = static_cast<OS>(os_in_file);
        Ram ram_value = static_cast<Ram>(ram_in_file);
        Storage storage_value = static_cast<Storage>(storage_in_file);
        Color color_value = static_cast<Color>(color_in_file);

        phones[i].os = os_value;
        phones[i].ram = ram_value;
        phones[i].storage = storage_value;
        phones[i].color = color_value;
    }

    myfile.close();

    cout_menu(phones, size);
}

/**
 * Add `phone` to `phones` array.
 *
 * @param phones
 * @param size
 *
 * @return void
 */
void add_phone(Mobile *phones, int size) {

    // get phone detail from user
    string name, brand;
    int stock;

    cout << "Enter the phone name :" << endl;
    cin >> name;

    cout << "Enter the phone brand :" << endl;
    cin >> brand;

    // Check for the absence of a mobile in the `phones` array
    // with this `name` and `brand` in advance
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

        phone_index = search(name, brand, phones, size);
    }

    cout << "Enter the phone stock :" << endl;
    cin >> stock;

    // validate stock input . must be integer
    while (!std::cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "error : stock must be number" << endl << "Enter the phone stock correctly:" << endl;
        cin >> stock;
    }

    // add new phone in `phones` array
    if(size == 0) {
        phones = new Mobile[1];
        phones[0].name = name;
        phones[0].brand = brand;
        phones[0].os = OS::OS_NULL;
        phones[0].ram = Ram::R_NULL;
        phones[0].storage = Storage::S_NULL;
        phones[0].stock = stock;
        phones[0].price = 0;
        phones[0].sell = 0;
        phones[0].color = Color::C_NULL;
        size +=1;
    } else {

        // save previous array in temporary array
        Mobile *temp_phones = phones;

        // create new array with new size
        phones = new Mobile[size+1];

        // push previous phones in new array
        for (int i=0; i < size; i++) {
            phones[i] = temp_phones[i];
        }

        // push new phone info in array
        phones[size].name = name;
        phones[size].brand = brand;
        phones[size].os = OS::OS_NULL;
        phones[size].ram = Ram::R_NULL;
        phones[size].storage = Storage::S_NULL;
        phones[size].stock = stock;
        phones[size].price = 0;
        phones[size].sell = 0;
        phones[size].color = Color::C_NULL;

        // increase array size
        size +=1;

        // remove temporary array
        delete[] temp_phones;
    }

    return cout_menu(phones, size);
}

/**
 * Remove `phone`.
 * then shrink `phones` array
 *
 * @param name
 * @param brand
 * @param phones
 * @param size
 *
 * @return void
 */
void remove_phone(string name, string brand, Mobile *phones,int size) {

    // check phone exists
    int index = search(name, brand, phones, size);

    if(index == -1) {
        cout << "error : phone not found." << endl;
        return cout_menu(phones, size);
    }

    // remove phone
    // shifting mobiles to the left in the right position
    // relative to the removed mobile position
    for (int i = index + 1; i < size; ++i) {
        phones[i - 1] = phones[i];
    }

    // shrink array
    // save previous array in temporary array
    Mobile *temp_phones = phones;

    // decrease array size
    size -= 1;

    // create new array with new size
    phones = new Mobile[size];

    // push previous phones in new array
    for(int i=0; i<size; i++) {
        phones[i] = temp_phones[i];
    }

    // remove temporary array
    temp_phones = NULL;
    delete temp_phones;

    // print message
    cout << "phone `" << name << "|" << brand << "` deleted successfully." << endl;

    // print main menu
    return cout_menu(phones, size);

}

/**
 * Find `phone` with name and brand.
 *
 * @param name
 * @param brand
 * @param phones
 * @param size
 *
 * @return index of `phone`, or -1 if there was no `phone`.
 */
int search(string name, string brand, Mobile *phones, int size) {

    // suppose it does not exist
    int index = -1;

    // Then we look for it
    for(int i=0; i<size; i++) {
        if((phones[i].name == name) && (phones[i].brand == brand)) {
            // save the found mobile index
            index = i;
            break;
        }
    }

    // return result
    return index;
}



/**
 * Sort `phones` array by price.
 * without duplicate array
 *
 * @param phones
 * @param size
 */
void sort_by_price(Mobile *phones, int size) {

    Mobile temp;
    int i,j;

    bool swapped = false;

    // loop through all numbers
    if(size > 1) for(i = 0; i < size-1; i++) {
        swapped = false;

        // loop through numbers falling ahead
        for(j = 0; j < size-1-i; j++) {
            if(phones[j].price < phones[j+1].price) {
                temp = phones[j];
                phones[j] = phones[j+1];
                phones[j+1] = temp;
                swapped = true;
            }
        }

        // if no number was swapped that means
        // array is sorted now, break the loop :)
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
 * @param phones
 * @param size
 */
void change_mobile_info(Mobile *phones, int size) {

    // get phone name
    string name, brand;
    cout << "Enter the phone name :" << endl;
    cin >> name;

    // get phone brand
    cout << "Enter the phone brand :" << endl;
    cin >> brand;

    // search phone
    int index = search(name, brand, phones, size );

    // if not exists print error message
    if(index == -1) {
        cout << "error : phone not found." << endl;
        return cout_menu(phones, size);
    }

    // print phone edit menu
    return edit_menu(index, phones, size);
}

/**
 * Handle menu for change `phone` details.
 *
 * @param index
 * @param phones
 * @param size
 */
void edit_menu (int index, Mobile *phones, int size)
{
    int menu;

    // print edit menu
    cout << "[1] OS" << endl;
    cout << "[2] Ram" << endl;
    cout << "[3] Storage" << endl;
    cout << "[4] Color" << endl;
    cout << "[5] Stock" << endl;
    cout << "[6] Price" << endl;
    cout << "[7] Quit to main menu" << endl;
    cin >> menu;

    // prepare for next use
    cin.clear();
    std::cin.ignore();

    // handle menu
    switch(menu) {
        case 1: // edit os
            {
                int new_value;
                cout << "Select OS for phone `" << phones[index].name << "`." << endl;
                cout << "[1] iOS" << endl;
                cout << "[2] Android" << endl;
                cout << "[3] Windows phone" << endl;
                cin >> new_value;

                // fix Enum value
                OS userValue = static_cast<OS>(new_value);

                // prepare for next use
                cin.clear();
                std::cin.ignore();

                // save
                phones[index].os = userValue;
                break;
            }
        case 2: // edit ram
            {
                int new_value;
                cout << "Select Ram for phone `" << phones[index].name << "`." << endl;
                cout << "[1] 2GB" << endl;
                cout << "[2] 4GB" << endl;
                cout << "[3] 6GB" << endl;
                cout << "[4] 8GB" << endl;
                cout << "[5] 12GB" << endl;
                cout << "[6] 16GB" << endl;
                cout << "[7] 32GB" << endl;
                cout << "[8] 64GB" << endl;
                cin >> new_value;

                // fix Enum value
                Ram userValue = static_cast<Ram>(new_value);

                // prepare for next use
                cin.clear();
                std::cin.ignore();

                // save
                phones[index].ram = userValue;
                break;
            }
        case 3: // edit storage
            {
                int new_value;
                cout << "Select Storage for phone `" << phones[index].name << "`." << endl;
                cout << "[1] 16GB" << endl;
                cout << "[2] 32GB" << endl;
                cout << "[3] 64GB" << endl;
                cout << "[4] 128GB" << endl;
                cout << "[5] 256GB" << endl;
                cout << "[6] 512GB" << endl;
                cout << "[7] 1TB" << endl;
                cout << "[8] 2TB" << endl;
                cin >> new_value;

                // fix Enum value
                Storage userValue = static_cast<Storage>(new_value);

                // prepare for next use
                cin.clear();
                std::cin.ignore();

                // save
                phones[index].storage = userValue;
                break;
            }
        case 4: // edit color
            {
                int new_value;
                cout << "Select Color for phone `" << phones[index].name << "`." << endl;
                cout << "[1] Black" << endl;
                cout << "[2] Gray" << endl;
                cout << "[3] Green" << endl;
                cout << "[4] Blue" << endl;
                cout << "[5] White" << endl;
                cout << "[6] Red" << endl;
                cout << "[7] Yellow" << endl;
                cin >> new_value;

                // fix Enum value
                Color userValue = static_cast<Color>(new_value);

                // prepare for next use
                cin.clear();
                std::cin.ignore();

                // save
                phones[index].color = userValue;
                break;
            }
        case 5: // edit stock
            {
                int new_value;
                cout << "Enter new stock for phone `" << phones[index].name << "`." << endl;
                cin >> new_value;

                // validate stock input . must be integer
                while (!std::cin.good())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');

                    cout << "error : stock must be number" << endl << "Enter the phone stock correctly:" << endl;
                    cin >> new_value;
                }

                // save
                phones[index].stock = new_value;
                break;
            }
        case 6: // edit price
            {
                int new_value;
                cout << "Enter new price for phone `" << phones[index].name << "`." << endl;
                cin >> new_value;

                // validate stock input . must be integer
                while (!std::cin.good())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');

                    cout << "error : price must be number" << endl << "Enter the phone price correctly:" << endl;
                    cin >> new_value;
                }
                phones[index].price = new_value;
                break;
            }
        case 7: // return to main menu
            return cout_menu(phones, size);
        default:
            {
                cout << "The value entered is incorrect. Please enter the menu number carefully" << endl;
                return edit_menu(index, phones, size);
            }
    }

    // print phone edit menu
    return edit_menu(index, phones, size);
}

/**
 * Change detail of `phone`.
 *
 * @param phones
 * @param size
 */
void sell_a_mobile(Mobile *phones, int size) {

    // get phone name
    string name, brand;
    cout << "Enter the phone name :" << endl;
    cin >> name;

    // get phone brand
    cout << "Enter the phone brand :" << endl;
    cin >> brand;

    // look for it
    int index = search(name, brand, phones, size );

    // print error if not exists
    if(index == -1) {
        cout << "error : phone not found." << endl;
        return cout_menu(phones, size);
    }
    else{
        // decrease stock
        phones[index].stock -= 1;

        // increase sell
        phones[index].sell += 1;
        cout << "Sales were registered successfully." << endl;

        // print phone
        phones[index].print();

        // print main menu
        return cout_menu(phones, size);
    }
}


/**
 * Print `phones` array.
 *
 * @param phones
 * @param size
 */
void print_phones(Mobile *phones, int size) {

    // Check there is a `phone`
    if(size) {

        // print array in readable format
        for (int j=0;j< size; j++) {
            phones[j].print();
        }

    } else {
        cout << "Phone has not been added yet." << endl;
    }
}

/**
 * Print `phones` detail sorted by sell.
 *
 * @param phones
 * @param size
 */
void most_sold_item(Mobile *phones, int size) {

    // copy phones in sort array
    Mobile *sorted_by_sold = phones;

    Mobile temp;
    int i,j;

    bool swapped = false;

    // loop through all phones
    if(size > 1) for(i = 0; i < size-1; i++) {
        swapped = false;

        // loop through sell falling ahead
        for(j = 0; j < size-1-i; j++) {
            if(sorted_by_sold[j].sell < sorted_by_sold[j+1].sell) {
                temp = sorted_by_sold[j];
                sorted_by_sold[j] = sorted_by_sold[j+1];
                sorted_by_sold[j+1] = temp;
                swapped = true;
            }
        }

        // if no phone was swapped that means
        // array is sorted now, break the loop.
        if(!swapped) {
            break;
        }
    }

    // print phones sorted by sell
    print_phones(sorted_by_sold, size);

    // delete sorted array
    sorted_by_sold = NULL;
    delete sorted_by_sold;

    // print main menu
    return cout_menu(phones, size);
}

/**
 * Print main menu.
 *
 * @param phones
 * @param size
 */
void cout_menu(Mobile *phones, int size) {

    int menu;

    // print menu for user
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

    // prepare for next use
    cin.clear();
    std::cin.ignore();

    // Perform the action associated with each menu item
    return handle_menu(menu, phones, size);
}

/**
 * Manage menu items
 * Call suitable function
 *
 * @param menu
 * @param phones
 * @param size
 */
void handle_menu(int menu, Mobile *phones, int size) {

    switch(menu) {
        case 1: // add a phone
            return add_phone(phones, size);
        case 2: // remove phone
            {
                string name, brand;

                // get phone name
                cout << "Enter the phone name :" << endl;
                cin >> name;

                // get phone brand
                cout << "Enter the phone brand :" << endl;
                cin >> brand;

                // remove phone
                return remove_phone(name, brand, phones, size);
            }
        case 3: // sort phones by price
            return sort_by_price(phones, size);
        case 4: //search a phone
            {
                string name, brand;

                // get phone name
                cout << "Enter the phone name :" << endl;
                cin >> name;

                // get phone brand
                cout << "Enter the phone brand :" << endl;
                cin >> brand;

                // Check there is a `phone`
                if(size) {

                    // get phone index
                    int index = search(name, brand, phones, size );

                    // print message for fail result
                    if(index == -1)
                        cout << "error : phone not found." << endl;
                    else{
                        // print phone
                        phones[index].print();
                    }
                } else {
                    cout << "Phone has not been added yet." << endl;
                }

                // print main menu
                return cout_menu(phones, size);
            }
        case 5: // change phone info
            return change_mobile_info(phones, size);
        case 6: //sell a phone
            return sell_a_mobile(phones, size);
        case 7: // print phones
            {
                // print all phones
                print_phones(phones, size);

                // print main menu
                return cout_menu(phones, size);
            }
        case 8: // print phones sorted by the most sold to the least
            return most_sold_item(phones, size);
        case 9: //exit
            {
                save_into_a_file(phones, size);
                cout << "<<<<--THANK YOU-->>>>" << endl;
                break;
            }

        default:
            {
                cout << "The value entered is incorrect. Please enter the menu number carefully" << endl;
                return cout_menu(phones, size);
            }
    }

}






