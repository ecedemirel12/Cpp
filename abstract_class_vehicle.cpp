#include <iostream>
using namespace std;

class Vehicle
{
    protected:
        int numPerson;
        string line;

    public:
        Vehicle() {}

        virtual void price() = 0;
        friend ostream &operator<<(ostream &out, Vehicle &x);
};

class Minibus : public Vehicle
{
    private:
        double total;

    public:
        Minibus(int n, string l)
        {
            numPerson = n;
            line = l;
        }
        ~Minibus()
        {
            numPerson = 0;
            line = "null";
        }
        void price()
        {
            total = 5.90 * numPerson;
            cout << "Minibus price: " << total << " TL " << numPerson << " people"<< endl;
        }
};
class Boat : public Vehicle
{
    private:
        double total;

    public:
        Boat(int n, string l)
        {
            numPerson = n;
            line = l;
        }
        ~Boat()
        {
            numPerson = 0;
            line = "null";
        }
        void price()
        {
            total = 2.15 * numPerson;
            cout << "Boat price: " << total << " TL " << numPerson << " people" << endl;
        }
};

class Train : public Vehicle
{
    private:
        double total;

    public:
        Train(int n, string l)
        {
            numPerson = n;
            line = l;
        }
        ~Train()
        {
            numPerson = 0;
            line = "null";
        }
        void price()
        {
            total = 4.00 * numPerson;
            cout << "Train price: " << total << " TL " << numPerson << " people" << endl;
        }
};

void printPrice(Vehicle *ptr)
{
    ptr->price();
}

ostream &operator<<(ostream &out, Vehicle &x)
{
    out << x.line << endl;
    return out;
}

int main()
{
    int person;

    cout << "If you want to pass from Europe side to Asia side, you have three options:" << endl;
    cout << "Minibus, Train and Boat" << endl;
    cout << "How many people you are? ";
    cin >> person;

    Minibus m(person, "Taksim - Kadikoy");
    Boat b(person, "Taksim - Kadikoy");
    Train t(person, "Eminonu - Uskudar");

    printPrice(&m);  
    printPrice(&b);
    printPrice(&t);

    system("pause");
    return 0;
}
