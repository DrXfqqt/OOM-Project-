#include "user.h"
#include <iostream>
#include <fstream>
using namespace std;

string u_un,u_pw;

void user::user_menu(){
    start:
system("clear");
 int choice; 
cout<<"\n\n\t\t\t\t\t\tControl Panel"; 
cout<<"\n\n\n\t 1. Display Record ";
 cout<<"\n\t 2. Reset Password"; 
cout<<"\n\t 3. Exit"; 
cout<<"\n\n\t\t Please Enter Your Choice : ";
 cin>>choice;

		switch(choice)
		{
			case 1:{
                 u_display();
                break;
            }
				break;
            case 2:{
                 u_reset();
                break;
            }
			case 3:
				 goto end;

			default:
				cout<<"\n\n Invalid Value...Please try Again...";
		}
		goto start;
		end:
		    ;
}

void user::u_signup()
{
    system("clear");
     cout << "\n\n\t\t\t USER SIGNUP ";
     cout << "\n\n\t ENTER USERNAME : ";
     cin >> user_un;
     cout << "\t ENTER PASSWORD : ";
     cin >> user_pw;
     ofstream ad("user.txt", ios::out | ios::app);
     ad << " " << user_un << " " << user_pw << "\n";
     ad.close();
     cout << "\n\n\t\t\t USER SUCCESSFULLY ADDED \n";
     cin.ignore();
     cin.get();
}

void user::u_login()
{
    system("clear");
    fstream ad;
		int found=0;

		cout<<"\n\n\t\t\t\tUSER LOGIN";
		ad.open("user.txt",ios::in);
		if(!ad)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
                        cin.get();
            goto end;
		}

		cout<<"\n\n\n\t Enter Username: ";
		cin>>u_un;
		cout<<"\n\n\t Enter Password: ";
		cin>>u_pw;
		ad>>user_un>>user_pw;

		while(!ad.eof())
		{
			if(u_un == user_un && u_pw == user_pw)
			{
			  found++;
			}
			ad>>user_un>>user_pw;
		}

		ad.close();

		if(found == 0){
		cout<<"\n\n\t\t WRONG USERNAME OR PASSWORD\n";
		cin.ignore();
		cin.get();
 		}
		else{
            user_menu();
		}
   end:
;
}


void user::u_reset()
{
   system("clear");
		string n_passwd,o_passwd;
		fstream file,file1;
		cout<<"\n\n\t\t\t\tRESET PASSWORD";
		cout<<"\n\n\n\t Enter OLD password : ";
		cin>>o_passwd;
		file.open("user.txt",ios::in);

		file1.open("temp.txt",ios::app|ios::out);
		file>>user_un>>user_pw;
		while(!file.eof())
		{
			if( o_passwd == user_pw )
			{
				system("clear");
				cout<<"\n\n\t\t\t\tReset Password";
				cout<<"\n\n\n\t Enter NEW password : ";
				cin>>n_passwd;
				  file1<<" "<<user_un<<" "<<n_passwd<<"\n";
				cout<<"\n\n\n\tPASSWORD CHANGED SUCCESSFULLY\n\n";
				cin.ignore();
				cin.get();
			}
			else{
                file1<<" "<<user_un<<" "<<user_pw<<"\n";
			}
			file>>user_un>>user_pw;
		}
		file.close();
		file1.close();
		remove( "user.txt" );
		rename( "temp.txt" , "user.txt" );
}


void user::u_display()
{

    system("clear");
        string a1,a2,a3,a4,a5;
		fstream file;
		cout<<"\n\n\t\t\t\tDisplay Record";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
                         cin.ignore();
			cin.get();
			user_menu();
		}
		file>>a1>>a2>>a3>>a4>>a5;
		while(!file.eof())
		{
		    if( a2 == u_un )
             break;
			file>>a1>>a2>>a3>>a4>>a5;

		}
		        cout<<"\n\n\n\n Employee ID : "<<a1;
			cout<<"\n\n\t\tEmployee Name : "<<a2;
			cout<<"\n\n Employee Basic Salary : "<<a3;
			cout<<"\n\n\t\tEmployee Designation : "<<a4;
			cout<<"\n\n Employee Group ID : "<<a5;
		file.close();
cin.ignore();
cin.get();
    }
