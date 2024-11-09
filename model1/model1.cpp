#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
//#include <random>
//#include <typeinfo>

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
            if (!col.empty()) {
            curr.push_back(col);
            } else {
curr.push_back("0");
            }
        }
            data.push_back(curr);
            curr.clear();
        }

for (int i=0;i<data.size();i++) {
if (data[i][0]=="0") {
data[i][0]=data[i-1][0];
}
if (data[i][1]=="0") {
data[i][1]=data[i][0];
}
for (int j=0;j<data[i].size();j++) {
    cout << data[i][j] <<" ";
}
cout << "\n";
}
}
