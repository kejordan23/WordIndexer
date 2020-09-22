
#define CATCH_CONFIG_RUNNER
#include <fstream>
#include <iostream>
#include "catch.hpp"
#include "DSVector.h"
#include "DSDLinkedList.h"
#include "DSString.h"

using namespace std;

int main(int argc, char* argv[]) {
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

        output<<"Hello World"<<endl;

        /*
        DSString a1[] = {"Kylie", "John", "Byron", "Amy"};
        DSVector<DSString> vec = DSVector<DSString>();
        for (int i=0; i<sizeof(a1); i++)
            vec.push_back(a1[i]);
        vec.print();


        output.close();
        inputFile.close();*/
        //DSDLinkedList<int> list = DSDLinkedList<int>();
        /*for(int i=1; i<=5; i++){
            list.insertAtEnd(i);
        }*/
        //list.print();

    }
    return 0;
}
