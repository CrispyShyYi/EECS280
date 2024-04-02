#include "TextBuffer.hpp"
#include <list>
#include <string>

using namespace std;


TextBuffer::TextBuffer():data(), cursor(data.end()), 
row(1), column(0), index(0){ };

bool TextBuffer::forward() {
    if (cursor == data.end()) {
      return false;
    }
    if (*cursor == '\n') {
      ++cursor;
      row++;
      column = 0;
      index++;
      return true;
    }
    ++cursor;
    column++;
    index++;
    return true;
};

bool TextBuffer::backward(){
    if (cursor == data.begin()) {
        // If the cursor is already at the beginning, we cannot move backward
        return false;
    }
    --cursor;
    if(cursor == data.begin()){
        column = 0;
    }
    else if (*cursor == '\n'){
        column = compute_column();
        row -= 1;
    }
    else{
        column -= 1;
    }
    index -= 1;
    return true;
};

void TextBuffer::insert(char c){
    if (c == '\n'){
        data.insert(cursor, c);
        row++;
        column = 0;
        index++;
        return;
    }
    data.insert(cursor, c);
    ++column;
    ++index;
    return;
};

bool TextBuffer::remove(){
    if (cursor == data.end()){
        return false;
    }
    else{
        cursor = data.erase(cursor);
        --index;
        return true;
    }
};

void TextBuffer::move_to_row_start() {
    if (cursor == data.end() || *cursor == '\n') {
        backward();
    }
    while (cursor != data.begin() && *cursor != '\n') {
      backward();
    }
    // in case of reaching previous line, we want to go back
    if (*cursor == '\n') forward();
};

void TextBuffer::move_to_row_end() {
    if (cursor == data.end() || *cursor == '\n') return;
    while (cursor != data.end() && *cursor != '\n') forward();
  };

void TextBuffer::move_to_column(int new_column){
    move_to_row_end();
    int max = compute_column();
    if (new_column >= max) {
        return;
    }
    move_to_row_start();
    for (int i = 0; i < new_column; ++i) {
        forward();
    }
};

bool TextBuffer::up(){
    if (row == 1){
        return false;
    }
    else{
        int targetCColum = column;
        move_to_row_start();
        backward();
        move_to_column(targetCColum);
        return true;
    }
};

bool TextBuffer::down(){
    if (cursor == data.end()) return false;
    int targetColumn = column;
    move_to_row_end();
    if(cursor == data.end()){
        move_to_row_start();
        move_to_column(targetColumn);
        return false;
    }
    forward();
    move_to_column(targetColumn);
    return true;
};

bool TextBuffer::is_at_end() const{
    if(cursor == data.end()) return true;
    else return false;
};

  
char TextBuffer::data_at_cursor() const{
    return *cursor;
};

  
int TextBuffer::get_row() const{
    return row;
};

  
int TextBuffer::get_column() const{
    return column;
};

  
int TextBuffer::get_index() const{
    if (cursor == data.end()) return data.size();
    return index;
};

 
int TextBuffer::size() const{
    int count = 0;
    auto it = data.begin();
    while (it != data.end()){
        count++;
        ++it;
    }
    return count;
};
  
std::string TextBuffer::stringify() const{
    return std::string(data.begin(), data.end());
};

  
int TextBuffer::compute_column() const{
    auto it = data.begin();
    int targetColumn = 0;
    while (it != cursor){
        ++targetColumn;
        if (*it == '\n'){
            targetColumn = 0;
        }
        ++it;
    }
    return targetColumn;
};
