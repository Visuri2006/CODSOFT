#include <bits/stdc++.h>
using namespace std;

struct Task
{
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask()
{
    Task t;
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, t.name);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added successfully.\n";
}

void viewTasks()
{
    if (tasks.size() == 0)
    {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i].name << " [";
        if (tasks[i].completed)
            cout << "Completed";
        else
            cout << "Pending";
        cout << "]\n";
    }
}

void markCompleted()
{
    int num;
    cout << "Enter task number to mark as completed: ";
    cin >> num;

    if (num > 0 && num <= tasks.size())
    {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}

void removeTask()
{
    int num;
    cout << "Enter task number to remove: ";
    cin >> num;

    if (num > 0 && num <= tasks.size())
    {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed successfully.\n";
    }
    else
    {
        cout << "Invalid task number.\n";
    }
}

int main(){
    int choice;

    do
    {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}