#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
#include <array>
using namespace std;

namespace ariel {
    string snowman(int a) {
        const int min = 0;
        const int problematic_num = 2;
        const int num_string = 4;
        const int left_hand = 4;
        const int right_hand = 5;
        const int stomach = 6;
        const int max_num_of_string = 7;
        const int bottom = 7;
        const int max_snowman = 8;
        const int mod = 10;
        const int max = 44444444;
        
        if (a < min) {
            throw invalid_argument("Invalid number - Negative number");
        }

        if (a > max) {
            throw out_of_range("invalid input");
        }
           
        array<string, num_string> hat { "_===_", " ___\n .....", "  _\n  /_\\", " ___\n (_*_)" }; // 0
        array<string, num_string> nose { ",", ".", "_", " " }; // 1 - 1
        array<string, num_string> left_eye { "(.", "(o", "(O", "(-" }; // 2 - 1
        array<string, num_string> right_eye { ".)", "o)", "O)", "-)" }; // 3 - 1
        array<string, num_string> left_arm { "<", "\\", "/", " " }; // 4 - 1 or 2
        array<string, num_string> right_arm { ">", "/", "\\", " " }; // 5 - 1 or 2
        array<string, num_string> torso { "( : )", "(] [)", "(> <)", "(   )" }; // 6 - 3
        array<string, num_string> base { " ( : )", " (\" \")", " (___)", " (   )" }; // 7 - 4

        
        int tmp = a;
        int count = 0;
        array<int, max_snowman> index {};
        while (tmp != 0) {
            int digit = tmp % mod;
            if (digit < 1 || digit > num_string) {
                throw invalid_argument("Invalid digits - should be digits between 1 to 4");
            }
            index.at(max_num_of_string-count) = digit;
            tmp = tmp / mod;
            count++;
        }
        if (count != max_snowman) {
            throw invalid_argument("Wrong number of digits");
        }
        
        string snowman = " ";

        snowman.append(hat.at(index.at(0)-1) + "\n");

        if (index.at(left_hand) == problematic_num) {
            snowman.append(left_arm.at(index.at(left_hand)-1));
        } else {
            snowman.append(" ");
        }

        snowman.append(left_eye.at(index.at(2)-1) + nose.at(index.at(1)-1) + right_eye.at(index.at(3)-1));

        if (index.at(right_hand) == problematic_num) {
            snowman.append(right_arm.at(index.at(right_hand)-1) + "\n");
        } else {
            snowman.append("\n");
        }
        
        if (index.at(left_hand) != problematic_num) {
            snowman.append(left_arm.at(index.at(left_hand)-1));
        } else {
            snowman.append(" ");
        }

        snowman.append(torso.at(index.at(stomach)-1));

        if (index.at(right_hand) != problematic_num) {
            snowman.append(right_arm.at(index.at(right_hand)-1) + "\n");
        } else {
            snowman.append("\n");
        }

        snowman.append(base.at(index.at(bottom)-1));
        

        cout << "________________________" << endl;
        cout << snowman << endl;
        return snowman;
    }
}