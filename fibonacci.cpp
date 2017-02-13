#include <iostream>

using namespace std;

int getFib(int in);   //BUG: Input took non integer numbers

//For the uninitiated:
//The Fibonacci sequence is a sequence of numbers starting with 1, 1 where every following number is the sum of the last two.
//The Fibonacci sequence should go 1, 1, 2, 3, 5, 8, 13, 21...

//Please mark any bugs that have been fixed as such.
//BUG: Output is incorrect. (found and changed)
//BUG: The input takes non-integer numbers.
//TODO: Implement separate recursive implementation of getFib(). (Those familiar with recursion in C++ can have fun with this if they'd like.)

int main()
{
    int in;  //BUG: Input took non-integer numbers. changed float to int
    int out;

    cout << "Hello! I can tell you any nth fibonacci number, calculating it by looping." << endl << "Which number do you want to know?" << endl;
    cin >> in; //Why is this statement accepting non-integer numbers? Why does input 3 give a different answer than 3.1?
    cout << endl << "Calculating...";
    out = getFib(in);
    cout << endl << out;
}

int getFib(int in)  //BUG: Input took non-integer numbers.
{
    int out = 1;
    int lastOut = 1;
    int temp;
    for(int i = 2; i < in; i++)
    {
        out = out + lastOut; //
        temp = out;          //Something here is causing the final output to be incorrect.
        lastOut = temp;      //
    }
    return out;
}
