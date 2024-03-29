// Project 2: Auto Indexer
// Author: Kylie Jordan
//
// MyIndex.cpp
//
// This source file defines all the constructors and functions for the MyIndex class

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
    //sort();
    /*for(int i = 0; i <entries.getSize(); i++)
        addAlpha(entries[i]);
    for(int i=0; i<final.getSize(); i++)
        final.getElement(i).print();*/
    print(output);
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
            if(temp2 == '[')
                i++;
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
void MyIndex::sort(){
    if(entries.empty())
        return;
    quickSort(0, entries.getSize()-1);
}
void MyIndex::quickSort(int first, int second){
    int i = first;
    int j = second;
    //DSString temp = entries[first + (second-first)/2].getWord();
    DSString pivot = entries[first + (second-first)/2].getWord();
    DSString lowI;
    DSString lowJ;
    while(i<=j){
        //lowI = lowI.retLower(entries[i].getWord());
        //lowJ = lowJ.retLower(entries[j].getWord());
        while(entries[i].getWord() < pivot)
            i++;
        while(entries[j].getWord() > pivot)
            j--;
        if(i<=j){
            swapEntry(i, j);
            i++;
            j--;
        }
    }
    if(first<j)
        quickSort(first, j);
    if(i<second)
        quickSort(i, second);
}
void MyIndex::swapEntry(int i, int j){
    IndexEntry temp = entries[i];
    entries[i] = entries[j];
    entries[j] = temp;
}
void MyIndex::addAlpha(IndexEntry& i){
    DSString word = i.getWord();
    if(final.getSize() == 0)
        final.insertAtFront(i);
    if(final.getSize() == 1 && final.getElement(0).getWord()<word)
        final.insertAtEnd(i);
    else if(final.getSize() == 1 && final.getElement(0).getWord()>word)
        final.insertAtFront(i);
    else{
        int loc = 0;
        while(word>final.getElement(loc).getWord())
            loc++;
        if(word != final.getElement(loc).getWord())
            final.insertAt(loc, i);
    }
}
void MyIndex::print(ofstream& out){
    DSString lowSub;
    DSString lowCurr;
    for (int i=0; i<entries.getSize(); i++){
        if(entries[i].isParent()){
            entries[i].print(out);
            for (int j=0; j<entries[i].subSize(); j++){
                lowSub = lowSub.retLower(entries[i].getSubEntry(j));
                for(int k = 0; k<entries.getSize(); k++){
                    lowCurr = lowCurr.retLower(entries[k].getWord());
                    if(lowSub == lowCurr) {
                        out << "    ";
                        entries[k].print(out);
                    }
                }
            }
        }
        else
            entries[i].print(out);
    }
}