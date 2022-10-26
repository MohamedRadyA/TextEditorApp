// Program Name: TextEditor.cpp
// Last Modification Date: 16/05/2022
// Purpose: Text Editor Main Application File

#include "TextEditorFunc.cpp"

int main() {
    openFile();
    int choice = 0;
    while (choice != 16) {
        choice = getOperation();
        switch (choice) {
            case 1:
                add_content();
                break;
            case 2:
                display_content();
                break;
            case 3:
                empty_content();
                break;
            case 4:
                encrypt_content();
                break;
            case 5:
                decrypt_content();
                break;
            case 6:
                mergeFiles();
                break;
            case 7:
                getNumOfWords();
                break;
            case 8:
                getNumOfChars();
                break;
            case 9:
                getNumOfLines();
                break;
            case 10:
                findWord();
                break;
            case 11:
                findWordCount();
                break;
            case 12:
                upperCaseFile();
                break;
            case 13:
                lowerCaseFile();
                break;
            case 14:
                firstCapsFile();
                break;
            case 15:
                save();
                break;
            case 16:
                break;
            default:
                cout << "Enter a valid operation (1-16): \n";
        }
    }
    file.close();
    cout << "Thanks for using FCAI Text Editor.";
    return 0;
}
