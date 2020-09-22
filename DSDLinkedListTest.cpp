//
// Created by Kylie Jordan on 9/21/20.
//

#include "catch.hpp"
#include "DSDLinkedList.h"
#include "DSString.h"

TEST_CASE ("DSDLinkedList class", "[int]"){
    DSDLinkedList<int> list = DSDLinkedList<int>();
    for(int i=1; i<=5; i++){
        list.insertAtEnd(i);
    }
    SECTION("Equality operators"){

    }
    SECTION("empty()"){

    }
    SECTION("getElement()"){

    }
    SECTION("getSize()"){

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

    }
}
