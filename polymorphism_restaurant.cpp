#include <iostream>
using namespace std;

class Restaurant
{
    protected:
        int hamburger, toast;
        string name;

    public:
        Restaurant() {}

        virtual void fee() {}
        friend ostream &operator<<(ostream &out, Restaurant &x);
};

class ItalianRestaurant : public Restaurant
{
    private:
        int pizza;
        double total;

    public:
        ItalianRestaurant(int h, int t, int p, string n) 
        {
            hamburger = h;
            toast = t;
            pizza = p;
            name = n;
        }

        void fee()
        {
            total = (hamburger * 8.40) + (toast * 2.50) + (pizza * 15.54);
            cout << "Italian Restaurant fee is: " << total << endl;
        }
};

class TurkishRestaurant : public Restaurant
{
    private:
        int kebap;
        double total;

    public:
        TurkishRestaurant(int h, int t, int k, string n) 
        {
            hamburger = h;
            toast = t;
            kebap = k;
            name = n;
        }

        void fee()
        {
            total = (hamburger * 8.40) + (toast * 2.50) + (kebap * 6.50);
            cout << "Turkish Restaurant fee is: " << total << endl;
        }
};

class ChineseRestaurant : public Restaurant
{
    private:
        int sushi;
        double total;

    public:
        ChineseRestaurant(int h, int t, int s, string n) 
        {
            hamburger = h;
            toast = t;
            sushi = s;
            name = n;
        }

        void fee()
        {
            total = (hamburger * 8.40) + (toast * 2.50) + (sushi * 15.50);
            cout << "Chinese Restaurant fee is: " << total << endl;
        }
};

ostream &operator<<(ostream &out, Restaurant &x)
{
    out << x.name << " Restaurant" << endl;
    return out;
}

void printMenuCost(Restaurant *a)
{
    a->fee();
}

int main()
{
    int pizza, kebap, hamburger, toast, sushi;

    cout << "Please enter the numbe of items" << endl;
    cout << "I will calculate the price for Italian, Turkish and Chinese Restaurant" << endl;

    cout << "How many pizza?: ";
    cin >> pizza;
    cout << "How many toast?: ";
    cin >> toast;
    cout << "How many hamburger?: ";
    cin >> hamburger;
    cout << "How many kebap?: ";
    cin >> kebap;
    cout << "How many sushi?: ";
    cin >> sushi;

    cout << endl;
    ItalianRestaurant i(hamburger, toast, pizza, "Italiano");
    cout << i;
    printMenuCost(&i);
    cout << endl;

    TurkishRestaurant t(hamburger, toast, kebap, "Turk Mutfagi");
    cout << t;
    printMenuCost(&t);
    cout << endl;

    ChineseRestaurant c(hamburger, toast, sushi, "Chino");
    cout << c;
    printMenuCost(&c);
    cout << endl;

    system("pause");
    return 0;
}