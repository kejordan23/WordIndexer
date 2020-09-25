//
// Created by Kylie Jordan on 9/25/20.
//

#ifndef INC_20F_AUTO_IDX_MYINDEX_H
#define INC_20F_AUTO_IDX_MYINDEX_H

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "DSDLinkedList.h"

class MyIndex{
    private:
        char line[80];
        //vector to store IndexEntry objects?
    public:
        MyIndex(istream&, ofstream&);
        void processWrds(DSString, DSString);
};

#endif //INC_20F_AUTO_IDX_MYINDEX_H
