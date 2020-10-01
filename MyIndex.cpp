//
// Created by Kylie Jordan on 9/25/20.
//

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "DSVector.h"
#include "DSDLinkedList.h"
#include "MyIndex.h"
#include "IndexEntry.h"

using namespace std;

MyIndex::MyIndex(istream& input, ofstream& output){
    DSString page;
    DSString words = "";
    input.getline(line, 80);
    while (strcmp(line, "<-1>") != 0){
        if(line[0] == '<')
            page = line;
        input.getline(line, 80);
        while(line[0] != '<'){
            if(words == "")
                words = line;
            else
                words = words +" " + line;
            input.getline(line, 80);
        }
        processWrds(page, words);
        words = "";
    }
    print();
}
void MyIndex::processWrds(DSString page, DSString words){
    char temp = words[0];
    char temp2 = ' ';
    DSString word;
    DSString parent = "";
    int index = 0;
    int i = 0;
    int j = 0;
    while (i<words.getLength()){
        if (temp != '[' && temp != '(') {
            temp2 = words[i+1];
            index = i;
            while (temp2 != ' ' && temp2 != '\0') {
                i++;
                temp2 = words[i];
            }
            word = words.substr(index, i - index);
            addToIndex(word, page);
            i++;
        }
        else if (temp == '[') {
            temp2 = words[i+1];
            index = i+1;
            while (temp2 != ']' && temp2 != '\0') {
                i++;
                temp2 = words[i];
            }
            word = words.substr(index, i - index);
            addToIndex(word, page);
            i+=2;
        }
        if (words[i-1] == '(') {
            temp2 = words[i];
            index = i;
            while (temp2 != ')' && temp2 != '\0') {
                i++;
                temp2 = words[i];
            }
            parent = words.substr(index, i - index);
            addToIndex(parent, page);
            addParent(word, parent);
            i+=2;
        }
        temp = words[i];
        index = 0;
    }
}
void MyIndex::addToIndex(DSString word, DSString page){
    word.removeEndPunc(word);
    DSString lowVers = word.retLower(word);
    DSString lowCurr;
    if(entries.empty()){
        IndexEntry i(word, page);
        entries.push_back(i);
    }
    else{
        int index = 0;
        for(int i = 0; i<entries.getSize(); i++){
            lowCurr = lowCurr.retLower(entries[i].getWord());
            if(lowCurr == lowVers)
                index = i;
        }
        if (index != 0){
            entries[index].addPage(page);
        }
        else{
            IndexEntry i(word, page);
            entries.push_back(i);
        }
    }
}
void MyIndex::addParent(DSString word, DSString parent){
    word.removeEndPunc(word);
    parent.removeEndPunc(parent);
    DSString lowVersWrd = word.retLower(word);
    DSString lowVersPar = parent.retLower(parent);
    DSString lowCurr;
    int index = 0;
    for (int i = 0; i<entries.getSize(); i++){
        lowCurr = lowCurr.retLower(entries[i].getWord());
        if(lowCurr == lowVersPar)
            index = i;
    }
    if(entries[index].subSize() == 0)
        entries[index].addSubEntry(word);
    bool dup = false;
    for(int j = 0; j<entries[index].subSize(); j++){
        lowCurr = lowCurr.retLower(entries[index].getSubEntry(j));
        if(lowCurr == lowVersWrd)
            dup = true;
    }
    if (!dup)
        entries[index].addSubEntry(word);
}
void MyIndex::print(){
    DSString lowSub;
    DSString lowCurr;
    for (int i=0; i<entries.getSize(); i++){
        if(entries[i].isParent()){
            entries[i].print();
            for (int j=0; j<entries[i].subSize(); j++){
                lowSub = lowSub.retLower(entries[i].getSubEntry(j));
                for(int k = 0; k<entries.getSize(); k++){
                    lowCurr = lowCurr.retLower(entries[k].getWord());
                    if(lowSub == lowCurr) {
                        cout << "    ";
                        entries[k].print();
                    }
                }
            }
        }
        else
            entries[i].print();
    }
}