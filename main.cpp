/*  Feb 11 2026
    The following program takes in a text file and returns the encrypted 
    version of it using a shift/caesar cypher.

    If the encrypted file is passed with the same integer key it was encrypted 
    with then the program will create a new file decrypted.txt
    with the decrypted text contents.
    
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>


void shift_cypher(int key, std::ifstream& file, std::ofstream& output);

int main(int argc, char* argv[]){
    
    if(argc < 4){ //- > <program.name> <decrypt/encrypt> <filename> <key>
        std::cerr << "Usage: " << argv[0] << " <decrypt/encrypt> <filename> <key>\n";
        return -1;
    }

    //read key from the argv[3]
    //pre-condition: The key must be between 1-93
    //
    int key;
    try{
        key = std::stoi(argv[3]);
    }
    catch(const std::exception&){
        std::cerr << "Invalid key! Must be an integer between 1-93!\n";
        return 1;
    }

    if(key < 1 || key > 93){
        std::cerr << "key must be between 1-93\n";
        return 1;
    }

    //file in from argv[2]
    //
    std::string file_name = argv[2];
    std::ifstream input_text(file_name);

    if(!input_text.is_open()){
        std::cerr << "Error: could not open file " << file_name << "\n";
        return 1;
    }

    
    // transform the flag char array( argv[1] ) to all lowercase
    //
    std::string str = argv[1];
    std::transform(str.begin(), str.end(), str.begin(), 
        [](unsigned char c){return std::tolower(c);});
    
    // Last preprocess step is to make sure the flag is spelled correctly.
    //
    if(str == "encrypt"){
        // open the ofstream object
        //
        std::ofstream output_text("encrypted.txt");

        if(!output_text){
            std::cerr << "Error creating file\n";
            return 1;
        }

        //call encrypt
        //
        shift_cypher(key, input_text, output_text);

        input_text.close();
        output_text.close();
    }
    else if(str == "decrypt"){
        std::ofstream output_text("decrypted.txt");
        if(!output_text){
            std::cerr << "Error creating file\n";
            return 1;
        }

        //The key is passed as a negative so the function starts decrypting
        //
        shift_cypher(-key, input_text, output_text);

        input_text.close();
        output_text.close();
    }
    else{
        std::cerr<< "Usage: " << argv[0] <<" <flag> <filename> <key>\n";
        return 1;
    }

    
    return 0;
}

void shift_cypher(int key, std::ifstream& file, std::ofstream& output){
    
    std::string line;
    key = key %94;
    
    while(std::getline(file, line)){

        for(int i = 0; i < line.size(); i++){

            if(line[i] >= '!' && line[i] <= '~'){

                int j = line[i] - '!';

                int k = ((j + key) % 94 + 94) % 94;

                output << (char) ('!' + k);

            }
            else{
                output << (char) line[i];
            }

        }
        // getline removes the '\n' from the input file for some reason
        //
        output << '\n'; 
    }
    
}