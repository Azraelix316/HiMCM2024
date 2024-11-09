#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <cctype>
using namespace std;
int main() {
    fstream fileInput;
    //opens data file
    fileInput.open("HiMCM_Olympic_Data (1).csv",ios::in);
    //data collection
    string row,temp,line,col;
    vector<vector<string>> data;
    int rowNumber=0;
    cout << "\n\n";
    vector<string> curr;

while (getline(fileInput,line,'\n')) {
    stringstream s(line);
        // read every column and store it into col
        while (getline(s,col,','))
        {
            // add all the column data into a vector
            curr.push_back(col);
            if (col.empty()) curr.push_back("0");
        }
            data.push_back(curr);
            curr.clear();
        }

cout << data.size();
for (int i=0;i<data.size();i++) {
for (int j=0;j<data[i].size();j++) {
    cout << data[i][j] <<" ";
}
cout << "\n\n\n";
}
}
