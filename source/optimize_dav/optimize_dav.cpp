#include <iostream>

using namespace std;

class FRACTION {
    private:
        int x, y;
    public:
        FRACTION (int );
        FRACTION(FRACTION const &) = delete;
        FRACTION & operator=(FRACTION const &) = delete;
};

FRACTION::FRACTION(int a = 0) {
    x = a;
    y = 1;
}

int main() {
    FRACTION a, b;
    a = b;
}