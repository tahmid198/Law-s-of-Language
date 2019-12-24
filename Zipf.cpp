//Created by Tahmid Zaman
//
//My homeboy Zifh and his law
//
//CPP file

#include "Zipf.hpp"

//---------------------------------BEGIN function to read/write textFile data-----------
void Zipf::getData()
{
	std::string input; 

	std::string file_name; 
	std::fstream my_file;  //using fstream to read and write file

	std::cout << "which file do you want to open?";
    std::cin >> file_name;

    my_file.open(file_name.c_str());
    
    while(!my_file.eof())
    {
    	my_file >> input; //Get input

    	std::cout << input << " "; //Print output
    }

    my_file.close(); // Close file
}
//----------------------------------END function to read/write textFile data------------
