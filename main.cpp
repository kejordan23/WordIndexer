
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

        MyIndex i(inputFile, output);

        /*
        DSString a1 = "Kylie";
        DSString a2 = "John";
        DSString a3 = "Byron";
        DSVector<DSString> vec = DSVector<DSString>();
        vec.push_back(a1);
        vec.push_back(a2);
        vec.push_back(a3);
        vec.print();*/

        /*DSDLinkedList<int> list = DSDLinkedList<int>();
        for(int i=1; i<=5; i++){
            list.insertAtEnd(i);
        }
        DSDLinkedList<int> list4 = DSDLinkedList<int>();
        list4 = list;
        list4.print();*/

        /*DSString test = "HELLO WORLD";
        DSString test2 = test.retLower(test);
        cout<<test2<<"---"<<endl;
        cout<<test<<"---"<<endl;*/


        output.close();
        inputFile.close();
    }
    return 0;
}
