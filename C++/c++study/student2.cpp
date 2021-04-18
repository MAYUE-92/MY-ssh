#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char name[10],ID[11];
    int age; double score;
    char *memo;
public:
    void show();
    Student(char *pname, char *pID, int in_age, double in_score,char*pmemo)
    {
        strcpy(name,pname); strcpy(ID,pID);
        age = in_age; score = in_score;

        int len = strlen(pmemo);
        if(len<=0) memo=0;
        else
        {
            memo = new char[len+1];
            strcpy(memo, pmemo);
        }
    };
    Student(Student&obj)//定义拷贝结构函数，使用深度拷贝的方法。
    {
        strcpy(name,obj.name); strcpy(ID,obj.ID);
        age = obj.age; score = obj.score;

        int len = strlen(obj.memo);
        if(len<=0) memo=0;
        else
        {
            memo = new char[len+1];
            strcpy(memo, obj.memo);
        }
    };  
    ~Student() //析构函数，用于销毁动态分配的内存
    {
        if(memo!=0) delete []memo;
    };
};
void Student::show()
{
    cout<<"学生姓名："<<name<<endl;
    cout<<"学生ID："<<ID<<endl;
    cout<<"学生年龄："<<age<<endl;
    cout<<"学生成绩："<<score<<endl;
    cout<<"学生情况："<<memo<<endl;
}

int main()
{
    char name[]="张三";
    char ID[] = "1400500001";
    char memo[] = "成绩优秀";
    Student obj(name,ID,19,95,memo);
    Student obj_n(obj);
    obj_n.show();
    return 0;
}