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
        DSDLinkedList<int> pages = DSDLinkedList<int>();
    public:
        IndexEntry(){word = "";};
        IndexEntry(DSString wrd, DSString pg){
            word = wrd;
            DSString temp = pg.substr(1, pg.getLength()-2);
            int page = atoi(temp.c_str());
            pages.insertAtFront(page);
        };
        DSString& getWord(){return word;};
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
        void print(){
            std::cout<<"word: "<<word<<std::endl;
            pages.print();
        };
};

#endif //INC_20F_AUTO_IDX_INDEXENTRY_H
