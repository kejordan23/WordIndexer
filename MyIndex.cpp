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
    for(int i = 0; i<entries.getSize(); i++)
        entries[i].print();
}
void MyIndex::processWrds(DSString page, DSString words){
    char temp = words[0];
    char temp2 = ' ';
    DSString word;
    DSString phrase;
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
        if (temp == '[') {
            temp2 = words[i+1];
            index = i+1;
            while (temp2 != ']' && temp2 != '\0') {
                i++;
                temp2 = words[i];
            }
            phrase = words.substr(index, i - index);
            addToIndex(phrase, page);
            i+=2;
        }
        if (temp == '(') {
            temp2 = words[i+1];
            index = i;
            while (temp2 != ')' && temp2 != '\0') {
                i++;
                temp2 = words[i];
            }
            parent = words.substr(index, i - index-1);
            i++;
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