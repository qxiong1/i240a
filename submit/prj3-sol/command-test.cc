#include <memory>
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "command.hh"
#include "command-stream.hh"
#include "priority-queue.hh"

using namespace std;

int main(int argc, char* argv[])
{
  	if (argc != 2) 
  	{
 	   cerr << "usage: " << argv[0] << " FILE_PATH" << endl;
 	   exit(1);
 	}
  
	ifstream f(argv[1]);
	if(!f.is_open())
		exit(EXIT_FAILURE);


///*
 	MaxHeap q0;
 	MinHeap q1;

 	//cout << "#head of queue shown on left; start out with q0: [ ]; q1: [ ]" << endl;
	string command;
	while(f >> command)
	{
		if(command == "enter")
		{
			string id;
			int p0, p1;
			f >> id >> p0 >> p1;
			Job j(id, p0, p1);

			q0.enqueue(j);
			cout << command << " " << j << " ";
		}
		else if(command == "move")
		{
			if(q0.size() > 0)
			{
				Job j = q0.dequeue();
				q1.enqueue(j);
				cout << command << " " << j << " ";
			}
			else
				continue;
		}
		else if(command == "leave")
		{
			if(q1.size() > 0)
			{
				Job j = q1.dequeue();
				cout << command << " " << j << " ";
			}
			else
				continue;
		}
		else
			cout << "[" << command << "] not found. " << endl;
		//cout << "\t#q0: " << q0 << "; q1:" << q1;
		cout << endl;
	}
//*/
	
  	f.close();
  	return EXIT_SUCCESS;
}
