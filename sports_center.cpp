#include <iostream>
#include <string>
using namespace std;

class Hours
{   
    private:
        int hours, minutes;
 
    public:
        Hours(int h = 0 , int m = 0) : hours(h), minutes(m) {}

        //to access the hours and minutes variables from outside
        int getH()
        {
            return hours;
        }
        int getM()
        {
            return minutes;
        }

        friend ostream &operator<<(ostream &out, Hours &a);
        friend istream &operator>>(istream &in, Hours &b);
};

class Member
{
    protected: //because derived class "player" should access the variables
        string id, memberName;
        Hours total;
        int tot_min;

    public:
        Member(string i = "", string n = "") : id(i), memberName(n) {}  

        int calcMin(Hours in, Hours out, bool &proper) //there is "proper" variable to check the check in and check out time is proper
        {
            proper = true;
            if (out.getH() > in.getH() && out.getM() >= in.getM())
            {
                total = Hours(out.getH() - in.getH(), out.getM() - in.getM()); //I used the "Hours" costructor to keep total hours and minutes in "total" variable
                tot_min = (total.getH() * 60) + total.getM();
                return tot_min;
            }
            else if (out.getH() >= in.getH() && out.getM() < in.getM())
            {
                total = Hours((out.getH() - 1) - in.getH(), (out.getM() + 60) - in.getM()); 
                tot_min = (total.getH() * 60) + total.getM();
                return tot_min;
            }
            else
            {
                cout << "Please enter the time properly." << endl;
                proper = false; //if the check in and check out time is not propar, this will return false as a parameter
            }
        }
};

class Player : public Member
{
    private:
        string speacialty;

    public:
        Player(string i = "", string n = "", string s = "") : speacialty(s), Member(i, n) {}

        void print()
        {
            cout << "Id of the member is " << id << endl;
            cout << "Name of the member is " << memberName << endl;
            cout << "Specialty of the member is " << speacialty << endl;
        }
};

ostream &operator<<(ostream &out, Hours &a)
{
    out << a.hours << ":" << a.minutes;
    return out;
}

istream &operator>>(istream &in, Hours &b)
{
    in >> b.hours >> b.minutes;
    return in;
}

int main()
{
    Player p("917537", "Stephen Curry", "Player");
    Hours p_in, p_out;
    int totalMin;
    bool isProper; //to check the check in and check out time is proper

    p.print();

    cout << "Enter the check in time of the member :" << endl;
    cin >> p_in;
    cout << "Enter the check out time of the member :" << endl;
    cin >> p_out;

    cout << "Check in and check out times are " << p_in << " and " << p_out << endl;

    totalMin = p.calcMin(p_in, p_out, isProper);
    if (isProper == true)  //if check in and check out time is proper, thne we can print the total minutes
        cout << "The total time member stays in the sports center is " << totalMin << " minutes." << endl;

    system("pause");
    return 0;
}