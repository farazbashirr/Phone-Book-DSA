#include <iostream>
#include <string>

using namespace std;

struct BSTNode {
    string name;
    string phone_number;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const string& name, const string& phone_number)
        : name(name), phone_number(phone_number), left(NULL), right(NULL) {}
};

BSTNode* create_bst_node(const string& name, const string& phone_number) {
    return new BSTNode(name, phone_number);
}

BSTNode* insert_contact(BSTNode* root, const string& name, const string& phone_number) {
    if (root == NULL) {
        return create_bst_node(name, phone_number);
    }

    if (name < root->name) {
        root->left = insert_contact(root->left, name, phone_number);
    } else if (name > root->name) {
        root->right = insert_contact(root->right, name, phone_number);
    } else {
        root->phone_number = phone_number;
    }
    return root;
}

BSTNode* search_contact(BSTNode* root, const string& name) {
    if (root == NULL || root->name == name) {
        return root;
    }

    if (name < root->name) {
        return search_contact(root->left, name);
    } else {
        return search_contact(root->right, name);
    }
}

BSTNode* find_min(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

BSTNode* delete_contact(BSTNode* root, const string& name) {
    if (root == NULL) {
        return root;
    }

    if (name < root->name) {
        root->left = delete_contact(root->left, name);
    } else if (name > root->name) {
        root->right = delete_contact(root->right, name);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }

        BSTNode* temp = find_min(root->right);
        root->name = temp->name;
        root->phone_number = temp->phone_number;
        root->right = delete_contact(root->right, temp->name);
    }
    return root;
}

void update_phone_number(BSTNode* root, const string& name, const string& new_number) {
    BSTNode* contact = search_contact(root, name);
    if (contact != NULL) {
        contact->phone_number = new_number;
        cout << "Phone number for " << name << " updated to " << new_number << "." << endl;
    } else {
        cout << "Contact " << name << " not found." << endl;
    }
}

void view_contacts(BSTNode* root) {
    if (root != NULL) {
        view_contacts(root->left);
        cout << "Name: " << root->name << ", Number: " << root->phone_number << endl;
        view_contacts(root->right);
    }
}

void delete_all(BSTNode* root) {
    if (root != NULL) {
        delete_all(root->left);
        delete_all(root->right);
        delete root;
    }
}

int main() {
    BSTNode* root = NULL;
    string name, phone_number;
    int choice;

    while (true) {
        cout << "--------------------Phonebook Menu:--------------------\n";
        cout<<"\n";
        cout<<"\n";
        cout << "--------------------1. Add Contact---------------------\n";
        cout << "--------------------2. View Contacts-------------------\n";
        cout << "--------------------3. Search Contact------------------\n";
        cout << "--------------------4. Delete Contact------------------\n";
        cout << "--------------------5. Update Phone Number-------------\n";
        cout << "--------------------6. Exit----------------------------\n";
        cout<<"\n";
        cout<<"\n";
        cout << "--------------------Enter your choice:-----------------\n";
        cin >> choice;

        switch (choice) {
        case 1: system("cls");
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone_number;
            root = insert_contact(root, name, phone_number);
            cout << "Contact " << name << " saved in contact." << endl;
            break;main();system("cls");
        case 2: system("cls");
            view_contacts(root);
           break;main();system("cls");
        case 3: system("cls");
            cout << "Enter name to search: ";
            cin >> name;
            if (BSTNode* contact = search_contact(root, name)) {
                cout << "Name: " << contact->name << ", Number: " << contact->phone_number << endl;
            } else {
                cout << "Contact " << name << " not found." << endl;
            }
            break;main();system("cls");
        case 4: system("cls");
            cout << "Enter name to delete: ";
            cin >> name;
            root = delete_contact(root, name);
            cout << "Contact " << name << " deleted." << endl;
            break;main();system("cls");
        case 5: system("cls");
            cout << "Enter name to update phone number: ";
            cin >> name;
            cout << "Enter new phone number: ";
            cin >> phone_number;
            update_phone_number(root, name, phone_number);
            break;main();system("cls");
        case 6: system("cls");
            cout << "THANK YOU..." << endl;
            delete_all(root);
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("cls");
        }
    }

    return 0;
}



