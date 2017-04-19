//Ashley Gittens 
//Title: Maze Program
//This is a Maze program that reads in a maze text file and finds one or all pathways
//through a maze using recursion and backtracking to find the final destination.

#include <iostream>
#include <fstream>  //used for ifstream
#include <cstdlib>
#include <sstream>  //used for stringstream
#include <iomanip>  //used for setw

using namespace std;

void display(string **maze, int row, int column); //Display maze function
bool allPaths(string **maze,int currRow, int currColumn, int row, int column, int i);
bool onePath(string **maze,int currRow, int currColumn, int row, int column,int i);

int main()
{   string readRow,readCol;     //Read row and column from file
    string filename;            //Name of read file
    cout<<"Please enter the name of the input file:";
    getline(cin,filename);      //Gets user input of text file
    ifstream mefile;
    mefile.open(filename.c_str());	
    if(!mefile){			//If file not open
        cout << "Maze.txt could not be accessed!" << endl;
    }
    if(mefile.is_open()){		//If file is open
        mefile >>readRow>> readCol;     //Read row and column from file
        }
    
    int rows= atoi(readCol.c_str());  //Convert row to integer from string
    int column= atoi(readCol.c_str());  //Convert column to integer from string
    cout<< "This maze has " <<  rows << " rows" << " and " <<column << " columns";
    cout<<endl;
    string** path= new string*[rows];  //Dynamically allocate 2D array for maze
    for(int i=0; i < rows; i++){
    	path[i]= new string[column];
}
    for(int r=0; r<rows; r++){
    	for(int c=0; c<column; c++){
             mefile>>path[r][c]; //Maze read from file and stored in array
    }
}
    cout<<"This is the maze you entered"<<endl;
    display(path,rows,column);      //Displays orginal maze before pathway is found
    mefile.close();
    cout<<endl;
    cout<<"Finding a path....."<<endl;
    cout<< "Please enter the number of the task you wish to run."<<endl;
    cout<<"Enter 1 for Find One Path."<<endl;
    cout<<"Enter 2 for Find All Paths."<<endl;
    int startRow=0,startCol=0;              //Starts at beginning of maze (0,0)

    int caseNum;
    cout<<"Chosen case is: ";
    cin>>caseNum;
    cout<<endl;
    switch(caseNum){
    case 1:
    	if(onePath(path,startRow,startCol, rows, column,0)==true){  //Checks for Pathway in Maze
        	cout<<"Path was found!";}
        else{
            	cout<<"Path was not found!";
        }
    	break;
    case 2:
    	if(allPaths(path,startRow,startCol, rows, column,0)==true){     //Checks for all pathways in Maze
        	cout<< "Path was found!";}
        else{
            	cout<< "Path not found!";
        }
    	break;
    default:
    	cout<<"Error, Wrong Input!";            //User entered a invalid input.
    }
    	return 0;
}
