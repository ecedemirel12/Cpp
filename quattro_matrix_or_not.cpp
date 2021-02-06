#include <iostream>
#include <stdlib.h> //to use random generate function
using namespace std;

template<typename R>
class Matrix
{
    private:
        R matrix[4][4];

    public:
        Matrix() 
        {
            cout << "Matrix objects has been created." << endl;
        }
        ~Matrix()
        {
            cout << "Matrix object has been destroyed." << endl;
        }

        R getElement(int a, int b)  //I want to get the elements one by one to check if the matrix quattro or not
        {
            return matrix[a][b];
        }

        friend ostream &operator<<(ostream &out, Matrix &m)
        {
    
            for(int a = 0 ; a < 4 ; a++)
            {
                for(int b = 0 ; b < 4 ; b++)
                {
                    out << m.matrix[a][b] << "     ";
                }
                out << endl;
            }
            return out;
        }

        friend istream &operator>>(istream &in, Matrix &m)
        { 
            for(int a = 0 ; a < 4 ; a++)
            {
               for(int b = 0 ; b < 4 ; b++)
                {
                    in >> m.matrix[a][b];
                }
            }
            return in;
        }
      
        friend Matrix operator+(Matrix &n1, Matrix &n2)
        {
            Matrix<R> sum;  //I created an object to store the result
            for(int a = 0 ; a < 4 ; a++)
            {
                for(int b = 0 ; b < 4 ; b++)
                {
                    sum.matrix[a][b] = n1.matrix[a][b] + n2.matrix[a][b];  
                }
            }
            return sum;
        }

        friend Matrix operator-(Matrix &n1, Matrix &n2)
        {
            Matrix<R> subs;  //I created an object to store the result
            for(int a = 0 ; a < 4 ; a++)
            {
                for(int b = 0 ; b < 4 ; b++)
                {
                    subs.matrix[a][b] = n1.matrix[a][b] - n2.matrix[a][b]; 
                }
            }
            return subs;
        }

        void checkRange() //to check the number is between 0 and 25
        {
            bool outOfRange = false;
            for(int a = 0 ; a < 4 ; a++)
            {
               for(int b = 0 ; b < 4 ; b++)
                {
                    if((matrix[a][b] < 0) || (matrix[a][b] > 25))
                    {
                        matrix[a][b] = rand() % 26; //random integer number
                        outOfRange = true;
                    }
                }
            }
            if(outOfRange == true)
                cout << "Some elements in the matrix are out of range! They were assigned a random number." << endl;
        }
};


int main()
{
    Matrix<double> mat1, mat2, result;  
    cout << "\nEnter the first matrix(4x4) elements: ";
    cin >> mat1;
    mat1.checkRange();
    cout << "Enter the second matrix(4x4) elements: ";
    cin >> mat2;
    mat2.checkRange();
    cout << "First Matrix:\n" << mat1 << endl;
    cout << "Second Matrix:\n" << mat2 << endl;
    

    char op;
    cout << "Enter an operation(+ , -): ";
    cin >> op;
    if(op == '+')
        result = mat1 + mat2;
    if(op == '-')
        result = mat1 - mat2;
    cout << result;
  
    //checking resultant matrix is quattro or not
    double sum00, sum03, sum30, sum33;
    sum00 = result.getElement(0, 1) + result.getElement(1, 0) + result.getElement(1, 1);
    sum03 = result.getElement(0, 2) + result.getElement(1, 2) + result.getElement(1, 3);
    sum30 = result.getElement(2, 0) + result.getElement(2, 1) + result.getElement(3, 1);
    sum33 = result.getElement(2, 2) + result.getElement(2, 3) + result.getElement(3, 2);
    if((sum00 == result.getElement(0, 0)) && (sum03 == result.getElement(0, 3)) && (sum30 == result.getElement(3, 0)) && (sum33 == result.getElement(3, 3)))
        cout << "The resultant matrix is a Quattro Matrix.\n" << endl;
    else
    	cout << "The resultant matrix is not a Quattro Matrix.\n" << endl;


    return 0;
}
