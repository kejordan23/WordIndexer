//
// Created by Kylie Jordan on 9/17/20.
//

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"

TEST_CASE("DSVector class", "[int]"){
    DSVector<int> vec = DSVector<int>();
    DSVector<int> vec2 = DSVector<int>();
    DSVector<int> vec3 = DSVector<int>();
    for (int i=1; i<=5; i++)
        vec.push_back(i);
    for (int i=2; i<=20; i+=2)
        vec2.push_back(i);
    for (int i=1; i<=20; i+=2)
        vec3.push_back(i);
    SECTION("Equality operator"){
        DSVector<int> vec4 = DSVector<int>();
        vec4 = vec;
        REQUIRE((vec4[0] == vec[0]));
        REQUIRE((vec4[1] == vec[1]));
        REQUIRE((vec4[2] == vec[2]));
        REQUIRE((vec4[3] == vec[3]));
        REQUIRE((vec4[4] == vec[4]));
    }
    SECTION("Subscript"){
        REQUIRE((vec2[0] == 2));
        REQUIRE((vec[1] == 2));
        REQUIRE((vec3[2] == 5));
        REQUIRE((vec[3] == 4));
        REQUIRE((vec3[4] != vec[4]));
    }
    SECTION("getCapacity()"){
        DSVector<int> vec4 = DSVector<int>(10);
        DSVector<int> vec5 = DSVector<int>(20);
        DSVector<int> vec6 = DSVector<int>(13);
        REQUIRE((vec4.getCapacity() == 10));
        REQUIRE((vec5.getCapacity() == 20));
        REQUIRE((vec6.getCapacity() == 13));
    }
    SECTION("getSize()"){
        REQUIRE((vec.getSize() == 5));
        REQUIRE((vec2.getSize() == 10));
        REQUIRE((vec3.getSize() == 10));
    }
    SECTION("getElement()"){
        REQUIRE((vec2.getElement(0) == 2));
        REQUIRE((vec.getElement(1) == 2));
        REQUIRE((vec3.getElement(2) == 5));
        REQUIRE((vec.getElement(3) == 4));
        REQUIRE((vec3.getElement(4) != vec[4]));
    }
    SECTION("insert()"){
        vec.insert(2, 6);
        REQUIRE((vec[2] == 6));
        vec2.insert(3, 10);
        REQUIRE((vec2[3] == 10));
        vec3.insert(6, 1);
        REQUIRE((vec3[6] == 1));
        vec3.insert(2, 6);
        REQUIRE((vec3[2] == 6));
        vec.insert(4, 6);
        REQUIRE((vec[4] == 6));
    }
    SECTION("push_back()"){
        DSVector<int> vec7 = DSVector<int>();
        for (int i=1; i<=5; i++)
            vec7.push_back(i);
        REQUIRE((vec7[0] == 1));
        REQUIRE((vec7[1] == 2));
        REQUIRE((vec7[2] == 3));
        REQUIRE((vec7[3] == 4));
        REQUIRE((vec7[4] == 5));
    }
    SECTION("remove()"){
        vec2.remove(1);
        REQUIRE((vec2[1] == 6));
        vec2.remove(4);
        REQUIRE((vec2[4] == 14));
        vec2.remove(4);
        REQUIRE((vec2[4] == 16));
    }
}



/*
TEST_CASE("[DSStrings}"){
    DSString a1[] = {"Kylie", "John", "Byron", "Amy"};
    DSString a2[] = {"cat", "dog", "wolf", "tiger", "possum", "marmot"};
    DSString a3[] = {"house", "car", "trailer"};
    DSVector<DSString> vec = DSVector<DSString>();
    DSVector<DSString> vec2 = DSVector<DSString>();
    DSVector<DSString> vec3 = DSVector<DSString>();
    for (int i=0; i<sizeof(a1); i++)
        vec.push_back(a1[i]);
    for (int i=0; i<sizeof(a2); i++)
        vec2.push_back(a2[i]);
    for (int i=0; i<sizeof(a3); i++)
        vec3.push_back(a3[i]);
    SECTION("Equality operator"){
        DSVector<DSString> vec4 = DSVector<DSString>();
        vec4 = vec;
        REQUIRE((vec4[0] == vec[0]));
        REQUIRE((vec4[1] == vec[1]));
        REQUIRE((vec4[2] == vec[2]));
        REQUIRE((vec4[3] == vec[3]));
        REQUIRE((vec4[4] == vec[4]));
    }
    SECTION("Subscript"){
        REQUIRE((vec2[0] == "cat"));
        REQUIRE((vec[1] == "John"));
        REQUIRE((vec3[2] == "trailer"));
        REQUIRE((vec[3] == "Amy"));
        REQUIRE((vec3[0] != vec[0]));
    }
    SECTION("getCapacity()"){
        DSVector<DSString> vec4 = DSVector<DSString>(10);
        DSVector<DSString> vec5 = DSVector<DSString>(20);
        DSVector<DSString> vec6 = DSVector<DSString>(13);
        REQUIRE((vec4.getCapacity() == 10));
        REQUIRE((vec5.getCapacity() == 20));
        REQUIRE((vec6.getCapacity() == 13));
    }
    SECTION("getSize()"){
        REQUIRE((vec.getSize() == 4));
        REQUIRE((vec2.getSize() == 6));
        REQUIRE((vec3.getSize() == 3));
    }
    SECTION("getElement()"){
        REQUIRE((vec2.getElement(0) == "cat"));
        REQUIRE((vec.getElement(1) == "John"));
        REQUIRE((vec3.getElement(2) == "trailer"));
        REQUIRE((vec.getElement(3) == "Amy"));
        REQUIRE((vec3.getElement(0) != vec[0]));
    }
    SECTION("insert()"){
        vec.insert(2, "Ben");
        REQUIRE((vec[2] == "Ben"));
        vec2.insert(3, "fisher cat");
        REQUIRE((vec2[3] == "fisher cat"));
        vec3.insert(6, "swingset");
        REQUIRE((vec3[6] == "swingset"));
        vec3.insert(2, "yard");
        REQUIRE((vec3[2] == "yard"));
        vec.insert(4, "Tim");
        REQUIRE((vec[4] == "Tim"));
    }
    SECTION("push_back()"){
        DSString a4[] = {"cool", "brb", "ttyl", "tbh", "btw"};
        DSVector<DSString> vec7 = DSVector<DSString>();
        for (int i=0; i<sizeof(a4); i++)
            vec7.push_back(a4[i]);
        REQUIRE((vec7[0] == "cool"));
        REQUIRE((vec7[1] == "brb"));
        REQUIRE((vec7[2] == "ttyl"));
        REQUIRE((vec7[3] == "tbh"));
        REQUIRE((vec7[4] == "btw"));
    }
    SECTION("remove()"){
        vec2.remove(1);
        REQUIRE((vec2[1] == "wolf"));
        vec2.remove(2);
        REQUIRE((vec2[2] == "possum"));
        vec2.remove(2);
        REQUIRE((vec2[2] == "marmot"));
    }
}*/

