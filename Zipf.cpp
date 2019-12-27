//Created by Tahmid Zaman
//
//My homeboy Zifh and his law
//
//CPP file

#include "Zipf.hpp"

//---------------------------------BEGIN function to read/write textFile data-----------
void theLaws::getData()
{
	std::string input; 

	std::string file_name; 
	std::fstream my_file;  //using fstream to read and write file

	std::cout << "What file do you want to open?";
    std::cin >> file_name;

    my_file.open(file_name.c_str());
    
    while(my_file >> input)
    {
        
    	//my_file >> input; //Get input

        //-------------------------------- this is to remove punctuations in input word------------
        for (int i = 0, len = input.size(); i < len; i++)
        {
            if (ispunct(input[i]))
            {
                input.erase(i--, 1);
                len = input.size();
            }
        }

        //insert new word with operator[]
        //wordMap[input]++;  // increment map's value for key 'input'
    
        
        
        // check if key 'c' exists in the map or not
        std::map<std::string,int>::iterator it = wordMap.find(input);

        // key already present in the map
        if (it != wordMap.end()) 
        {
            it->second++;   // increment map's value for key 'c'
        }
        // key not found
        else 
        {
            wordMap.insert(std::pair<std::string, int>(input, 1));  //std::insert cannot mutate existing values; operator[] can, if you want to use insert(), you would need to erase the value first
        }
        

    	std::cout << input << " "; //Print output 
    }
    std::cout << std::endl;
    
    for (std::map<std::string, int>::iterator it = wordMap.begin();it !=  wordMap.end(); it++)
    {
        std::cout << it->first << "::" << it->second << std::endl;
    }

    my_file.close(); // Close file
}
//----------------------------------END function to read/write textFile data------------
