//used for initial HiMCM training
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>  
using namespace std;  
int main() {

    vector<double> xValues;
    vector<double> tValues;
    vector<double> vels;
    float x=0;
    float xVel=0;
    float t=0;
    float dT=0.2;
    float kp=0.2;
    float s=90;
    float sum=0;
    float ki=0.00035;
    float kd=0.0;
    float last=1.0;
    float lastVel=0;
    float lastError=0;
    while (fabs(x-s)>1 && t<100) {
    xValues.push_back(x);
    tValues.push_back(t);
    vels.push_back(xVel);
    float derivative=((lastError)-(x-s));
    t+=dT;
    sum+=(s-x);
    if (fabs(lastError-(x-s))*5>fabs(x-s)) {
    xVel=kp*(s-x)*dT;
    xVel+=sum*ki*dT;
    xVel+=derivative*kd;
    } else {
    xVel=lastVel;
    }
    lastError=(x-s);
    last=x;
    lastVel=xVel;
    x+=xVel;
    }
    cout << xVel;
    fstream fout;
    fout.open("data.csv", ios::out);
    fout << "t-values" << "," << "x-values" << "\n";
    for (int i=0;i<xValues.size();i++) {
    fout << tValues[i] << "," << xValues[i] << "\n";
    }
    fout.close();
}

