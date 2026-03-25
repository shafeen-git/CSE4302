#include <bits/stdc++.h>
using namespace std;
enum etype {
    laborer, secretary, manager, accountant, executive, researcher
};
int main(){
    char choice;
    etype employee;
    cout << "Enter employee type (first letter only): ";
    cin >> choice;
    switch(choice){
        case 'l':
            employee=laborer;
            break;
        case 's':
            employee=secretary;
            break;
        case 'm':
            employee=manager;
            break;
        case 'a':
            employee=accountant;
            break;
        case 'e':
            employee=executive;
            break;
        case 'r':
            employee=researcher;
            break;
        default:
            cout<<"Invalid employee"<<"\n";
    }
    switch(employee){
        case laborer:
            cout<<"Employee type is laborer."<<"\n";
            break;
        case secretary:
            cout<<"Employee type is secretary."<<"\n";
            break;
        case manager:
            cout<<"Employee type is secretary."<<"\n";
            break;
        case accountant:
            cout<<"Employee type is accountant."<<"\n";
            break;
        case executive:
            cout<<"Employee type is executive."<<"\n";
            break;
        case researcher:
            cout<<"Employee type is researcher."<<"\n";
            break;
    }
}
