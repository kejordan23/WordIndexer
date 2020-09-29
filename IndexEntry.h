//
// Created by Kylie Jordan on 9/25/20.
//

#ifndef INC_20F_AUTO_IDX_INDEXENTRY_H
#define INC_20F_AUTO_IDX_INDEXENTRY_H

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "DSDLinkedList.h"

class IndexEntry{
    private:
        DSString word;
        //list of page numbers?
    public:
        IndexEntry();
        IndexEntry(DSString, DSString);
};

#endif //INC_20F_AUTO_IDX_INDEXENTRY_H
