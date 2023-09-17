#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product
{
    string product_ID;
    string product_NAME;
    int product_PRICE = 0;
};

void add_product(vector<Product>& product,string ID, string name, int price) {
    Product newProduct;
    newProduct.product_ID = ID;
    newProduct.product_NAME = name;
    newProduct.product_PRICE = price;

    product.insert(product.begin(), newProduct);
}

void find_product(vector<Product>& product, string search_name) {
    bool found = false;

    for (const Product& p : product) {
        if (p.product_NAME == search_name) {
            cout << "Product ID: " << p.product_ID << endl;
            cout << "Product name: " << p.product_NAME << endl;
            cout << "Product price: " << p.product_PRICE << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "NO PRODUCT FOUND" << endl;
    }
}

void delete_product(vector<Product>& product) {
    if (!product.empty()) {
        cout << "Delete the first member" << endl;
        product.erase(product.begin());
    }
    else {
        cout << "NO PRODUCT TO DELETE" << endl;
    }
}

int main() {
    vector<Product> product;
    int option;
    bool exitProgram = false;
    string ID;
    string name;
    int price;

    while (!exitProgram) {
        cout << "Please select one of these options" << endl;
        cout << "1. Add new product to the first position of the price list" << endl;
        cout << "2. Find the product" << endl;
        cout << "3. Delete the first product" << endl;
        cout << "-1. End the program" << endl;
        cout << "My option: ";
        cin >> option;

        switch (option) {
        case 1:
        {
            int i = 1;
            bool exitInput = false;
            while (!exitInput) {
                cout << "Product number " << i << endl;
                cout << "Enter product name (type 'exit' to go back): ";
                cin.ignore();
                getline(cin, name);

                if (name == "exit") {
                    exitInput = true;
                    break;
                }

                cout << "Enter product ID: " << endl;
                cin >> ID;

                cout << "Enter product price: ";
                cin >> price;
                add_product(product, ID, name, price);
                i++;
            }
        }
        break;

        case 2:
        {
            string search_name;
            bool exitInput = false;

            while (!exitInput) {
                cout << "Enter the name of the product (type 'exit' to go back): ";
                cin >> search_name;

                if (search_name == "exit") {
                    exitInput = true;
                    break;
                }

                find_product(product, search_name);
            }
        }
        break;

        case 3:
            delete_product(product);
            break;

        case -1:
            exitProgram = true;
            cout << "End the program" << endl;
            break;

        default:
            cout << "Wrong option, please reinput your choice" << endl;
            break;
        }
    }

    return 0;
}
