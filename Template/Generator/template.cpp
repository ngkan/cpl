#include <bits/stdc++.h>
using namespace std;

const string NAME = "name";     // problem name
const string TestType = "CMS";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

int Rand(int lo,int hi){
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    input << 1 << endl;
}

int main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();
    rd.seed(randomSeed);
    for(int _ = 0; _ < NTEST; _++){
        string id;          // id of current test
        stringstream ss;
        ss << _;
        ss >> id;

        cout << "Making test: " << id << endl;

        string input, output, program = NAME;

        if (TestType == "CMS")
            input  = NAME + id + ".in",
            output = NAME + id + ".out";
        else
            system(("MKDIR Test" + id).c_str()),
            input  = "Test" + id + '\\' + NAME + ".INP",
            output = "Test" + id + '\\' + NAME + ".OUT";

        ofstream inputFile(input.c_str());

        // create input
        makeTest(inputFile, _);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}
