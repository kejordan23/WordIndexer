//
// Created by Kylie Jordan on 9/21/20.
//

#include "catch.hpp"
#include "DSDLinkedList.h"
#include "DSString.h"

TEST_CASE ("DSDLinkedList class", "[int]"){
    DSDLinkedList<int> list = DSDLinkedList<int>();
    DSDLinkedList<int> list2 = DSDLinkedList<int>();
    DSDLinkedList<int> list3 = DSDLinkedList<int>();
    for(int i=1; i<=5; i++){
        list.insertAtEnd(i);
    }
    for(int i=2; i<=20; i+=2){
        list2.insertAtEnd(i);
    }
    for(int i=1; i<=20; i+=2){
        list3.insertAtEnd(i);
    }
    SECTION("Equality operators"){
        DSDLinkedList<int> list4 = DSDLinkedList<int>();
        list4 = list;
        REQUIRE((list4.getElement(0) == list.getElement(0)));
        REQUIRE((list4.getElement(1) == list.getElement(1)));
        REQUIRE((list4.getElement(2) == list.getElement(2)));
        REQUIRE((list4.getElement(3) == list.getElement(3)));
        REQUIRE((list4.getElement(4) == list.getElement(4)));
    }
    SECTION("empty()"){
        DSDLinkedList<int> list5 = DSDLinkedList<int>();
        REQUIRE((list.empty() == false));
        REQUIRE((list2.empty() == false));
        REQUIRE((list5.empty() == true));
    }
    SECTION("getElement()"){
        REQUIRE((list2.getElement(0) == 2));
        REQUIRE((list2.getElement(1) == 4));
        REQUIRE((list2.getElement(2) == 6));
        REQUIRE((list2.getElement(3) == 8));
        REQUIRE((list2.getElement(4) == 10));
        REQUIRE((list2.getElement(9) != 8));
    }
    SECTION("getSize()"){
        REQUIRE((list.getSize() == 5));
        REQUIRE((list2.getSize() == 10));
        REQUIRE((list3.getSize() == 10));
    }
    SECTION("insertAtFront()"){

    }
    SECTION("insertAtEnd()"){

    }
    SECTION("insertAt()"){

    }
    SECTION("remove()"){

    }
    SECTION("clear()"){
        list.clear();
        list2.clear();
        list3.clear();
        REQUIRE((list.getSize() == 0));
        REQUIRE((list2.getSize() == 0));
        REQUIRE((list3.getSize() == 0));
    }
}
