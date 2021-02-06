#include <iostream>
using namespace std;

class Distance
{
    private:
        double m, cm;
    public:
        Distance(double a = 0.0, double b = 0.0) : m(a), cm(b){}

        void setD(double d)
        {
            m = int(d);
            cm = (d*100) - (m*100);
        }

        double getm()
        {
            return m;
        }
        double getcm()
        {
            return cm;
        }

        friend Distance operator+(Distance &, Distance &);
        friend Distance operator-(Distance &, Distance &);
};

Distance operator+(Distance &a, Distance &b)
{
    Distance r;
    r.m = a.m + b.m;
    r.cm = a.cm + b.cm;
    if(r.cm > 100)
    {
        r.m += int(r.cm / 100);
        r.cm -= (int(r.cm / 100)) * 100;
        return r;
    }
    else
        return r;
}

Distance operator-(Distance &a, Distance &b)
{
    Distance r;
    double cm1, cm2;
    cm1 = ((a.m) * 100) + a.cm; //to compute in cm 
    cm2 = ((b.m) * 100) + b.cm;
    if(cm2 > cm1)
    {
        r = (cm2 - cm1) / 100;  //to convert to meter
    }
    else
    {
        r = (cm1 - cm2) / 100;
    }
    return r;
}

double mathMult(Distance &a)
{
    double x = 2*(a.getm());
    double y = 2*(a.getcm());
    double r;
    if(y>100)  //to control overflow
    {
        x += (int)(y / 100);   
        y -= ((int)(y / 100)* 100);  // to compute the remain part after the addition of overflow part to the meter
        r = x + (y / 100);  //compute the total distance in meter
    }
    else
    {
        r = x + (y / 100); //compute the total distance in meter
    }
    return r;
}

int main()
{
    Distance a, b;
    a.setD(2.6);
    double result = mathMult(a);
    cout << result << endl;


    system("pause");
    return 0;
}