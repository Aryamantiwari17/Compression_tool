#include <bits/stdc++.h>
using namespace std;
const string ERROR_CODES_FILE = "errorCodes.txt";  //Including the errorCodes text file

unordered_map<int, string> load_error_codes() {   //Defining a function for reading the file
    unordered_map<int, string> error_codes;
    ifstream file(ERROR_CODES_FILE);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open error codes file: " << ERROR_CODES_FILE << endl;
        return error_codes;
    }
    string line;
    while (getline(file, line)) {
        if (line[0] == '#' || line.empty()) {  //skipping the lines with #
            continue;
        }

        size_t colon_pos = line.find(": ");  //where the number matches search for colon and return the description
        if (colon_pos == string::npos) {
            continue;
        }

        int code = stoi(line.substr(0, colon_pos));
        string description = line.substr(colon_pos + 2);
        error_codes[code] = description;
    }
    file.close();
    return error_codes; //returns the error code description
}
const unordered_map<int, string> ERROR_CODES = load_error_codes(); //calling of the function when error found
//sample program for error codes
int main()
{
    int n;
    cin>>n;
    if(n>2){
        cout<<"Error("<<ERROR_CODES.at(102)<<")"<<endl;
        exit(1);
    }
    return 0;
}