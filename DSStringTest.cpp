// Project 1: Sentiment Analysis
// Author: Kylie Jordan
//
// test.cpp
//
// This source file uses TDD CATCH tests to evaluate the DSString class

#include "catch.hpp"
#include <cstring>
#include "DSString.h"
#include <vector>

TEST_CASE("String class", "[string]") {

    DSString s[10];
    s[0] = DSString("testString");
    s[1] = DSString("a test string");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE STRING");
    s[4] = DSString("this is an uppercase string");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testString");

    SECTION("Equality operators") {
        REQUIRE((s[0] == DSString("testString")));
        REQUIRE((s[0] == s[9]));
        REQUIRE((s[2] == ""));
        REQUIRE((s[1] == "a test string"));
        REQUIRE((!(s[3] == s[4])));
    }
    SECTION("Inequality operators") {
        REQUIRE(((s[0] != DSString("testString"))) == false);
        REQUIRE(((s[0] != s[8]) == true));
        REQUIRE(((s[2] != " ") == true));
        REQUIRE(((s[1] != "a test string") == false));
        REQUIRE(((!(s[3] != s[4])) == false));
    }

    SECTION("Assignment operators") {
        DSString str;
        str = "a test string";
        REQUIRE((str == s[1]));
        str = DSString("testString");
        REQUIRE((str == s[0]));
        str = "";
        REQUIRE((str == s[6]));
        str = DSString("\n");
        REQUIRE((str == s[5]));
    }

    SECTION("Addition operator") {
        REQUIRE((DSString("testStringtestString") == s[0] + s[9]));
        REQUIRE((s[6] + s[6] == ""));
        REQUIRE((s[5] + s[6] == DSString("\n")));
        REQUIRE(((s[0] + s[1] + s[2]) == "testStringa test string"));
    }

    SECTION("Greater than operator") {
        REQUIRE((s[0] > s[1]));
        REQUIRE((s[4] > s[3]));
        REQUIRE((s[9] > s[6]));
        REQUIRE((s[7] > s[6]));
    }
    SECTION("less than operator") {
        REQUIRE((s[1] < s[0]));
        REQUIRE((s[3] < s[4]));
        REQUIRE((s[6] < s[9]));
        REQUIRE((s[6] < s[7]));
    }

    SECTION("[] Operator") {
        REQUIRE((s[0][1] == 'e'));
        REQUIRE((s[4][4] == ' '));
        REQUIRE((s[6][0] == 0));
    }

    SECTION("getLength function") {
        REQUIRE((s[9].getLength() == 10));
        REQUIRE((s[2].getLength() == 0));
        REQUIRE((s[8].getLength() == 26));
        REQUIRE((s[3].getLength() == 27));
    }

    SECTION("Substring function") {
        REQUIRE((s[0].substr(0, 5) == "testS"));
        REQUIRE((s[4].substr(0, 4) == "this"));
        REQUIRE((s[4].substr(1, 3) == "his"));
    }

    SECTION("c_str function") {
        REQUIRE((strcmp(s[0].c_str(), "testString") == 0));
        REQUIRE((strcmp(s[9].c_str(), s[0].c_str()) == 0));
        REQUIRE((strcmp(s[2].c_str(), "") == 0));
    }
    SECTION("removeStpWrds function") {
        DSString test;
        std::vector<DSString> v1 = {"about", "Kylie", "Jamie"};
        std::vector<DSString> v2 = {"a", "about", "About"};
        std::vector<DSString> v3 = {"Byron", "Jack", "Kylie"};
        test.removeStpWrds(v1);
        REQUIRE(((v1[0] == "Kylie") && (v1[1] == "Jamie")));
        test.removeStpWrds(v2);
        REQUIRE((v2[0] == "About"));
        test.removeStpWrds(v3);
        REQUIRE(((v3[0] == "Byron") && (v3[1] == "Jack") && (v3[2] == "Kylie")));
    }
    SECTION("removeBdChrs function") {
        DSString test;
        std::vector<DSString> v1 = {"Kyli:e", "Ja_.mie"};
        std::vector<DSString> v2 = {"About"};
        std::vector<DSString> v3 = {"By--ron", " Jack", "Ky/?lie"};
        test.removeBdChrs(v1);
        REQUIRE(((v1[0] == "Kylie") && (v1[1] == "Jamie")));
        test.removeBdChrs(v2);
        REQUIRE((v2[0] == "About"));
        test.removeBdChrs(v3);
        REQUIRE(((v3[0] == "Byron") && (v3[1] == "Jack") && (v3[2] == "Kylie")));
    }
    SECTION("removeEndPunc()"){
        DSString d1 = "Hello+_)(*";
        DSString d2 = "Data Structures!@#$%";
        DSString d3 = "binary tree";
        d1.removeEndPunc(d1);
        d2.removeEndPunc(d2);
        d3.removeEndPunc(d3);
        REQUIRE((d1 == "Hello"));
        REQUIRE((d2 == "Data Structures"));
        REQUIRE((d3 == "binary tree"));
    }
    SECTION("retLower()"){
        DSString d1 = "HELLO";
        DSString d2 = "DATA STRUCTURES";
        DSString d3 = "binary TREE";
        DSString d4 = d1.retLower(d1);
        DSString d5 = d2.retLower(d2);
        DSString d6 = d3.retLower(d3);
        REQUIRE((d4 == "hello"));
        REQUIRE((d5 == "data structures"));
        REQUIRE((d6 == "binary tree"));
    }
}

