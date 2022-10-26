// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: TextEditorFunc.h
// Last Modification Date: 16/05/2022
// Author1 and ID and Group: Mohamed Rady 20210506
// Author2 and ID and Group: Shawky Ebrahim 20210184
// Author3 and ID and Group: Abdelrahman Gomaa 20210224
// Teaching Assistant: Eng Yousra & Nesma
// Purpose: Text Editor functions library header file

#ifndef TEXT_EDITOR_FUNCTION_HEADER
#define TEXT_EDITOR_FUNCTION_HEADER

#include<bits/stdc++.h>
#include <conio.h>

using namespace std;

fstream file;
string file_name;
void openFile();
int getOperation();
void add_content();
void display_content();
void empty_content();
void encrypt_content();
void decrypt_content();
void mergeFiles();
void getNumOfWords();
void getNumOfChars();
void getNumOfLines();
void findWord();
void findWordCount();
void upperCaseFile();
void lowerCaseFile();
void firstCapsFile();
void save();

#endif
