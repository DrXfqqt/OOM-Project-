#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

using std::string;

class Employee
{
	private:
		int emp_id,basic_sal,grp_id;
		string name,desig;
	public:
		void admin_menu();
		void insert();
		void display();
		void search();
		void modify();
		void del();
		void group();
		void show_group();
		void net_salary();
        void u_display();
};

#endif // EMPLOYEE_H
