#include <iostream>
#include "json.hpp"
#include <vector>
#include <fstream>
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

void processChoice(vector<Task> tasks);

void viewTasks(vector<Task> tasks);

void addTask();

// ==================== main() ====================
int main() {

    vector<Task> tasks;
    displayMenu();
    processChoice(tasks);
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
    cout << ">> Chon: ";
}

void processChoice(vector<Task> tasks) {
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case(0):
            cout << "Cam on ban da su dung Task Tracker! Hen gap lai!";
            break;
        case 1:
            addTask();
        case 2:
            // Xoa tac vu
        case 3:
            viewTasks(tasks);
    }
}

void addTask() {
    ifstream inFile("tasks.json");
    json tasksJson;
    inFile >> tasksJson;
    inFile.close();

    string description;
    bool isDone;
    cout << "Nhap mo ta cho cong viec: ";
    getline(cin, description);
    cout << "Nhap trang thai cho cong viec: ";
    cin >> isDone;
    tasksJson.push_back({
        {"id", tasksJson.size() + 1},
        {"description", description},
        {"isDone", isDone}
    });

    ofstream outFile("tasks.json");
    outFile << tasksJson.dump(4);
    outFile.close();
}

void viewTasks(vector<Task> tasks) {
    for (int i = 0; i < tasks.size(); i++) {
        cout << "Ma so: " << tasks[i].id
             << " | " << tasks[i].description
             << " | " << "Trang thai: " << (tasks[i].isDone ? "Hoan thanh" : "Chua Xong") << endl;
    }
}
