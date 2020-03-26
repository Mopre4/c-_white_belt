#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c, D;
    bool Dev_by_zero = true;
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;

    if (a == 0){Dev_by_zero = false;}
    if (D == 0 && Dev_by_zero){
        cout << (-b - sqrt(D) ) / (2 * a) << endl;
    } else if (D > 0 && Dev_by_zero){
        cout << (-b + sqrt(D) ) / (2 * a) <<
         " " << (-b - sqrt(D) ) / (2 * a) << endl;
    } else if (D < 0)  {
        cout << " " <<endl;
    } else if ( b != 0){
        cout << -c / b << endl;
    }
    else cout << " "<<endl;

    return 0;
}
