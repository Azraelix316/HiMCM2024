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
double b_year=-1;
//step through, calculate residuals for every year
//store best residual and year.
for (int year=4;year<data[0].size();year++) {
double current_residuals=0;
double lessAverage=0;
double largeAverage=0;
for (int row=1;row<data.size()-3;row++) {
for (int col=4;col<data[row].size();col++) {
if (col < year) {
lessAverage+=stod(data[row][col]);
} else {
largeAverage+=stod(data[row][col]);
}
}
}
cout << "RAW:" << largeAverage <<" "<<year<<" ";
lessAverage*=(1.00/((year-4)*71));
largeAverage*=(1.00/(71*(data[0].size()-(year))));
cout << lessAverage <<" "<<largeAverage<< " " <<data[0].size()-4 <<" " <<1.00/(data[0].size()-4);
for (int row=1;row<data.size()-3;row++) {
for (int col=4;col<data[row].size();col++) {
if (col < year) {
current_residuals+=pow(stod(data[row][col])-lessAverage,2);
} else {
current_residuals+=pow(stod(data[row][col])-largeAverage,2);
}
}
}
cout << " "<<current_residuals;
cout << "\n";
if (current_residuals<=b_residuals) {
b_residuals=current_residuals;
b_year=year;
}
}
cout << b_residuals << " " << b_year;
}


class tree {
    tree() {
    }
    double computeSplittingPoint(int variableIndex) {
    return 0;
    }
};