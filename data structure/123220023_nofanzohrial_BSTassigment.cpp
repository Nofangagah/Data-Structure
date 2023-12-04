#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

struct Node {
    string name;
    int patientID;
    int lengthOfStay;
    Node* left;
    Node* right;

    Node(string n, int id, int length) : name(n), patientID(id), lengthOfStay(length), left(NULL), right(NULL) {}
};

Node* insert(Node* anjay, string name, int patientID, int lengthOfStay) {
    if (anjay == NULL) {
        return new Node(name, patientID, lengthOfStay);
    }

    if (lengthOfStay < anjay->lengthOfStay) {
        anjay->left = insert(anjay->left, name, patientID, lengthOfStay);
    } else if (lengthOfStay > anjay->lengthOfStay) {
        anjay->right = insert(anjay->right, name, patientID, lengthOfStay);
    }

    return anjay;
}

void inorderTraversal(Node* anjay) {
    if (anjay != NULL) {
        inorderTraversal(anjay->left);
        cout << "Name: " << anjay->name << ", Patient ID: " << anjay->patientID << ", Length of Stay: " << anjay->lengthOfStay << endl;
        inorderTraversal(anjay->right);
    }
}

void preorderTraversal(Node* anjay) {
    if (anjay != NULL) {
        cout << "Name: " << anjay->name << ", Patient ID: " << anjay->patientID << ", Length of Stay: " << anjay->lengthOfStay << endl;
        preorderTraversal(anjay->left);
        preorderTraversal(anjay->right);
    }
}

void postorderTraversal(Node* anjay) {
    if (anjay != NULL) {
        postorderTraversal(anjay->left);
        postorderTraversal(anjay->right);
        cout << "Name: " << anjay->name << ", Patient ID: " << anjay->patientID << ", Length of Stay: " << anjay->lengthOfStay << endl;
    }
}

Node* findMin(Node* anjay) {
    while (anjay->left != NULL) {
        anjay = anjay->left;
    }
    return anjay;
}

Node* remove(Node* anjay, int lengthOfStay) {
    if (anjay== NULL) {
        return anjay;
    }

    if (lengthOfStay < anjay->lengthOfStay) {
        anjay->left = remove(anjay->left, lengthOfStay);
    } else if (lengthOfStay > anjay->lengthOfStay) {
        anjay->right = remove(anjay->right, lengthOfStay);
    } else {
        if (anjay->left == NULL) {
            Node* temp = anjay->right;
            delete anjay;
            return temp;
        } else if (anjay->right == NULL) {
            Node* temp = anjay->left;
            delete anjay;
            return temp;
        }

        Node* temp = findMin(anjay->right);
        anjay->name = temp->name;
        anjay->patientID = temp->patientID;
        anjay->lengthOfStay = temp->lengthOfStay;
        anjay->right = remove(anjay->right, temp->lengthOfStay);
    }
    return anjay;
}


void back() {
	string backtomenu;
    bool backmenu = true;
    backmenu = true;
    cout << "kembali?(y/n) : ";
    cin >> backtomenu;
    while (backmenu) {

        if (backtomenu == "y") {
            system("cls");
            backmenu = false;
        } else if (backtomenu == "n") {
            system("cls");
            cout << "Terima kasih." << endl;
            exit(0);
        } else {
            cout << "invalid input, cuma y/n ajah" << endl;
            cin >> backtomenu;
        }
    }
	
	
}
int main() {
    Node* anjay = NULL;
    int choice;

    do {
        cout << "\t\tMENU\n";
        cout << "\t\t1. Add Data\n";
        cout << "\t\t2. Show Data\n";
        cout << "\t\t3. Delete Data\n";
        cout << "\t\t4. Exit\n";
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
				system("cls");
                string name;
                int patientID, lengthOfStay;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient ID: ";
                cin >> patientID;
                cout << "Enter length of stay: ";
                cin >> lengthOfStay;
                anjay = insert(anjay, name, patientID, lengthOfStay);
                back();
                break;
            }
            case 2:
            system("cls");
                if (anjay == NULL) {
                    cout << "BST is empty." << endl;
                } else {
                    cout << "In-order traversal:" << endl;
                    inorderTraversal(anjay);
                    cout << endl;

                    cout << "Pre-order traversal:" << endl;
                    preorderTraversal(anjay);
                    cout << endl;

                    cout << "Post-order traversal:" << endl;
                    postorderTraversal(anjay);
                    cout << endl;
                }
                back();
                  cin.ignore(); 
                break;
            case 3: {
				system("cls");
                if (anjay == NULL) {
                    cout << "BST is empty." << endl;
                } else {
                    int lengthOfStay;
                    cout << "Enter length of stay to delete: ";
                    cin >> lengthOfStay;
                    anjay = remove(anjay, lengthOfStay);
                    cout << "Node with length of stay " << lengthOfStay << " deleted." << endl;
                }
                back();
                break;
            }
            case 4:
                cout << "aku pergi.\n";
                exit(0);
                break;
            default:
                cout << "Invalid choice man.\n";
                
        }

    } while (choice != 4);

    return 0;
}
