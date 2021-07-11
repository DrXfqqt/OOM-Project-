#include "admin.h"
#include "Employee.h"
#include <iostream>
#include <fstream>

using namespace std;

void admin::a_signup()
{
     system("clear");
     cout << "\n\n\t\t\t ADMIN SIGNUP " ;
     cout << "\n\n\t ENTER USERNAME : " ;
     cin >> admin_un ;
     cout << "\t ENTER PASSWORD : " ;
     cin >> admin_pw ;

     ofstream ad("admin.txt", ios::out | ios::app);
     ad << " " << admin_un << " " << admin_pw << "\n";
     ad.close();

     cout << "\n\n\t\t\t USER SUCCESSFULLY ADDED \n" ;

     cin.ignore();
     cin.get();
}

void admin::a_login()
{
    system("clear");

    ifstream ad;
    ad.open("admin.txt", ios::in);
    if (!ad)
        a_signup();
    else
    {

        string  a_un, a_pw;
        cout << "\n\n\t\t\t\t\t\t ADMIN LOGIN \n\n" ;
        cout << "\n\n\t Enter Username : ";
        cin >> a_un;
        cout<< "\n\n\t Enter Password : ";
        cin >> a_pw;
        ad >> admin_un >> admin_pw;

        if (a_un == admin_un && a_pw == admin_pw)
        {
            Employee emp;
            emp.admin_menu();
        }
        else
        {
            printf( "\n\n\t\t Wrong Username or Password\n");
         cin.ignore();  
	 cin.get();
        }
    }
    ad.close();
}
