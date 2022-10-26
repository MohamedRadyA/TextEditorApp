// Program Name: TextEditorFuncs.cpp
// Last Modification Date: 16/05/2022
// Purpose: Text Editor functions library

#include "TextEditorFuncs.h"

void add_content() {
    string tmp;
    char c;
    while (true) {
        c = getch();
        if (c == 13) {
            // if the user press enter
            tmp.push_back('\n');
            cout << '\n';
        } else if (c == 8) {
            // if user press backspace
            if (tmp.size() && tmp.back() != '\n') {
                tmp.pop_back();
                wcout << '\b' << ' ' << '\b';
            }
        } else if (c == 26) {
            break;
        } else {
            cout << c;
            tmp.push_back(c);
        }
    }
    cout << '\n';

    file.open(file_name, ios::app);
    file << '\n' << tmp;
    file.close();
}

void display_content() {
    file.open(file_name, ios::in);
    ostringstream file_content;
    file_content << file.rdbuf();
    cout << file_content.str() << '\n';
    file.close();
}

void empty_content() {
    file.open(file_name, ios::out);
    file.close();
}

void encrypt_content() {
    file.open(file_name, ios::in);
    ostringstream file_content;
    file_content << file.rdbuf();
    string tmp = file_content.str();
    for (auto &val: tmp) {
        if (val == '\n') continue;
        val += 1;
    }
    file.close();
    file.open(file_name, ios::out);
    file << tmp;
    file.close();
}

void decrypt_content() {
    file.open(file_name, ios::in);
    ostringstream file_content;
    file_content << file.rdbuf();
    string tmp = file_content.str();
    for (auto &val: tmp) {
        if (val == '\n') continue;
        val -= 1;
    }
    file.close();
    file.open(file_name, ios::out);
    file << tmp;
    file.close();
}

//----------------------------------------------------------------------------------

void getNumOfLines() {
    file.open(file_name, ios::in);
    string line;
    int num = 0;
    while (getline(file, line))
        num++;
    file.close();
    cout << "The number of lines is: " << num << "\n";
}

void getNumOfChars() {
    ostringstream text;
    int num = 0;
    file.open(file_name, ios::in);
    text << file.rdbuf();
    for (auto ch: text.str()) {
        if (ch != '\n')
            num++;
    }
    file.close();
    cout << "The number of characters is: " << num << "\n";
}

void getNumOfWords() {
    file.open(file_name, ios::in);
    string word;
    int num = 0;
    while (file >> word)
        num++;
    file.close();
    cout << "The number of words is: " << num << "\n";
}


void findWord() {
    file.open(file_name, ios::in);
    string word;
    cout << "Enter the word you want to find: ";
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    set<string> s;
    string z;
    while (true) {
        file >> z;
        transform(z.begin(), z.end(), z.begin(), ::tolower);
        s.emplace(z);
        if (file.eof())
            break;
    }
    if (s.count(word)) cout << "Word was found.\n";
    else cout << "Word was not found.\n";
    file.close();
}

void findWordCount() {
    string word, z;
    int count = 0;
    file.open(file_name, ios::in);
    cout << "Enter the word you want to find: ";
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (file >> z) {
        transform(z.begin(), z.end(), z.begin(), ::tolower);
        if (z == word)
            count++;
    }
    cout << "Word was found " << count << " times.\n";
    file.close();
}

void upperCaseFile() {
    file.open(file_name, ios::in);
    ostringstream file_content;
    file_content << file.rdbuf();
    string tmp = file_content.str();
    for (auto &val: tmp) {
        val = toupper(val);
    }
    file.close();
    file.open(file_name, ios::out);
    file << tmp;
    file.close();
    cout << "File has been converted to uppercase.\n";
}

void lowerCaseFile() {
    file.open(file_name, ios::in);
    ostringstream file_content;
    file_content << file.rdbuf();
    string tmp = file_content.str();
    for (auto &val: tmp) {
        val = tolower(val);
    }
    file.close();
    file.open(file_name, ios::out);
    file << tmp;
    file.close();
    cout << "File has been converted to lowercase.\n";
}

void firstCapsFile() {
    file.open(file_name, ios::in);
    ostringstream file_content;
    file_content << file.rdbuf();
    string tmp = file_content.str();
    tmp[0] = toupper(tmp[0]);
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i - 1] == ' ' || tmp[i - 1] == '\n')
            tmp[i] = toupper(tmp[i]);
        else
            tmp[i] = tolower(tmp[i]);
    }
    file.close();
    file.open(file_name, ios::out);
    file << tmp;
    file.close();
    cout << "File has been converted to first caps file.\n";
}

void save() {
    string sameFile;
    cout << "Save edits in the same file? (Y/N)";
    cin >> sameFile;

    while (sameFile.size() > 1 && tolower(sameFile[0]) != 'y' && tolower(sameFile[0]) != 'n') {
        cout << "Save edits in the same file? (Y/N)";
        cin >> sameFile;
    }

    if (tolower(sameFile[0]) == 'y')
        cout << "File " << file_name << " saved.\n\n";
    else {
        char name[100];
        cout << "Enter new file name: (without .txt)";
        cin >> name;
        strcat(name, ".txt");
        rename(file_name.c_str(), name);
        cout << "File " << name << " has been saved.\n\n";
    }
}


void mergeFiles() {
    fstream file2;
    string file_name2;
    while (true) {
        cout << "Enter the second file's name:\n";
        cin >> file_name2;
        file_name2 += ".txt";
        file2.open(file_name2, ios::in);
        if (file2)
            break;

        cout << "Invalid file name to merge, enter a valid file name:\n";
    }
    file.open(file_name, ios::app);
    string content;
    ostringstream all;
    all << file2.rdbuf();
    content = all.str();
    file << '\n' << content;
    file.close();
    file2.close();
}

void openFile() {
    cout << "Enter the file's name:\n";
    cin >> file_name;
    file_name += ".txt";
    file.open(file_name, ios::in);
    if (!file) cout << "file does not exist!, i created it for you.\n";
    file.close();
}

int getOperation() {
    cout << "1. Add new text to the end of the file\n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content\n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file.\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital)\n"
            "15. Save\n"
            "16. Exit\n";
    cout << "Enter an operation:\n";
    int choice;
    cin >> choice;
    cin.clear();
    cin.sync();
    return choice;
}
