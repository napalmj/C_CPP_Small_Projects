/*************************************************
* Name: Nathaniel
*
* Description: I wrote this program for my wife.				
*			   It analyzes if the test results are mixed or single.
*
**************************************************/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//structure for storing data

int main()
{
    int SIZE = 276, countMix = 0, countOnly = 0, sampleNum[SIZE];
    int PVY[SIZE], PVS[SIZE];
    
    //gets lab data from file and stores data
    ifstream inFile("LabData.txt"); //data file will need to be changed
    
    string line = "";
    getline(inFile, line);
    for(int i = 0; i< SIZE; i++)
    {
        inFile >> sampleNum[i];
        inFile >> PVY[i];
        inFile >> PVS[i];
    }
    
    inFile.close();
    

    //
    for(int i = 0; i< SIZE; i++)
    {
    if(PVS[i] != 0 && PVY[i] != 0)
        {
            cout << sampleNum[i] << " is PVS only.\n";
            countOnly++;
        }
        else
            {
            cout << sampleNum[i] << " is Mix\n";
            countMix++;
            }
    }
    
    cout << endl;
    cout << "Total of Mixed: " << countMix << endl;
    cout << "Total of PVS only: " << countOnly << endl;
    
    return 0;
}