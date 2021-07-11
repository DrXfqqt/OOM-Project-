#ifndef USER_H
#define USER_H

#include<string>
using std::string;

class user
{
    public:
        void user_menu();
        void u_signup();
        void u_login();
        void u_reset();
        void u_display();
    protected:

    private:
        string user_un; //username
        string user_pw; //password

};

#endif // USER_H
