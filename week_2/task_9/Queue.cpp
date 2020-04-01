#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main(){
    int q;
    cin >> q;
    string request;
    vector <int> persons;
    for(size_t i = 0; i < q; i++){
       cin >> request;
       if(request == "COME"){
           int k;
           cin >> k;
           persons.resize(persons.size() + k, 0);//заполним нулями, нули будут спокойными
       }
       else if (request == "WORRY"){
           int i;
           cin >> i;
           persons[i] = 1; // единицы будут нервными
       }
       else if (request == "QUIET"){
           int i;
           cin >> i;
           persons[i] = 0;
       }
       else if(request == "WORRY_COUNT"){
           cout << count(persons.begin(), persons.end(), 1); //считаем количество нервных
       }
    }
    return 0;
}