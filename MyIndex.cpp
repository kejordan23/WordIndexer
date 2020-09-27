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
            i++;
        }
        if (temp == '[') {
            temp2 = words[i+1];
            index = i+1;
            while (temp2 != ']' && temp2 != '\0') {
                i++;
                temp2 = words[i];
            }
            word = words.substr(index, i - index);
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
            cout<<"--"<<parent<<endl;
            i++;
        }
        temp = words[i];
        cout<<"--"<<word<<"--"<<endl;
        //word = " ";
        index = 0;
    }
}