//
// Created by Kylie Jordan on 9/25/20.
//

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "DSDLinkedList.h"
#include "MyIndex.h"

using namespace std;

MyIndex::MyIndex(istream& input, ofstream& output){
    DSString page;
    DSString words;
    input.getline(line, 80);
    while (strcmp(line, "<-1>") != 0){
        if(line[0] == '<')
            page = line;
        input.getline(line, 80);
        while(line[0] != '<'){
            words = words + " " + line;
            input.getline(line, 80);
        }
        processWrds(page, words);
        words = "";
    }
}
void MyIndex::processWrds(DSString page, DSString words){
    cout<<page<<endl;
    cout<<words<<endl;
}