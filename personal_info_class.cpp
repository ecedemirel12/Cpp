#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Student
{
    private:
        string fname, lname;
        int a, s;

    public:
        void setAge(int a)
        {
            this->a = a;
        }
         void setStandard(int s)
        {
            this->s = s;
        }
         void setFirstName(string f)
        {
            fname = f;
        }
         void setLastName(string l)
        {
            lname = l;
        }
        int getAge()
        {
            return a;
        } 
        int getStandard()
        {
            return s;
        }
        string getLastName()
        {
            return lname;
        }
        string getFirstName()
        {
            return fname;
        }
        string toString()
        {
            string str;
            str = to_string(a) + ',' + fname + ',' + lname + ',' + to_string(s);
            return str;
        } 
};

int main() 
{
    int age, standard;
    string firstName, lastName;
    
    cin >> age >> firstName >> lastName >> standard;
    
    Student st;
    st.setAge(age);
    st.setStandard(standard);
    st.setFirstName(firstName);
    st.setLastName(lastName);
    
    cout << st.getAge() << endl;
    cout << st.getLastName() << ", " << st.getFirstName() << endl;
    cout << st.getStandard() << endl;
    cout << endl;
    cout << st.toString() << endl;

    system("pause");
    return 0;
}