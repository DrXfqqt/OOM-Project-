#include "Employee.h"
#include "user.h"
#include <iostream>
#include <fstream>

using namespace std;

void Employee::admin_menu(){

 start:
		system("clear");
		int x;
		cout<<"\n\n\t\t\t\t\t\tControl Panel";
		cout<<"\n\n\n\t 1. Add User";
		cout<<"\n\t 2. Insert Record";
		cout<<"\n\t 3. Display Record";
		cout<<"\n\t 4. Search Record";
		cout<<"\n\t 5. Modify Record";
		cout<<"\n\t 6. Delete Record";
		cout<<"\n\t 7. Group Record";
		cout<<"\n\t 8. Show All Groups";
		cout<<"\n\t 9. Net Salary";
		cout<<"\n\t 10. Exit";
		cout<<"\n\n\t\t Please enter your Choice : ";
		cin>>x;
		switch(x)
		{
			case 1:{
			    user u;
			    u.u_signup();
				break;
			}
            case 2:
                insert();
                break;
			case 3:
				display();
				break;
			case 4:
                search();
				break;
			case 5:
				modify();
				break;
			case 6:
				del();
				break;
			case 7:
				group();
				break;
			case 8:
                show_group();
				break;
			case 9:
				net_salary();
				break;
			case 10:
				goto end;
			default:
				cout<<"\n\n Invalid value...Please try again...";
		}
		goto start;
		end:
		    ;

}



