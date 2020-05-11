#include <iostream>

using namespace std;

class Incognizable{
public:
    Incognizable(){};
    Incognizable(int new_c, int new_d = 0){
        c = new_c;
        d = new_d;
    }
private:
    int c,d;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}