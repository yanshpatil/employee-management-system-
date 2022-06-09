
#include <iostream>

#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

class employee
{
private:
    
    char name[100];
    char id[5];
    char city[100];

    char street[200];
    float da ;
    float va ;
    float basic_salary;
    float total_salary;
    float gross;
    int it;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void deleted();
};

void employee::menu() 
{
   
    while (true)
    {
        int choice;
        char x; 
        system("clear");
       
        cout << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display " << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete " << endl;
        cout << "5. Exit" << endl;

        cout << " Enter Your Choice: "; 
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\tAdd Record (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            display();
            break;
        case 3: it
            modify();
            break;
       
        case 4:
            deleted();
            break;
        case 5:
            system("clear");
            
            exit(0);
        default:
            cout << "\n\n Invalid Choice\n";
        }
    }
}

void employee::insert() 
{
    system("clear");
    int it = 1100;
    float va = 1200;
    float da;
    fstream file;
    cout << "\n" << endl;
    cout << "Employee Insert Data " << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID : ";
    cin >> id;
    cout << "\n Enter city: ";
    cin >> city;
    cout << "\n Enter Employee basic_salary: ";
    cin >> basic_salary;
    da = (0.9*basic_salary);
    total_salary = da + va + basic_salary;
    gross = total_salary - it ;

   
    cout << "\n Enter Employee street: ";
    cin >> street;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << city << " " << basic_salary << " " << street <<  "\t\t" << da << "\t\t"   << total_salary << "\t\t" << gross  << "\n";
    file.close();
}

void employee::display() 
{
    system("clear");
    int total = 1;
    fstream file;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> city >> basic_salary>>street >> da >> total_salary >> gross;
        while (!file.eof())
        {
            
            cout << total++ << ". " << name << "\t  " << id << "\t " << city << "\t   " << basic_salary<<  "\t" << street <<  "\t" << da << "\t\t"  << total_salary << "\t" << gross  ;
            file >> name >> id >> city >> basic_salary>> street >> da >>total_salary >> gross;
        }
    }
    file.close();
}

void employee::modify() // Modify data of employe
{
    system("clear");
    char checkId[5];
    int found = 0;
    int it = 1100;
    float va = 1200;
    float da;
    fstream file, file1;
    cout << "Update Data" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> city >> basic_salary>> street >> da >> total_salary >>gross;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter city: ";
                cin >> city;
                cout << "\n Enter Employee basic_salary: ";
                cin >> basic_salary;
                da = (0.9*basic_salary);
                total_salary = da + va + basic_salary;
                gross = total_salary - it ;
               
                cout << "\n Enter Employee street: ";
                cin >> street;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << city << " " << basic_salary<< " " << street <<  "\t\t" << da << "\t\t"   << total_salary << "\t\t" << gross  << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << city << " " << basic_salary<< " "  << street <<  "\t\t" << da << "\t\t"   << total_salary << "\t\t" << gross  << "\n";
            }
            file >> name >> id >> city >> basic_salary>> street >> da >> total_salary >> gross;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
   
}


void employee::deleted() 
{
    system("clear");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "Delete Employee Data" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> city >> basic_salary>>street >> total_salary >> gross;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << city << " " << basic_salary<< " " << street <<  "\t\t" << da << "\t\t"   << total_salary << "\t\t" << gross  << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> city >> basic_salary>> street >> da >> total_salary >> gross;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
     
    }
}

int main()
{
    
    employee system;
    system.menu();
    return 0;
}
        
