#include <iostream>
#include "admin.h"
#include "user.h"

using std::cin;
using std::cout;

void Welcome_Page();

int main()
{
    Welcome_Page();

    return 0;
}

void Welcome_Page()
{
    system("clear");
    int choice;
    cout << "\n\n\t\t\t\t\t\t MANAGEMENT LOGIN \n\n";
    cout << "\t 1. Admin Login \n\t 2. User Login \n\t 3. Exit \n\n\n\t\t Please Enter Your Choice : ";
    cin >> choice;

    switch (choice)
    {

        case 1:{
                 admin ad;
                 ad.a_login();
                 Welcome_Page();

                 break;
               }

        case 2:{
                 user us;
                 us.u_login();
                 Welcome_Page();

                 break;
               }

        case 3:
                 exit(0);
    }
}
