#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    std::cout << "TO-DO LIST MANAGER" << std::endl;

    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Select an option: ";

        int option;
        std::cin >> option;

        if (option == 1) {
            Task newTask;
            std::cin.ignore(); 
            std::cout << "Enter task description: ";
            std::getline(std::cin, newTask.description);
            newTask.completed = false;
            tasks.push_back(newTask);
            std::cout << "Task added.\n";
        } else if (option == 2) {
            if (tasks.empty()) {
                std::cout << "No tasks to display.\n";
            } else {
                displayTasks(tasks);
            }
        } else if (option == 3) {
            if (tasks.empty()) {
                std::cout << "No tasks to mark as completed.\n";
            } else {
                displayTasks(tasks);
                std::cout << "Enter the task number to mark as completed: ";
                int taskNumber;
                std::cin >> taskNumber;
                if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
                    tasks[taskNumber - 1].completed = true;
                    std::cout << "Task marked as completed.\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
            }
        } else if (option == 4) {
            if (tasks.empty()) {
                std::cout << "No tasks to remove.\n";
            } else {
                displayTasks(tasks);
                std::cout << "Enter the task number to remove: ";
                int taskNumber;
                std::cin >> taskNumber;
                if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    std::cout << "Task removed.\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
            }
        } else if (option == 5) {
            std::cout << "Exiting the program.\n";
            break;
        } else {
            std::cout << "Invalid option. Please select a valid option.\n";
        }
    }

    return 0;
}

