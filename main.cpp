#include <iostream>
#include "json.hpp"
#include <fstream>
#include <cstdlib>
using namespace std;
using json = nlohmann::json;

// ==================== Struct ====================
struct Task {
    int id;
    string description;
    bool isDone;
};

// ==================== Function Prototype ====================
void displayMenu();

void processChoice(string tasksFile);

void viewTasks(string tasksFile);

void addTask(string tasksFile);

void deleteTask(string tasksFile);

// ==================== main() ====================
int main() {
    displayMenu();
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        processChoice("tasks.json");
    }
    return 0;
}

// ==================== Function Declaration ====================
void displayMenu() {
    cout << "======= Chao mung den voi Task Tracker! ======= \n";
    cout << "Nhap chu so tuong ung voi chuc nang ban muon su dung \n";
    cout << "1 - Them tac vu \n";
    cout << "2 - Xoa tac vu \n";
    cout << "3 - Xem danh sach tac vu \n";
    cout << "4 - Danh dau hoan thanh tac vu \n";
    cout << "0 - Thoat \n";
}


void processChoice(string tasksFile) {
    cout << ">> Chon: ";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choice) {
        case(0):
            cout << "Cam on ban da su dung Task Tracker! Hen gap lai!";
            exit(0);
        case 1:
            addTask(tasksFile);
            break;
        case 2:
            deleteTask(tasksFile);
            break;
        case 3:
            viewTasks(tasksFile);
            break;
    }
}


void addTask(string tasksFile) {
    ifstream inFile(tasksFile);
    json tasksJson;
    inFile >> tasksJson;
    inFile.close();

    string description;
    bool isDone;
    cout << "Nhap mo ta cho cong viec: ";
    getline(cin, description);
    cout << "Nhap trang thai cho cong viec: ";
    cin >> isDone;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    tasksJson.push_back({
        {"id", tasksJson.size() + 1},
        {"description", description},
        {"isDone", isDone}
    });

    ofstream outFile(tasksFile);
    outFile << tasksJson.dump(4);
    outFile.close();
}


void viewTasks(string tasksFile) {
    ifstream inFile(tasksFile);
    json tasksJson;
    inFile >> tasksJson;
    inFile.close();

    for (int index = 0; index < tasksJson.size(); index++) {
        cout << "Ma so: " << tasksJson[index]["id"]
             << " | " << tasksJson[index]["description"]
             << " | " << "Trang thai: " << (tasksJson[index]["isDone"] ? "Hoan thanh" : "Chua Xong") << endl;
    }
}

void deleteTask(string tasksFile) {
    ifstream inFile(tasksFile);
    json tasksJson;
    inFile >> tasksJson;
    inFile.close();

    int idToRemove;
    cout << "Nhap ID cong viec ban muon xoa: ";
    cin >> idToRemove;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (auto iterator = tasksJson.begin(); iterator != tasksJson.end(); iterator++) 
        if ((*iterator)["id"] == idToRemove) {
            tasksJson.erase(iterator);
            break;
        }

    ofstream outFile(tasksFile);
    outFile << tasksJson;
    outFile.close();
}