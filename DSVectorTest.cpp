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
    for (int i=2; i<=20; i+2)
        vec2.push_back(i);
    for (int i=1; i<=20; i+2)
        vec3.push_back(i);
    SECTION("Equality operator"){
        DSVector<int> vec4 = DSVector<int>();
        vec4 = vec;
        REQUIRE((vec4[0] != NULL));
        REQUIRE((vec4[0] == vec[0]));
        REQUIRE((vec4[1] == vec[1]));
        REQUIRE((vec4[2] == vec[2]));
        REQUIRE((vec4[3] == vec[3]));
        REQUIRE((vec4[4] == vec[4]));
    }
    SECTION("Subscript"){

    }
    SECTION("getCapacity()"){

    }
    SECTION("getSize()"){

    }
    SECTION("getElement()"){

    }
    SECTION("insert()"){

    }
    SECTION("push_back()"){

    }
    SECTION("remove()"){

    }
}

TEST_CASE("DSVector class", "[DSString]"){

}