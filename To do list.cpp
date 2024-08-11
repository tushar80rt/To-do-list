#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;

    Task(const std::string& desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << "\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks to display.\n";
        } else {
            std::cout << "Your Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description 
                          << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
            }
        }
    }

    void markTaskAsCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isCompleted = true;
            std::cout << "Task " << taskNumber << " marked as completed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            std::cout << "Task removed: " <<
