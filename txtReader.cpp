#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> extract_sentences(const string& file_path) {
    ifstream file(file_path);
    string text;
    string line;
    vector<string> sentences;

    while (getline(file, line)) {
        text += line + " ";
    }

    istringstream iss(text);
    string sentence;
    while (getline(iss, sentence, '.')) {
        sentence.pop_back(); // remove the delimiter
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }
    }

    return sentences;
}

int main() {
    string file_path = "path_to_your_file.txt";  // replace with your file path
    vector<string> sentences = extract_sentences(file_path);

    for (const auto& sentence : sentences) {
        cout << sentence << endl;
    }

    return 0;
}