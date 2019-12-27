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



class theLaws
{
	public:
		void getData();

	private:
		std::map<std::string, int> wordMap;

};
#endif