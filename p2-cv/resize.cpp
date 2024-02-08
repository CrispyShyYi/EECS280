#include <iostream>
#include <fstream>
#include <string>
#include "Image.hpp"
#include "processing.hpp"

using namespace std;

int main(int argc, char *argv[]) {  
 if(!(argc == 5 || argc == 4)){
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
    << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    return 1;
 }
 bool existHeight = false;
 if (argc == 5){
    existHeight = true;
 }
Image *img = new Image;
string inFile = argv[1];
ifstream ifstr(inFile);
if (!ifstr.is_open()){
    cout << "Error opening file: " << inFile << endl;
    delete img;
    return 1;
}
Image_init(img, ifstr);
int d_width = atoi(argv[3]);
int d_height = Image_height(img);
if (existHeight){
    d_height = atoi(argv[4]);
}
if (((d_width <= 0 || d_width > Image_width(img)) && !existHeight) || 
    (existHeight && (d_width <= 0 || d_width > Image_width(img) || 
    d_height <= 0 || d_height > Image_height(img)))){
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
    << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    delete img;
    return 1;    
}
seam_carve(img, d_width, d_height);
string outFile = argv[2];
ofstream ofstr(outFile);
if(!ofstr.is_open()){
    cout << "Error opening file: " << outFile << endl;
    delete img;
    return 1;
}
Image_print(img, ofstr);
ifstr.close();
ofstr.close();
delete img;
return 0;
}