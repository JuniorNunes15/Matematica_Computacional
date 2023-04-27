#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int b, p, min, max;

    cin >> b >> p >> min >> max;

    int aux = max-1;
    int i = 0;
    int result = 0;
    int numeradoMax, denominadorMax, numMin, denMin;

    while(i <= p-1) {
        result = result + (b-1) * (pow(b, aux));
        aux--;
        i++;
    }

    if(p > max) {
        aux = max;
        result = result + (b-1) * (pow(b, aux));
        numeradoMax = result * (pow(b,p-max-1));
    }
    else
        numeradoMax = result;
    if(p > max)
        denominadorMax = pow(b,(p-max));
    else
        denominadorMax = 1;
    
    numMin = 1;
    denMin = pow(b,(max+1));

    cout << numeradoMax << "/" << denominadorMax << endl;
    cout << numMin << "/" << denMin << endl;

    return 0;
}
