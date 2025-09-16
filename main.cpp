#include <iostream>
#include <vector>
using namespace std;


struct Task {
    int id;
    string description;
    bool isDone;
};


void welcomingMessage() {
    cout << "======= Chao mung den voi Task Tracker! ======= \n";
    cout << "Nhap chu so tuong ung voi chuc nang ban muon su dung \n";
    cout << "1 - Them tac vu \n";
    cout << "2 - Xoa tac vu \n";
    cout << "3 - Xem danh sach tac vu \n";
    cout << "4 - Danh dau hoan thanh tac vu \n";
    cout << "0 - Thoat \n";
    cout << ">> Chon: ";
}


void viewTasks(vector<Task> tasks) {
    for (int i = 0; i < tasks.size(); i++) {
        cout << "ID: " << tasks[i].id
             << " | " << tasks[i].description
             << " | " << "IsDone?: " << (tasks[i].isDone ? "Yes" : "No") << endl;
    }
}


int main() {
//    welcomingMessage();
    vector<Task> tasks;

    Task T1 = {1, "Trieu hoi quai vat", false};
    Task T2 = {2, "Hoc C++", true};
    tasks.push_back(T1);
    tasks.push_back(T2);

    viewTasks(tasks);

    return 0;
}
