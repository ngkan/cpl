#include <bits/stdc++.h>
using namespace std;

#define WINDOWS 0
#define LINUX 1

#define THEMIS 0
#define CMS 1

// Change here
#define OS WINDOWS				
#define STYLE CMS					

const string NAME = "name";
const int NTEST = 20;           
const string dir = "Test";

#if OS == WINDOWS
	const string slash = "\\"; 
	const string solution = NAME + ".exe";
#else
	const string slash = "/"; 
	const string solution = "./" + NAME;
#endif

mt19937_64 rd(chrono::system_clock::now().time_since_epoch().count());

int Rand(int lo,int hi){
    return rd() % (hi - lo + 1) + lo;
}

// Change here
void createTest(ofstream &input, int testId){
    input << 1 << endl;
}

int main(){
	system(("mkdir " + dir).c_str());
	
    for(int id = 0; id < NTEST; id ++){
        string _; stringstream ss; ss << id; ss >> _;

        cout << "Creating test: " << _ << endl;

		#if STYLE == THEMIS
			string folder = dir + slash + _,
				   input = folder + slash + NAME + ".inp", 
				   output = folder + slash + NAME + ".out";
			system(("mkdir " + folder).c_str());
		#else
			string input = dir + slash + _ + ".in", 
				   output = dir + slash + _ + ".out";
		#endif
	
        ofstream inputFile(input.c_str());
        createTest(inputFile, id);
        inputFile.close();
        system((solution + " < " + input + " > " + output).c_str());
    }
}
