#include <iostream>
#include <string>
using namespace std;

class HealthCenterInfo
{
    private:
        string name, surname;
        int age, starvationRate;
    
    public:
        HealthCenterInfo(string n = "", string s = "", int a = 0)
        {
            starvationRate = 100;
            name = n;
            surname = s;
            age = a;
        }
        ~HealthCenterInfo()
        {
            cout << name << " " << surname << " quits the health center." << endl;
        }
        
        string getName()
        {
            return name;
        }
        string getSurname()
        {
            return surname;
        }
        string getFullName()
        {
            return (name + " " + surname);  //I used string concatenation to get the full name
        }
        int getStarvationRate()
        {
            return starvationRate;
        }
        void setStarvationRate(int x)
        {
            starvationRate = x;
        }
        bool checkStarvation()  
        {
            if(starvationRate < 20)
                return true;
            else
                return false;
        }
};

class Patient : public HealthCenterInfo
{
    private:
        string diseaseName;

    public:
        Patient(string n = "", string s = "", int age = 0, string d = "") : HealthCenterInfo(n, s, age), diseaseName(d) {}
        ~Patient()
        {
            cout << getFullName() << " was discharged!." << endl;
        }

        void setDiseaseName(string d)
        {
            diseaseName = d;
        }
        bool checkStarvation()
        {
            if(getStarvationRate() < 50)
                return true;
            else
                return false;
        }
        void takeACare()
        {
            setStarvationRate(getStarvationRate() - 15);
            if(checkStarvation() == true)
                cout << "Patient: " << getFullName() << " is hungry!!!" << endl;
        }
};

class Employee : public HealthCenterInfo
{
    private:
        int employeeid;

    public: 
        Employee(string n = "", string s = "",int age = 0, int e = 0) : HealthCenterInfo(n, s, age), employeeid(e) {}
        ~Employee()
        {
            cout << getFullName() << " quits the job in the health center." << endl;
        }

        int getEmployeeid()
        {
            return employeeid;
        }
        bool checkStarvation()
        {
            if(getStarvationRate() < 20)
                return true;
            else
                return false;        
        }
        void checkPatient(Patient &p)  
        {
            setStarvationRate(getStarvationRate() - 5);
            cout << "The patient named " << p.getFullName() << " is checking." << endl;
            if(p.checkStarvation() == true)
                cout << p.getFullName() << " is starving!";
        }
};

class Doctor : public Employee
{
    public:
        Doctor(string n = "", string s = "",int age = 0, int e = 0) : Employee(n, s, age, e) {}
        ~Doctor()
        {
            cout << getFullName() << " quits being a Doctor in this center!" << endl;
        }
        
        void checkPatient(Patient &p) //I used reference because I want to modify the original object
        {
            setStarvationRate(getStarvationRate() - 5);  //setting the doctor's starvation rate
            cout << "The patient named " << p.getFullName() << " is checking." << endl;
            p.takeACare();
            cout << getFullName() << " gives medicine to patient." << endl;
            if(p.checkStarvation() == true)  //in the homework, whether the starvation rate is patient's starvation rate or employee's starvation rate is not quite clear, so I assume that it is patient's rate
                cout << p.getFullName() << " is starving!" << endl;
        }
};   
        
class Nurse : public Employee
{
    public:
        Nurse(string n = "", string s = "",int age = 0, int e = 0) : Employee(n, s, age, e) {}
        ~Nurse()
        {
            cout << getFullName() << " quits being a Nurse in this center!" << endl;
        }
        
        void checkPatient(Patient &p)  //I used reference because I want to modify the original object
        {
            setStarvationRate(getStarvationRate() - 10);  //setting the nurse's starvation rate
            cout << "The patient named " << p.getFullName() << " is checking." << endl;
            p.takeACare();
            cout << getFullName() << " took care of patient." << endl;
            if(p.checkStarvation() == true)  //in the homework, whether the starvation rate is patient's starvation rate or employee's starvation rate is not quite clear, so I assume that it is patient's rate
                cout << p.getFullName() << " is starving!" << endl;
        }
};

int main()
{
    Doctor doc("David", "Tennant", 49, 18971);
    Nurse nur("Jodie", "Whittaker", 38, 171982);
    Patient p("Matt", "Smith", 37, "xyzxyz");

    cout << "All people in this health center:" << endl;
    cout << doc.getFullName() << endl;
    cout << nur.getFullName() << endl;
    cout << p.getFullName() << endl;

    cout << "\nAll employees works:\n" << endl;
    for(int i = 0 ; i < 5 ; i++)
    { 
        cout << nur.getFullName() << endl;
        nur.checkPatient(p);
        cout << endl;
        cout << doc.getFullName() << endl;
        doc.checkPatient(p);
        cout << endl;
    }

    return 0;
}
