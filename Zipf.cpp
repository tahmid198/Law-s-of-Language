//Created by Tahmid Zaman
//
//My homeboy Zifh and his law
//
//CPP file

#include "Zipf.hpp"

//---------------------------------BEGIN function to read/write textFile data--------------------
void theLaws::getData()
{
	std::string input; 

	std::string file_name; 
	std::fstream my_file;  //using fstream to read and write file

	std::cout << "What file do you want to open?" << std::endl;
    std::cin >> file_name;

    my_file.open(file_name.c_str());
    
    while(my_file >> input)
    {
        //my_file >> input; //Get input

        //boost::to_lower(input);
        //convert string to lower case

        //-------------------------------------------conver each char in input str to lowercase---------------------
        for(char &c:input)
        {
           c = tolower(c);
        } //if words are not the same cases program will identify the an uppercase word and lowercase word as two diffrent words (Ex. You & you)


        //--------------------------------this is to remove punctuations in input str---------------
        for (int i = 0, len = input.size(); i < len; i++)
        {
            if (ispunct(input[i]))
            {
                input.erase(i--, 1);
                len = input.size();
            }
        }

        //---------------------------------increment the value of each WORD----------------------------

        //increment/insert new word with operator[]
        wordMap[input]++;  // increment map's value for key 'input'
    
        //increment using the insert() function
        /*
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
        */

    	std::cout << input << " "; //Print output 
    }

    std::cout << std::endl;

    my_file.close(); // Close file
}
//-------------------------------------END function to read/write textFile data--------------------------


//-------------------------------------BEGIN sort function need to sort the map--------------------------

//this shorts the map using a vecor of pairs, it copies the map into a vector of key-values pairs, and then 
//sorts the vector in decending order 


//compartor function
bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) 
{ 
    return (a.second > b.second); 
} 

void theLaws::sortMap()
{
    std::cout << "The map, sorted by keys, is: " << std::endl;
    for (std::map<std::string, int>::iterator it = wordMap.begin();it !=  wordMap.end(); it++)
    {
        std::cout << it->first << "::" << it->second << std::endl;
    }

    // create a empty vector of pairs
    std::vector<std::pair<std::string, int>> vec;

    // copy key-value pairs from the map to the vector
   
    for ( std::map<std::string, int>::iterator it2 = wordMap.begin(); it2 != wordMap.end(); it2++) 
    {
        vec.push_back(make_pair(it2->first, it2->second));
    }

    //sort the vector by increasing order of its pair's second value
    std::sort(vec.begin(), vec.end(), sortByVal); 

    // print the vector
    std::cout << "The map, sorted by value is: " << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i].first << ":: " << vec[i].second << std::endl;
    }
    
}
//-----------------------------------------------END sort function---------------------------------------------


















