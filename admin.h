#ifndef ADMIN_H
#define ADMIN_H

#include"Employee.h"
#include<string>

using std::string;

class admin : public Employee
{
    public:
        void a_signup();
        void a_login();

    protected:

    private:
        string admin_un;  //username
        string admin_pw;  //password
};

#endif // ADMIN_H
