#include <iostream>
#include <fstream>
#include <map>

using std::map;
using std::string;
using std::ofstream;
using std::cout;
using std::cin;

class Rus_Eng_dictionary {
    private:
    map<string, string> Rus_Eng;
    public:
    Rus_Eng_dictionary() {}
    string GetWord(string RusWord) {
        string EngWord = Rus_Eng[RusWord];
        return EngWord;
    }
    void AddWord(string RusWord, string EngWord) {
        bool IsCorrect = true;
        for(auto Itter = Rus_Eng.begin(); Itter != Rus_Eng.end(); Itter++) {
            if(Itter->first == RusWord) {
                cout << "This key is alredy exist.\n";
                IsCorrect = false;
            }
        }
        if(IsCorrect) {
            Rus_Eng[RusWord] = EngWord;
        }
    }
    void TransformToFile(string FileName) {
        string RusWord, EngWord;
        ofstream File(FileName);
        for(auto Itter = Rus_Eng.begin(); Itter != Rus_Eng.end(); Itter++) {
            RusWord = Itter->first;
            EngWord = Itter->second;
            File << RusWord << " : " << EngWord << "\n";
        }
        File.close();
    }
};

int main() {
    Rus_Eng_dictionary RE;
    RE.AddWord("стол", "table");
    RE.AddWord("стол", "table");
    return 0;
}
