#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	input.erase(remove(input.begin(), input.end(), '\t'), input.end());
	input.erase(remove(input.begin(), input.end(), '\n'), input.end());
	input.erase(remove(input.begin(), input.end(), '\r'), input.end());
	return input;
}

TEST_CASE("Good snowman code") {
    CHECK(snowman(11111111) == string(" _===_\n (.,.)\n<( : )>\n ( : )"));
    CHECK(snowman(22222222) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(snowman(33333333) == string("   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)"));
    CHECK(snowman(44444444) == string("  ___\n (_*_)\n (- -)\n (   ) \n (   )"));
    CHECK(snowman(11114411) == string(" _===_\n (.,.)\n ( : ) \n ( : )"));
    CHECK(snowman(12222212) == string(" _===_\n\\(o.o)/\n ( : )\n (\" \")"));
    CHECK(snowman(33232124) == string("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
    CHECK(nospaces(snowman(12121212)) == nospaces("_===_\n(..o)/\n<( : )\n(\" \")"));
    CHECK(nospaces(snowman(23232323)) == nospaces(" ___\n.....\n\\(o_O)\n (] [)\\\n (___)"));
    CHECK(nospaces(snowman(34214223)) == nospaces("  _\n  /_\\\n (o .)/\n (] [)\n (___)"));
    CHECK(nospaces(snowman(41232142)) == nospaces("  ___\n (_*_)\n\\(o,O)\n (   )>\n (\" \")"));
    CHECK(nospaces(snowman(12341234)) == nospaces(" _===_\n (O.-)/\n<(> <)\n (   )"));
    CHECK(nospaces(snowman(43214321)) == nospaces("  ___\n (_*_)\n (o_.)\n (] [)\\\n ( : )"));
    CHECK(nospaces(snowman(24314213)) == nospaces("  ___\n .....\n (O .)/\n ( : )\n (___)"));
    CHECK(nospaces(snowman(31122412)) == nospaces("   _\n  /_\\\n\\(.,o)\n ( : )\n (\" \")"));
    CHECK(nospaces(snowman(11223344)) == nospaces(" _===_\n (o,o)\n/(   )\\\n (   )"));
    CHECK(nospaces(snowman(22334411)) == nospaces("  ___\n .....\n (O.O)\n ( : )\n ( : )"));
    CHECK(nospaces(snowman(33441122)) == nospaces("   _\n  /_\\\n (-_-)\n<(] [)>\n (\" \")"));
    CHECK(nospaces(snowman(44112233)) == nospaces("  ___\n (_*_)\n\\(. .)/\n (> <)\n (___)"));
    CHECK(nospaces(snowman(13421423)) == nospaces(" _===_\n (-_o)\n<(] [)\n (___)"));
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(11114416));
    CHECK_THROWS(snowman(12345678));
    CHECK_THROWS(snowman(11161215));
    CHECK_THROWS(snowman(11511213));
    CHECK_THROWS(snowman(17111212));
    CHECK_THROWS(snowman(11611214));
    CHECK_THROWS(snowman(11111218));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(11111811));
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(55555555));
    CHECK_THROWS(snowman(66666666));
    CHECK_THROWS(snowman(77777777));
    CHECK_THROWS(snowman(88888888));
    CHECK_THROWS(snowman(99999999));
}

TEST_CASE("Less than 8 digits") {
    CHECK_THROWS(snowman(1111111));
    CHECK_THROWS(snowman(5));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11));

    for (int i = 0; i < 100000; i++) {
        CHECK_THROWS(snowman(i));
    }
}

TEST_CASE("More than 8 digits") {
    CHECK_THROWS(snowman(222222222));
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(333333333));
    CHECK_THROWS(snowman(444444444));
}

TEST_CASE("Negative number") {
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(-11));
    CHECK_THROWS(snowman(-555));
    CHECK_THROWS(snowman(-1111));
    CHECK_THROWS(snowman(-11111));
    CHECK_THROWS(snowman(-111111));
    CHECK_THROWS(snowman(-11111111));
}
