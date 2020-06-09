#include "Stack.h"
#include <bits/stdc++.h>
using namespace std;
#define infile1 "data.txt"
#define infile2 "dataReverse.txt"

class UnitTest {
private:
    ifstream data;
    ifstream dataReverse;
public:
    UnitTest() {
        data.open(infile1);
        dataReverse.open(infile2);
        if (data && dataReverse) {}
        else {
            throw exception();
        }
    }

    void testAll() {
        testStackEmptyFunc();
        testStackPopFunc();
        testStackPushFunc();
        testStackSizeFunc();
    }

    void testStackEmptyFunc() {
        Stack<string> myStack;
        assert(myStack.empty());
    }

    void testStackSizeFunc() {
        Stack<string> myStack;
        string s;
        int cnt = 0;
        while (getline(data, s)) {
            myStack.push(s);
            ++cnt;
            assert(cnt == myStack.size());
        }
    }

    void testStackPushFunc() {
        Stack<string> myStack;
        string s;
        while (getline(data, s)) {
            myStack.push(s);
            string tmp = myStack.top();
            assert(tmp == s);
        }
    }

    void testStackPopFunc() {
        Stack<string> myStack;
        string s;
        while (getline(data, s)) {
            myStack.push(s);
        }
        while (getline(dataReverse, s)) {
            string tmp = myStack.top();
            myStack.pop();
            assert(tmp == s);
        }
    }
};

