// Project 2: Auto Indexer
// Author: Kylie Jordan
// Class: CS 2341 section 801
// Lab section: N14
//
// This program takes a list of keywords and their corresponding page numbers from an input file and inserts them
// into a formatted index. Normal words are surrounded by empty space, phrases are enclosed in square brackets,
// and any word or phrase that has a parent category is succeeded by the parent word or phrase in parentheses.
// Both parent and subordinate entries appear in the index on their own as well as indented below the parent.
// The pages in which these words appear are printed in ascending order after each word.
//
//main.cpp
//
#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "DSVector.h"
#include "DSDLinkedList.h"
#include "DSString.h"
#include "MyIndex.h"
#include "IndexEntry.h"

using namespace std;

//main() takes command line arguments argv 1: input01.txt OR input02.txt OR input03.txt and argv 2: output.txt
int main(int argc, char* argv[]) {
    //conditional to run CATCH tests if there are no command line arguments
    if (argc == 1) {
        return Catch::Session().run();
    }
    else {
        ifstream inputFile;
        ofstream output;
        //opening files with a conditional to check if they open correctly
        inputFile.open(argv[1]);
        output.open(argv[2]);
        if (!output.is_open() || !inputFile.is_open())
            cout << "unable to open file" << endl;

        //creates a MyIndex object that creates the index and outputs the results to the output file
        MyIndex i(inputFile, output);

        //closing both the input and output files
        output.close();
        inputFile.close();
    }
    return 0;
}
