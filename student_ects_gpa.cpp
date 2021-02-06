#include <iostream>
using namespace std;

class Student
{
    private:
        int id, totECTS;
        double cgpa;
        string name;
    public:
        Student()
        {
            id = 0;
            cgpa = 0;
        }
        Student(int i, string n, double c) : id(i), name(n), cgpa(c){}

        void read()
        {
            cin >> id >> name >> cgpa;
        }

        void findECTS()
        {
            if(cgpa>=3.00)
                totECTS = 48;
            else if(cgpa>=2.50)
                totECTS = 45;
            else if(cgpa>=2.00)
                totECTS = 40;
            else
                totECTS = 33;
        }

        void display()
        {
            cout << name << " can take at most " << totECTS << " credits." << endl;
        }
};

int main()
{
    Student me(123, "ece", 3.73);
    Student stu[50];

    me.findECTS();
    me.display();

    for (int i = 0; i < 50; i++)
    {
        cout << "Entre no, name and cgpa of student: ";
        stu[i].read();
        stu[i].findECTS();
        stu[i].display();
    }

    system("pause");
    return 0;
}
