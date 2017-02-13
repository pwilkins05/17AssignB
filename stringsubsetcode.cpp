#include <string>
#include <iostream>

using namespace std;

void recPrintAllSubsets( string input, string output )
{
    int length = input.length();
    if (length == 0)
    {
        cout << output << endl;
                                    //BUG: Does not return anything
    }
    recPrintAllSubsets(input.substr(1, length-1), output);
    recPrintAllSubsets(input.substr(1, length-1), input[0] + output);

}

int main()
{
    string input;
    cout << "give me a string" << endl;
                                            //Nowhere to receive a string input! (input has now been initialized and can be received! -Liam)
    getline(cin, input);

    cout << input << endl;

                                            //Still needs to call the print function somehow

    return 0;

}

