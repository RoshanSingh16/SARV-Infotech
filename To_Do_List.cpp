#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For clearing terminal
#ifdef _WIN32
    #define CLEAR_SCREEN "CLS"
#else
    #define CLEAR_SCREEN "clear"
#endif

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;
};

// Function to clear the terminal
void clearScreen() {
    system(CLEAR_SCREEN);
}

// Function to display the menu
void displayMenu() {
    cout << "\n__________________________________________\n";
    cout << "           TO-DO LIST MANAGER            \n";
    cout << "__________________________________________\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "0. Exit\n";
    cout << "__________________________________________\n";
    cout << "Enter your choice: ";
}

// Function to display the list of tasks
void displayTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "\nNo tasks in the list.\n";
    } else {
        cout << "\n__________________________________________\n";
        cout << "                TASK LIST                  \n";
        cout << "__________________________________________\n";
        for (size_t i = 0; i < todoList.size(); ++i) {
            cout << i + 1 << ". " << todoList[i].description
                 << " [" << (todoList[i].completed ? "Completed" : "Pending") << "]\n";
        }
        cout << "__________________________________________\n";
    }
}

int main() {
    vector<Task> todoList;
    int choice;

    do {
        clearScreen();
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the newline from the buffer

        switch (choice) {
            case 1: {
                // Add Task
                Task newTask;
                cout << "\nEnter task description: ";
                getline(cin, newTask.description);
                newTask.completed = false;
                todoList.push_back(newTask);
                cout << "\nTask added successfully!\n";
                cout << "\nPress ENTER to continue...";
                cin.get();
                break;
            }

            case 2: {
                // View Tasks
                clearScreen();
                displayTasks(todoList);
                cout << "\nPress ENTER to continue...";
                cin.get();
                break;
            }

            case 3: {
                // Mark Task as Completed
                if (todoList.empty()) {
                    cout << "\nNo tasks to mark as completed.\n";
                } else {
                    displayTasks(todoList);
                    int taskIndex;
                    cout << "\nEnter task number to mark as completed: ";
                    cin >> taskIndex;

                    if (taskIndex > 0 && taskIndex <= static_cast<int>(todoList.size())) {
                        todoList[taskIndex - 1].completed = true;
                        cout << "\nTask marked as completed!\n";
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                cout << "\nPress ENTER to continue...";
                cin.ignore();
                cin.get();
                break;
            }

            case 4: {
                // Remove Task
                if (todoList.empty()) {
                    cout << "\nNo tasks to remove.\n";
                } else {
                    displayTasks(todoList);
                    int taskIndex;
                    cout << "\nEnter task number to remove: ";
                    cin >> taskIndex;

                    if (taskIndex > 0 && taskIndex <= static_cast<int>(todoList.size())) {
                        todoList.erase(todoList.begin() + (taskIndex - 1));
                        cout << "\nTask removed successfully!\n";
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                cout << "\nPress ENTER to continue...";
                cin.ignore();
                cin.get();
                break;
            }

            case 0:
                cout << "\nExiting the To-Do List Manager. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
                cout << "\nPress ENTER to continue...";
                cin.ignore();
                cin.get();
                break;
        }

    } while (choice != 0);

    return 0;
}