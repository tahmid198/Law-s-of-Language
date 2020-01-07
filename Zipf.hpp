// Created by Tahmid Zaman 
//
//Zifh's Law
// 
//Header file

#ifndef Zipf_hpp
#define Zipf_hpp

#include <iostream>
#include <fstream> 	//Stream class to both read and write from/to files.
				  	//ofstream: Stream class to write on files
					//ifstream Stream class to read from files
#include <string>
#include <iterator> 
#include <map> 
#include <string>
#include <vector>
#include <algorithm> // for sort function
//#include <boost/algorithm/string.hpp>



class theLaws
{
	public:
		void getData();
		void sortMap();
		//bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b); 

	private:
		std::map<std::string, int> wordMap; //create the map


};
#endif