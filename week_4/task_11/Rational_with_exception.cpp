#include <iostream>
#include <numeric>
#include <ostream>
#include <istream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int new_numerator, int new_denominator) {
        // Реализуйте конструктор
        if (new_denominator == 0) {
            // бросаем исключение в случае нулевого знаменателя
            stringstream ss;
            ss << "Invalid argument";
            throw runtime_error(ss.str());
        }
        int tmp = gcd(new_numerator, new_denominator);
        numerator = new_numerator/tmp;
        denominator = new_denominator/tmp;
        if (numerator == 0 ){
            denominator = 1;
        } else if(numerator < 0 && denominator < 0){
            numerator = abs(numerator);
            denominator = abs(denominator);
        } else if(numerator > 0 && denominator < 0 ){
            numerator = - numerator;
            denominator = abs(denominator);
        }
    }
    int Numerator() const {
        // Реализуйте этот метод
        return numerator;
    }
    int Denominator() const {
        // Реализуйте этот метод
        return denominator;
    }
private:
    // Добавьте поля
    int numerator;
    int denominator;
};

Rational operator+(const Rational& lhs, const Rational& rhs){
    return(Rational(lhs.Numerator()*rhs.Denominator()
                    +rhs.Numerator()*lhs.Denominator(),
                    rhs.Denominator()*lhs.Denominator()));
}

Rational operator-(const Rational& lhs, const Rational& rhs){
    return(Rational(lhs.Numerator()*rhs.Denominator()
                    -rhs.Numerator()*lhs.Denominator(),
                    rhs.Denominator()*lhs.Denominator()));
}

Rational operator*(const Rational&lhs, const Rational& rhs){
    return(Rational(lhs.Numerator()*rhs.Numerator(),
                    lhs.Denominator()*rhs.Denominator()));
}

Rational operator/(const Rational&lhs, const Rational& rhs){
    if (rhs.Numerator() == 0) {
        stringstream ss;
        ss << "Division by zero";
        throw invalid_argument(ss.str());
    }
    return(Rational(lhs.Numerator()*rhs.Denominator(),
                    lhs.Denominator()*rhs.Numerator()));
}

istream& operator >>(istream& stream, Rational& rational){
    int numerator, denominator;
    char ch;
    stream >> numerator >> ch >> denominator;
    if(stream && ch == '/'){
        rational = Rational(numerator, denominator);
    }
    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs){
    if(lhs.Numerator()*rhs.Denominator() <
       rhs.Numerator()*lhs.Denominator()){
        return 1;
    }
    return 0;
}

ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() <<'/'<< rational.Denominator();
    return stream;
}

bool operator==(const Rational&lhs , const Rational& rhs){
    if(lhs.Numerator() == rhs.Numerator()
       && lhs.Denominator() == rhs.Denominator()){
        return 1;
    }
    return 0;
}

int main() {
    int nominator, denominator;
    char ch, sep;
    cin >> nominator >> sep >>denominator;
    try {
        Rational r1 = Rational(nominator, denominator);
        cin >> ch;
        cin >> nominator >> sep >> denominator;
        Rational r2 = Rational(nominator, denominator);
        if (ch == '*') {
            cout << r1 * r2;
        } else if (ch == '+') {
            cout << r1 + r2;
        } else if (ch == '-') {
            cout << r1 - r2;
        } else cout << r1 / r2;
        cout << endl;
    } catch (exception& ex){
        cout << ex.what()<<endl;
    }

    return 0;
}