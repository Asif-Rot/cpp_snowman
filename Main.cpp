#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main () {
    cout << "Let's build a snowman!" << endl;
    cout << "The snowman has a hat, nose, eyes, arms, torso and base" << endl;
    cout << "Every part has 4 options in the order below" << endl;
    cout << "Here are the options:" << endl;
    cout << "\nhat:\n1) _===_ ,2) ___ ,3) _ ,4) ___" << endl;
    cout << "            .....   /_\\   (_*_)" << endl;
    cout << "\nnose:\n1) ',' ,2) '.' ,3) '_' ,4) ' '" << endl;
    cout << "\nleft_eye:\n1) '.' ,2) 'o' ,3) 'O' ,4) '-'" << endl;
    cout << "\nright_eye:\n1) '.' ,2) 'o' ,3) 'O' ,4) '-'" << endl;
    cout << "\nleft_arm:\n1) '<' ,2) '\\' ,3) '/' ,4) ' '" << endl;
    cout << "\nright_arm:\n1) '>' ,2) '/' ,3) '\\' ,4) ' '" << endl;
    cout << "\ntorso:\n1)'( : )' ,2) '(] [)' ,3) '(> <)' ,4) '(   )'" << endl;
    cout << "\nbase:\n1) '( : )' ,2) '(\" \")' ,3) '(___)' ,4) '(   )'" << endl;
    cout << "\nexmaples -\nif you choose - 11111111, you will get: \n" << ariel::snowman(11111111) << endl;
    cout << "\nEach digit represents a part in the order shown above, more examples for demosnatration:" << endl;
    cout << "if you choose - 22222222, you will get: \n" << ariel::snowman(22222222) << endl;
    cout << "if you choose - 33333333, you will get: \n" << ariel::snowman(33333333) << endl;
    cout << "if you choose - 44444444, you will get: \n" << ariel::snowman(44444444) << endl;
    cout << "\nLet's begin!" << endl;
    cout << "If you choose any digit that is not in range of 1 to 4,\nthere will be no snowman for you!" << endl;
    
    while (true) {
        try {
            cout << "\nPlease type a number with 8 digits long that contains only numbers from 1 to 4" << endl;
            int count = 0;
            int x;
            cin >> x;
            int tmp = x;
            while (tmp != 0) {
            tmp = tmp / 10;
            count++;
        }
            if (count != 8) {
                throw out_of_range("not in range");
            }
            cout << "Your snowman:\n" << ariel::snowman(x) << endl;
        } catch (exception &e) {
            cout << "\nPlease try again with 8 digits in range of 1 to 4" << endl;
        }
    }
    return 0;
}
    