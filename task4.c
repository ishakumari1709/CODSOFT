#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task task;
        task.description = description;
        task.completed = false;
        tasks.push_back(task);
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
            return;
        }

        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << std::endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            std::cout << "Task removed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter option: ";

        int option;
        std::cin >> option;

        if (option == 1) {
            std::cin.ignore(); // Clear newline from previous input
            std::cout << "Enter task description: ";
            std::string description;
            std::getline(std::cin, description);
            todoList.addTask(description);
        } else if (option == 2) {
            todoList.viewTasks();
        } else if (option == 3) {
            std::cout << "Enter task index to mark as completed: ";
            size_t index;
            std::cin >> index;
            todoList.markTaskCompleted(index);
        } else if (option == 4) {
            std::cout << "Enter task index to remove: ";
            size_t index;
            std::cin >> index;
            todoList.removeTask(index);
        } else if (option == 5) {
            break;
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
