#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string title;      
    string dueDate;    
    string description; 
    bool completed;    

    
    Task(string t, string d, string desc)
        : title(t), dueDate(d), description(desc), completed(false) {}
};


void loadFromFile(vector<Task>& tasks, const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << filename << " не может быть открыт!" << endl;
        return;
    }

    while (in) {
        string title, dueDate, description;
        bool completed;

        getline(in, title);
        if (title.empty()) break;

        getline(in, dueDate);
        getline(in, description);
        in >> completed;
        in.ignore();

        tasks.emplace_back(title, dueDate, description);
        tasks.back().completed = completed;
    }
}


void checkTaskStatus(const vector<Task>& tasks) {
    int index;
    cout << "Введите номер дела для проверки статуса: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        cout << "Дело: " << tasks[index - 1].title 
             << "\nСтатус: " << (tasks[index - 1].completed ? "Выполнено" : "Не выполнено") 
             << endl;
    } else {
        cout << "Неверный номер дела." << endl;
    }
}


int main() {
    vector<Task> tasks;

    string file = "tasks.txt";
    loadFromFile(tasks, file);

    while (true) {
        cout << "\nВыберите действие:\n"
             << "1. Проверить статус дела\n"
             << "2. Выход\n";

        int choice; 
        cin >> choice;

        switch (choice) {
            case 1:
                checkTaskStatus(tasks);
                break;
            case 2:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }
}
