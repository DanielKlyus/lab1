#include <iostream>
#include "header.h"

int main()
{
    TritSet set{Trit::True, Trit::False, Trit::Unknown, Trit::True};
    cout << set << endl;
    testes();
    return 0;
}
