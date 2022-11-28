#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


void checkInputValidity()                 
{
    if (cin.fail())
    {
        throw "[Error] Incorrect input!";
    }
}

void checkLoopBoundsValidity(float a, float b)   //check interval
{
    if (a >= b)
    {
        throw "[Error] Incorrect loop bounds input!";
    }
}

void checkUpperBoundValidity(int n)    //check n
{
    if (n < 2)
    {
        throw "[Error] Incorrect upper bound input!";
    }
}

void checkLoopStepValidity(int h)  //check step
{
    if (h <= 0)


    {
        throw "[Error] Incorrect step input!";
    }
}

void fileOutput(float x, float y, int n)  //print text
{
    fstream fout;
    fout.open("output.txt", std::ios::app);
    fout << "x: " << x << '\n';
    fout << "y: " << y << '\n';
    fout << "n: " << n << '\n';
    fout << "\n";
    fout.close();
}

float calculate(float x, int n) // calculate  value of y
{
    int y = 0;

    if (x <= 0)
    {
        
        for (int i = 2; i < n - 1; i++)
        {
            
            y += (x / i);
            
        }
    }
    else if (x > 0)
    {
        
        for (int i = 0; i < n - 1; i++)
        {
            int s = 0;
            for (int j = 0; j < i; j++)
            {
               
                 s += (i / x + j);
            }
            y += s;
        }
    }

    return y;
}

int main()      // enter 
{
    float a = 0;


    float b = 0;
    int h = 0;
    int n = 0;
    

    int y = 0;
    float x = 0;

    

    try
    {
        cout << "Diapasone : " << '\n';    

        cout << "Please enter \'a\', \'b\' (a < b) = "; // read check a,b
        std::cin >> a >> b;
        checkInputValidity(); 
        checkLoopBoundsValidity(a, b);   


        cout << "Enter step h = ";   //read check step
        cin >> h;
        checkInputValidity();
        checkLoopStepValidity(h);

        cout << "Enter n (n>2) = ";   // read check n
        cin >> n;
        checkInputValidity();
        checkUpperBoundValidity(n);

        x = a;

        while (x <= b)
        {


            y = calculate(x, n);
            cout << "\'x\' and \'y\' values are: " << x << ", " << y << '\n';

            fileOutput(x, y, n);

            x += h;
        }
    }
    catch (const char* ex)
    {
        cout << ex << '\n';
        return -1;
    }
    catch (...)
    {
        cout << "[Error] Unknown error occured!" << '\n';
        return -2;
    }

    return 0;
}
