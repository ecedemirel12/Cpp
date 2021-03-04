#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
    public:
        virtual void getdata() {}
        virtual void putdata() {}
};

class Professor : public Person
{
   private:
        int publications, cur_id;
        int static ID;

    public:
        void getdata()
        {
            cout << "Enter name, age and publications: ";
            cin >> name >> age >> publications;
            ID++;
            cur_id = ID;
        }
        void putdata()
        {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        } 
};
int Professor::ID = 0;

class Student : public Person
{
    private:
        int marks[6], cur_id;
        int static ID;

    public:
        void getdata()
        {
            cout << "Enter name, age and the marks of the student: ";
            cin >> name >> age;
            for(int i = 0 ; i < 6 ; i++)
            {
                cin >> marks[i]; 
            }
            ID++;
            cur_id = ID;
        }
        void putdata()
        {
            int sum = 0;
            for(int i = 0 ; i < 6 ; i++)
            {
                sum += marks[i];
            }
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
};
int Student::ID = 0;


int main()
{
    int n, who;
    cout << "Enter the number of people: ";
    cin >> n;
    Person *per[n];

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Enter 1 for Professor, or enter 2 for Student: ";
        cin >> who;
        if(who == 1)
        {
            per[i] = new Professor;
            per[i]->getdata();
        }
        else if(who == 2)
        {
            per[i] = new Student; 
            per[i]->getdata(); 
        } 
    }
    for(int i = 0 ; i < n ; i++)
        per[i]->putdata();

    system("pause");
    return 0;
}