#include <iostream>
#include <iomanip>
#include<fstream>
#include "hash.h"
#include<list>
#include<string>

using std::string;
using std::list;
using namespace std;

void Hash :: remove (string s)
{

}

void Hash :: processFile (string file)
{
	int index=0;
	string s, line;
//	list<string> :: iterator itr;
	std :: ifstream hashfile(file.c_str());
	//ifstream hashfile;
	hashfile.open(file,ifstream::in);	
	while (!hashfile.eof())
	{
		getline(hashfile,line);
//		while (getline (hashfile,s))
//		{
			cout<<"\nstring: "<<s;
			index = hf(line);
			hashTable[index].push_back(s);
//		}
	}
	hashfile.close();
}

/*
ifstream hashfile;
	hashfile.open(file);

	while(!hashfile.eof())
	{
		getline(hashfile,s);
		index = hf(s);
		hashTable[index].push_back(s);
	}
	hashfile.close();

*/

bool Hash :: search(string s)
{
	int i;
    list<string>::iterator itr;
    
    for(i=0; i<HASH_TABLE_SIZE; i++)
    {
  //      cout << "\n\t";
//        cout << i << ":" << "\t ";
        for (itr=hashTable[i].begin(); itr!=hashTable[i].end(); itr++)
        {
            if (s == *itr)
				return true;
				break;
        }
    }

}

void Hash :: output(string s)
{

}

void Hash :: printStats()
{

}

void Hash::print()                  
{    
    int i;
    list<string>::iterator itr;
    
    for(i=0; i<HASH_TABLE_SIZE; i++)
    {
        cout << "\n\t";
        cout << i << ":" << "\t ";
        for (itr=hashTable[i].begin(); itr!=hashTable[i].end(); itr++)
        {
            cout << " "<<  *itr <<",";
        }
    }

}

           