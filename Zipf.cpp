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
    
    while(!my_file.eof())
    {
        
    	my_file >> input; //Get input

        //-------------------------------- this is to remove punctuations in input word------------
        for (int i = 0, len = input.size(); i < len; i++)
        {
            if (ispunct(input[i]))
            {
                input.erase(i--, 1);
                len = input.size();
            }
        }

        //insert with operator[] --> dont know how this works yet
        //for (std::map<std::string, int>::iterator it = wordMap.begin();it !=  wordMap.end(); it++) 
        //{
        //    wordMap[input]++;  // increment map's value for key 'c'
        //}


        wordMap.insert(std::pair<std::string, int>(input, 1));  //std::insert cannot mutate existing values; operator[] can, if you want to use insert(), you would need to erase the value first

    	std::cout << input << " "; //Print output 
    }
    
    for (std::map<std::string, int>::iterator it = wordMap.begin();it !=  wordMap.end(); it++)
    {
        std::cout << it->first << "::" << it->second << std::endl;
    }

    my_file.close(); // Close file
}
//----------------------------------END function to read/write textFile data------------
