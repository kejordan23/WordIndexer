// Project 2: Auto Indexer
// Author: Kylie Jordan
//
// MyIndex.h
//
// This header file declares and defines the MyIndex class constructors and functions.

#ifndef INC_20F_AUTO_IDX_MYINDEX_H
#define INC_20F_AUTO_IDX_MYINDEX_H

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "DSDLinkedList.h"
#include "IndexEntry.h"

class MyIndex{
    private:
        char line[80];
        DSVector<IndexEntry> entries = DSVector<IndexEntry>();
        DSDLinkedList<IndexEntry> final = DSDLinkedList<IndexEntry>();
    public:
        MyIndex(istream&, ofstream&);
        void processWrds(DSString, DSString);
        void addToIndex(DSString, DSString);
        void addParent(DSString, DSString);
        void sort();
        void quickSort(int, int);
        void swapEntry(int, int);
        void addAlpha(IndexEntry&);
        void print(ofstream&);
};

#endif //INC_20F_AUTO_IDX_MYINDEX_H
