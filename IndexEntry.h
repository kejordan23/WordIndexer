// Project 2: Auto Indexer
// Author: Kylie Jordan
//
// IndexEntry.h
//
// This header file declares and defines the IndexEntry class constructors and functions.

#ifndef INC_20F_AUTO_IDX_INDEXENTRY_H
#define INC_20F_AUTO_IDX_INDEXENTRY_H

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "DSDLinkedList.h"

//each IndexEntry has a words and a list of pages. Some IndexEntries have a vector of subEntries if it is a parent word
class IndexEntry{
    private:
        DSString word;
        DSDLinkedList<int> pages = DSDLinkedList<int>();
        DSVector<DSString> subEntries = DSVector<DSString>();
    public:
        IndexEntry(){word = "";};
        IndexEntry(DSString wrd, DSString pg){
            word = wrd;
            DSString temp = pg.substr(1, pg.getLength()-2); //converts page number to an int
            int page = atoi(temp.c_str());
            pages.insertAtFront(page);
        };
        //overloaded assignment operator
        IndexEntry& operator=(IndexEntry& i){
            if(word == i.word)
                return *this;
            else{
                word = i.word;
                pages = i.pages;
                if(i.subEntries.getSize() != 0)
                    subEntries = i.subEntries;
                return *this;
            }
        };
        //returns a value specifying whether the entry is a parent
        bool isParent(){
            if(subEntries.empty())
                return false;
            else
                return true;
        };
        DSString& getWord(){return word;};
        DSString& getSubEntry(int loc){
            return subEntries[loc];
        };
        void addSubEntry(DSString& word){
            subEntries.push_back(word);
        };
        int subSize(){
            return subEntries.getSize();
        };
        //adds pages to the entries list in ascending order
        void addPage(DSString pg){
            DSString temp = pg.substr(1, pg.getLength()-2);
            int page = atoi(temp.c_str());
            if(pages.getSize()==1 && pages.getElement(0)>page)
                pages.insertAtFront(page);
            else if(pages.getElement(pages.getSize()-1)<page)
                pages.insertAtEnd(page);
            else{
                int loc = 0;
                while(page>pages.getElement(loc))
                    loc++;
                if(page != pages.getElement(loc))
                    pages.insertAt(loc, page);
            }
        };
        void print(ofstream& out){
            out<<word<<": ";
            pages.print(out);
            out<<endl;
        };
};

#endif //INC_20F_AUTO_IDX_INDEXENTRY_H
