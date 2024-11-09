#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <random>
using namespace std;
int main() {
    fstream fileInput;
    //opens data file
    fileInput.open("HiMCM_Olympic_Data (1).csv",ios::in);
    vector<double> data;
    //data collection
    vector<string> curr;
    string row,temp,line,col;
while (fileInput >> temp) {
        getline(fileInput, line);
        stringstream row(line);
    curr.clear();
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(row, col, ','))
        {
            // add all the column data
            // of a row to a vector
            curr.push_back(col);
        }
        for (int i=0;i<curr.size();i++) {
        cout << curr[i] <<" ";
        }
        cout << "\n";
}

}