void Employee :: insert()
	{
		system("clear");
		fstream temp;
		temp.open("emp.txt",ios::in);
		if(!temp)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			admin_menu();
		}
		temp>>emp_id>>name>>basic_sal>>desig>>grp_id;
		while(!temp.eof())
		{
			temp>>emp_id>>name>>basic_sal>>desig>>grp_id;
		}
		temp.close();
		int test_id,found=0;
		fstream file,file1;
		cout<<"\n\n\t\t\t\tInsert Record";
		++emp_id;
		cout<<"\n\n\n Employee ID : "<<emp_id;
		cout<<"\n\n\t\tEmployee Name : ";
		cin>>name;
		cout<<"\n\n Employee Basic Salary : ";
		cin>>basic_sal;
		cout<<"\n\n\t\tEmployee Designation : ";
		cin>>desig;
		cout<<"\n\n Employee Group ID : ";
		cin>>grp_id;
		file.open("emp.txt",ios::out|ios::app);
		file<<" "<<emp_id<<" "<<name<<" "<<basic_sal<<" "<<desig<<" "<<grp_id<<"\n";
		file.close();
		file1.open("group.txt",ios::out|ios::app);
		file1<<" "<<grp_id<<" "<<emp_id<<" "<<basic_sal<<"\n";
		file1.close();
		file.open("groupid.txt",ios::in);
		if(!file)
		{
			file1.open("groupid.txt",ios::app|ios::out);
			file1<<" "<<grp_id<<"\n";
			file1.close();
		}
		else
		{
			file>>test_id;
			while(!file.eof())
			{
				if(test_id == grp_id)
		 		found++;
				file>>test_id;
			}
			file.close();
			if(found == 0)
			{
				file1.open("groupid.txt",ios::app|ios::out);
				file1<<" "<<grp_id<<"\n";
				file1.close();
			}
		}
		cout<<"\n\n\n\t\t\tNew Record Inserted Successfully...";
		cin.ignore();
                cin.get();
	}

	void Employee::display()
	{
		system("clear");
		fstream file;
		cout<<"\n\n\t\t\t\tDisplay Record";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		while(!file.eof())
		{
			cout<<"\n\n\n\n Employee ID : "<<emp_id;
			cout<<"\n\n\t\tEmployee Name : "<<name;
			cout<<"\n\n Employee Basic Salary : "<<basic_sal;
			cout<<"\n\n\t\tEmployee Designation : "<<desig;
			cout<<"\n\n Employee Group ID : "<<grp_id;
			file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		}
		file.close();
		cin.ignore();
		cin.get();
	}

	void Employee::search()
	{
		system("clear");
		fstream file;
		int emp_idd,found=0;
		cout<<"\n\n\t\t\t\tSearch Record";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		cout<<"\n\n Employee ID For Search : ";
		cin>>emp_idd;
		file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		while(!file.eof())
		{
			if(emp_idd == emp_id)
			{
			system("cls");
			cout<<"\n\n\t\t\t\tSearch Record";
			cout<<"\n\n Employee ID : "<<emp_id;
			cout<<"\n\n\t\tEmployee Name : "<<name;
			cout<<"\n\n Employee Basic Salary : "<<basic_sal;
			cout<<"\n\n\t\tEmployee Designation : "<<desig;
			cout<<"\n\n Employee Group ID : "<<grp_id;
			found++;
			}
			file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		}
		file.close();
		if(found == 0)
		cout<<"\n\n Employee ID Can't Found...";
		cin.ignore();
                cin.get();
	}

	void Employee::modify()
	{
		system("clear");
		int sall,test_id,found=0;
		string name1,desig1;
		fstream file,file1,file2,file3;
		cout<<"\n\n\t\t\t\tModify Record";
		file.open("emp.txt",ios::in);
		file1.open("group.txt",ios::in);
		if(!file || !file1)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		cout<<"\n\n Employee ID For Modify : ";
		cin>>test_id;
		file2.open("emp1.txt",ios::app|ios::out);
		file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				system("clear");
				cout<<"\n\n\t\t\t\tModify Record";
				cout<<"\n\n\n Employee Name : ";
				cin>>name1;
				cout<<"\n\n\t\tEmployee Basic Salary : ";
				cin>>sall;
				cout<<"\n\n Employee Designation : ";
				cin>>desig1;
				file2<<" "<<emp_id<<" "<<name1<<" "<<sall<<" "<<desig1<<" "<<grp_id<<"\n";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<basic_sal<<" "<<desig<<" "<<grp_id<<"\n";
			}
			file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");
		rename("emp1.txt","emp.txt");
		file3.open("group1.txt",ios::app|ios::out);
		file1>>grp_id>>emp_id>>basic_sal;
		while(!file1.eof())
		{
			if(test_id == emp_id)
				file3<<" "<<grp_id<<" "<<emp_id<<" "<<basic_sal<<"\n";
			else
				file3<<" "<<grp_id<<" "<<emp_id<<" "<<basic_sal<<"\n";
			file1>>grp_id>>emp_id>>basic_sal;
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt","group.txt");
		if(found == 0)
		cout<<"\n\n Couldn't Find Employee ID...";
		else
		cout<<"\n\n\t\t\t Record Modified Successfully...";
		cin.ignore();
		cin.get();
	}
	void Employee::del()
	{
		system("clear");
	int test_id,found=0;

		fstream file,file1,file2,file3;
		cout<<"\n\n\t\t\t\tDelete Record";
		file.open("emp.txt",ios::in);
		file1.open("group.txt",ios::in);
		if(!file || !file1)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		cout<<"\n\n Employee ID To Delete : ";
		cin>>test_id;
		file2.open("emp1.txt",ios::app|ios::out);
		file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				cout<<"\n\n Record Deleted Successfully...";
				cin.ignore();
				cin.get();
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<basic_sal<<" "<<desig<<" "<<grp_id<<"\n";
			}
			file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");
		rename("emp1.txt","emp.txt");
		file3.open("group1.txt",ios::app|ios::out);
		file1>>grp_id>>emp_id>>basic_sal;
		while(!file1.eof())
		{
			if(test_id != emp_id)
				file3<<" "<<grp_id<<" "<<emp_id<<" "<<basic_sal<<"\n";
			file1>>grp_id>>emp_id>>basic_sal;
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt","group.txt");
		if(found == 0)
		cout<<"\n\n Couldn't Find Employee ID...";
		cin.ignore();
		cin.get();
	}

	void Employee::group()
	{
		system("clear");
		fstream file;
		cout<<"\n\n\t\t\t\tGroup Record";
		file.open("group.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		file>>grp_id>>emp_id>>basic_sal;
		while(!file.eof())
		{
			cout<<"\n\n\n\n Employee Group ID : "<<grp_id;
			cout<<"\n\n\t\t Employee ID : "<<emp_id;
			cout<<"\n\n Employee Basic Salary : "<<basic_sal;
			file>>grp_id>>emp_id>>basic_sal;
		}
		file.close();
		cin.ignore();
		cin.get();
	}

	void Employee::show_group()
	{
		system("clear");
		int test_id,emp_count=0,sal_count=0,emp_total=0,sal_total=0;
		fstream file,file1;
		cout<<"\n\n\t\t\t\tShow All Groups";
		file.open("groupid.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		file>>test_id;
		while(!file.eof())
		{
			file1.open("group.txt",ios::in);
			file1>>grp_id>>emp_id>>basic_sal;
			while(!file1.eof())
			{
				if(test_id == grp_id)
				{
					emp_count++;
					sal_count += basic_sal;
					emp_total++;
					sal_total += basic_sal;
				}
				file1>>grp_id>>emp_id>>basic_sal;
			}
			file1.close();
			cout<<"\n\n\n\n Employee Group ID : "<<test_id;
			cout<<"\n\n\t\t Total Employee : "<<emp_count;
			cout<<"\n\n Total Basic Salary : "<<sal_count;
			emp_count=0;
			sal_count=0;
			file>>test_id;
		}
		file.close();
		cout<<"\n\n\n\n Over All Employee : "<<emp_total;
		cout<<"\n\n\t\t Over All Basic Salary : "<<sal_total;
		cin.ignore();
		cin.get();
	}

	void Employee :: net_salary()
	{
	    system("clear");
	     int allowence,TA,DA,tax;
         int netsalary;
         int totaldeduction;
         fstream file;
		int emp_idd,found=0;
		cout<<"\n\n\t\t\t\t Net Salary";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			cin.ignore();
			cin.get();
			admin_menu();
		}
		cout<<"\n\n Employee ID : ";
		cin>>emp_idd;
		file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		while(!file.eof())
		{
			if(emp_idd == emp_id)
			{
			system("clear");
            cout<<"\n\nEnter the allowence of employee :  ";
            cin>>allowence;
            cout<<"\n\nEnter the TA : ";
            cin>>TA;
            cout<<"\n\nEnter the DA :";
            cin>>DA;
            cout<<"\n\nEnter the tax : ";
            cin>>tax;

           TA  =  basic_sal*TA/100;
           DA  =  basic_sal*DA/100;
           tax = basic_sal*tax/100;

           totaldeduction = TA+DA+tax;
           netsalary =  basic_sal+allowence-totaldeduction;
           cout<<"\n\n\n\t\t Employee Net Salary  :"<<netsalary;
            found++;
			}
			file>>emp_id>>name>>basic_sal>>desig>>grp_id;
		}
		file.close();
		if(found == 0)
		cout<<"\n\n Couldn't Find Employee ID...";
		cin.ignore();
		cin.get();
	}
