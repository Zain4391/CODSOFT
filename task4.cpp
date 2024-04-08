#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
        string task;
        bool status; // false = pending, true = completed
        Node *next;
        Node *prev;

    Node()
    {
        task = "";
        status = false;
        next = NULL;
        prev = NULL;
    }
    Node(string n)
    {
        task = n;
        status = false;
        next = NULL;
        prev = NULL;
    }
};

class ToDoList
{
    public:
    Node *head,*tail;

    ToDoList()
    {
        head = NULL;
        tail = NULL;
    }

    void AddTask(string x)
    {
        Node *newTask = new Node(x);
        if(head == NULL)
        {
            head = newTask;
            newTask->next = head;
            head->prev = newTask;
            tail = newTask;
        }
        else
        {
            tail->next = newTask;
            newTask->prev = tail;
            tail = newTask;
        }
    }

    void Mark_complete(string tsk)
    {
        Node *current = head;
        while(current->next != NULL)
        {
            if(current->task == tsk)
            {
                char opt;
                cout<<"Have you completed the task:"<<tsk<<"? [y/n]"<<endl;
                cin>>opt;
                tolower(opt);
                if(opt == 'y')
                {
                    current->status = true;
                    return;
                }
                else 
                {
                    current->status = false;
                    return;
                }
            }
            current = current->next;
        }

        cout<<"Task "<<tsk<<" not found in list."<<endl;
    }

    void Delete_task(string tsk)
    {
        if(head == NULL || tail == NULL)
        {
            cout << "The List is empty."<<endl;
            return;
        }

        Node *current = head;

        while(current != NULL)
        {
            if(current->task == tsk) //4 cases if found; either only one node in list, either head or tail or simply in the list
            {
                if(current == head && current == tail)
                {
                    delete head;
                    head=NULL;
                    tail=NULL;
                    return; 
                }

                else if(current == head)
                {
                    head = current->next;
                    head->prev = NULL;
                    delete current;
                    return;
                }

                else if(current == tail)
                {
                    tail = current->prev;
                    tail->next = NULL;
                    delete current;
                    return;
                }
                else
                {
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                    delete current;
                    return;
                }
            }
            current = current->next;
        }

        cout<<"Task "<<tsk<<" not found in list."<<endl;
    }

    void printList()
    {
        Node *current = head;
        int i = 1;

        while(current != NULL)
        {
            if(current->status)
            {
                cout<<i<<"."<< current->task<<"---"<<"Complete"<<endl;
            }
            else
            {
                cout<<i<<"."<< current->task<<"---"<<"Pending"<<endl;
            }
            current = current->next;
            i++;
        }
    }
};

int main()
{
    ToDoList list;
    char ch;
    ch = 'y';
    while(ch != 'n')
    {
        string task;
        cout<<"Enter task to add to the list: "<<endl;
        getline(cin, task);
        list.AddTask(task);
        cout<<"Would you like to add another task? (y/n): ";
        cin>>ch;
        cout<<endl;
        fflush(stdin);
    }
    list.printList();
    cout<<endl;
    fflush(stdin);
    cout<<"Enter task of which you would like to update status: "<<endl;
    string task;
    getline(cin,task);
    list.Mark_complete(task);
    list.printList();
    return 0;
}