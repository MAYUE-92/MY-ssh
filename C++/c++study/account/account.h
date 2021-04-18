#include <cstring>
class Account
{
    private:
        int a_num;
        char* a_name;
        float money;
    public:
        void deposit();
        void withdraw();
        void show();
        Account(int in_num, char* in_name, float in_money)
        {
            a_num = in_num; money = in_money;
            a_name = in_name;
        };
};