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

double ssqr(vector<vector<double>> data, vector<double> coefficients) {
double residuals;
for (int i=0;i<data.size();i++) {
    double results=0;
    for (int j=0;j<coefficients.size();j++) {
    results+=coefficients[j]*data[i][j];
    }
}
return 0.00;
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
int yearsBeginColumn=5;

for (int i=1;i<data.size();i++) {
if (data[i][0]=="0") {
data[i][0]=data[i-1][0];
}
if (data[i][1]=="0") {
data[i][1]=data[i][0];
}
for (int j=yearsBeginColumn;j<data[i].size();j++) {
if (!is_number(data[i][j])) {
data[i][j]="0";
}
//cout << stod(data[i][j]) << " ";
}
}

vector<vector<double>> testcases;
int dataBeginColumn=4;
vector<string> years{"1896","1900","1904","1906","1908","1912","1920","1924","1928","1932","1936","1948","1952","1960","1964","1968","1972","1976","1980","1984","1988","1992","1996","2000","2004","2008","2012","2016","2020","2024","2028"};
vector<double> coefficients;
//ax1+bx2
for (int row=1;row<data.size();row++) {
    for (int col=yearsBeginColumn;col<data[row].size()-1;col++) {
    vector<string> input(data[row].begin()+dataBeginColumn,data[row].begin()+yearsBeginColumn);
    input.push_back(years[col-yearsBeginColumn]);
    input.push_back(data[row][col]);
    vector<double> dInput;
    for (auto & element : input) {
    dInput.push_back(stod(element));
    }    
    testcases.push_back(dInput);
    }
    }
for (int i=0;i<testcases.size();i++) {
for (int j=0;j<testcases[i].size();j++) {
cout << testcases[i][j] <<" ";
}
cout << "\n";
}


}