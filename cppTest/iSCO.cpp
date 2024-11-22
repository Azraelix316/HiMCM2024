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

float a=0;
float b=0;
float  counterAll=0;
float  counterTrue=0;
int timer=0;
int main()
{
    while (true) {  
srand(clock()); 
        if (rand() % 2==1) {
        if (rand() % 2 == 1 ) {
        a=0;
        }
        if (rand() % 2 == 0 ) {
        a=1;
        }
        } else {
        a=rand()/RAND_MAX;
        }
        if (rand() % 2==1) {
        if (rand() % 2 == 1 ) {
        b=0;
        }
        if (rand() % 2 == 0 ) {
        b=1;
        }
        } else {
        b=rand()/RAND_MAX;
        }
        if (abs(a-b)>(1/2)) counterTrue++;
        counterAll++;
        timer++;
        if (timer%1000==0) {
        cout << counterTrue/counterAll << "\n";
        }
    }

}
