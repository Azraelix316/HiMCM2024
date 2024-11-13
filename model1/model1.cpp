#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
//#include <random>

using namespace std;
bool is_number(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
int main() {
    fstream fileInput;
    //opens data file
    fileInput.open("HiMCM_Olympic_Data (1).csv",ios::in);
    //data collection
    string row,temp,line,col;
    vector<vector<string>> data;
    int rowNumber=0;
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

for (int i=1;i<data.size();i++) {
if (data[i][0]=="0") {
data[i][0]=data[i-1][0];
}
if (data[i][1]=="0") {
data[i][1]=data[i][0];
}
for (int j=4;j<data[i].size();j++) {
if (!is_number(data[i][j])) {
data[i][j]="0";
}
//cout << stod(data[i][j]) << " ";
}

}
//4th element (el 3) is when events start
//best residuals
double b_residuals=10000000000;
double DV=0;
vector<vector<double>> variableOptions;
//this loop loops through all the variable options
for (int variableColumn=0;variableColumn<variableOptions.size();variableColumn++) {
for (int variableSetting=0;variableSetting<variableOptions.size();variableSetting++) {

//loops through all testcases/rows
double lessAverage=0;
double greaterAverage=0;
for (float row=0;row<data.size();row++) {
//if data in the variable column < current add to less average, else greater 
if (data[row][variableColumn]<variableOptions[variableColumn][variableSetting]) {
lessAverage+=data[row][DV]/data.size().0;
} else {
greaterAverage+=data[row][DV]/data.size().0;
}
}




}
}
}

class grader() {
 public:
 int conditionColumn;
}