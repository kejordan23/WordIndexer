// Project 1: Sentiment Analysis
// Author: Kylie Jordan
//
// DSString.h
//
// This header file declares the DSString constructor and any functions found in the DSString class

#ifndef S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_DSSTRING_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>

class DSString{
    private:
        char* str;
    public:
        //public default constructor, copy constructors, and destructor
        DSString();
        DSString(const char*);
        DSString(const DSString&);
        ~DSString();

        //overloaded operators
        DSString& operator= (const char*);
        DSString& operator= (const DSString&);
        DSString operator+ (const DSString&);
        bool operator!= (const DSString&);
        bool operator== (const char*);
        bool operator== (const DSString&);
        bool operator> (const DSString&);
        bool operator< (const DSString&) const;
        char& operator[] (const int);

        //working functions accessed by DSString objects
        int getLength();
        DSString substr(int start, int numChars);
        char* c_str();
        void removeStpWrds(std::vector<DSString>&);
        void removeBdChrs(std::vector<DSString>&);
        void removeEndPunc(DSString&);
        DSString retLower(DSString);
        friend std::ostream& operator<< (std::ostream&, const DSString&);
        friend std::istream& operator>> (std::istream&, const DSString&);
};

#endif //S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
