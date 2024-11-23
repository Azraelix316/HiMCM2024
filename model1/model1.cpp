#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <random>

//used to determine initial training speed, but adapts later
double trainingSpeed=1;
using namespace std;

//function to check if a string is a number
bool is_number(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}


//calculates sum of squares given a data set and the linear regression
double ssqr(vector<vector<double>> data, vector<double> coefficients) {
double residuals=0;
for (int i=0;i<data.size();i++) {
    //final regression with interaction terms
    double predicted=(data[i][5]/2028)*(data[i][0]*coefficients[0] + coefficients[1]*data[i][1] + coefficients[2]*data[i][2]+coefficients[3]*data[i][3]/5000000.0 + coefficients[4]*data[i][4]/2028+coefficients[5])+coefficients[6];
    residuals+=pow(predicted-data[i][6],2);
}
return residuals;
}
//returns sum of squares, used to evaulate error

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
            //pushes the vector into a 2d array data
            curr.clear();
        }

//used to determine where to input the coefficients
int yearsBeginColumn=8;
int dataBeginColumn=3;


//data treatment
for (int i=1;i<data.size();i++) {
if (data[i][0]=="0") {
data[i][0]=data[i-1][0];
}
if (data[i][dataBeginColumn]!="-") {
data[i][dataBeginColumn]="1";
} else {
data[i][dataBeginColumn]="0";
}
if (data[i][1]=="0") {
data[i][1]=data[i][0];
}
for (int j=yearsBeginColumn;j<data[i].size();j++) {
if (!is_number(data[i][j])) {
data[i][j]="0";
}
}
}

//creates every testcase for every year
vector<vector<double>> testcases;
vector<string> years{"1896","1900","1904","1906","1908","1912","1920","1924","1928","1932","1936","1948","1952","1960","1964","1968","1972","1976","1980","1984","1988","1992","1996","2000","2004","2008","2012","2016","2020","2024","2028"};
vector<double> coefficients{0,0,0,0,0,0};
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


//training
//creates the last sum of squares, and checks to see if there's improvement
    double lastssqr;
        bool improvement=true;
while (trainingSpeed>0.00001) {
    improvement=true;
    while (improvement) {
        improvement=false;
    for (int j=0;j<coefficients.size();j++) {
        //calculates the last sum of squares to compare
        lastssqr=ssqr(testcases,coefficients);
        coefficients[j]+=trainingSpeed;
        //modifies current coefficient up or down until it can't improve
        while (lastssqr>ssqr(testcases,coefficients)) {
        lastssqr=ssqr(testcases,coefficients);
        coefficients[j]+=trainingSpeed;
        //flags an improvement
        improvement=true;
        }
        //keeps coefficient the same
        coefficients[j]-=trainingSpeed;
        lastssqr=ssqr(testcases,coefficients);  
        coefficients[j]-=trainingSpeed; 
        while (lastssqr>ssqr(testcases,coefficients)) {
        lastssqr=ssqr(testcases,coefficients);
        coefficients[j]-=trainingSpeed;
        //flags an improvement
        improvement=true;
        }
        //keeping coefficient the same
        coefficients[j]+=trainingSpeed;

        //ups training speed
        trainingSpeed+=trainingSpeed*0.01;
    }  
    } 
    //displays current coefficients and error, used to plug into excel to get r-squared, etc.
    cout << "\n" << ssqr(testcases,coefficients) << "\n";
    for (int i=0;i<coefficients.size();i++) {
    cout << coefficients[i]<< ",";
    } 
    //halves training speed, to increase precision
    trainingSpeed=trainingSpeed/2.0;
    cout << "\n"<< "Training Speed:" << trainingSpeed << "\n";
}
}