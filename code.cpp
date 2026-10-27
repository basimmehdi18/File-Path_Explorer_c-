#include <iostream>
#include <string>
using namespace std;

namespace pathutils {

    
    string getFilename(string path) {
        int slash = path.find_last_of("/\\");
        int dot = path.find_last_of('.');

        string filename = path.substr(slash + 1, dot - slash - 1);

        return filename;
    }

    
    string getExtension(string path) {
        int dot = path.find_last_of('.');

        if (dot == -1) {
            return "";
        }

        return path.substr(dot + 1);
    }

    
    int getFilenameLength(string path) {
        return getFilename(path).length();
    }

  
    string replaceExtension(string path) {
        int dot = path.find_last_of('.');

        if (dot == -1) {
            return path + ".bak";
        }

        return path.substr(0, dot) + ".bak";
    }

}

int main() {
    string path;

    do {
        cout << "Enter a file path: ";
        getline(cin, path);

        if (path.find('/') == string::npos) {
            cout << "Invalid path! The path must contain '/'. Try again.\n";
        }

    } while (path.find('/') == string::npos);

    cout << "\nFilename: " << pathutils::getFilename(path) << endl;
    cout << "Extension: " << pathutils::getExtension(path) << endl;
    cout << "Filename length: " << pathutils::getFilenameLength(path) << endl;
    cout << "New path: " << pathutils::replaceExtension(path) << endl;

    return 0;
}

// / is an escape character in c++