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

bool allPaths(string **maze,int currRow, int currColumn, int row, int column, int i){
//Finds all pathways through maze.
    string **CopyofMaze= new string*[row];  //Creates a new 2D dynamically allocated array 
						//to store each pathway through maze
    for(int i=0; i < row; i++){
        CopyofMaze[i]= new string[column];
    }
    for(int currRow=0; currRow<row; currRow++){
        for(int currColumn=0; currColumn<column; currColumn++){
            CopyofMaze[currRow][currColumn]=maze[currRow][currColumn]; //copy maze into the new created array
        }
    }
    if (currRow <=row-1 && currRow>=0 && currColumn >=0 && currColumn <=column-1 && CopyofMaze[currRow]		 [currColumn]=="."){
            stringstream ss;        //Used for the conversion of number to string
            ss<<i;			//integer i that was initiated at 0 is converted to string
            string num=ss.str(); //Sets number to the contents of the stream
            CopyofMaze[currRow][currColumn]=num;  //Number is set in maze path
            if(row-1==currRow && column-1== currColumn){  //If the current row and current column is equal the 								  //the destination(14,14)
                display(CopyofMaze, row, column);  //Displays maze, Found Destination
                cout<<endl;
                return true;
            }else{
		//Check down and if there is a '.'(path)
                allPaths(CopyofMaze,currRow+1,currColumn,row,column,i+1);
		allPaths(CopyofMaze,currRow,currColumn+1,row,column,i+1); //Check right  for a '.'(pathway)
                allPaths(CopyofMaze,currRow-1,currColumn,row,column,i+1); //Check up for a '.'(pathway)
                allPaths(CopyofMaze,currRow,currColumn-1,row,column,i+1); //Check left for a '.'(pathway)
            }
    return true;
    }
    return false; //if outside of maze boundaries return false
}

bool onePath(string **maze,int currRow, int currColumn, int row, int column,int i){
    //Finds only one path
    if (currRow <=row-1 && currRow>=0 && currColumn >=0 && currColumn <=column-1 && maze[currRow][currColumn]=="."){
    //Current row is less than destination row, current column less than destination column and it is a path 	 //in maze
            stringstream ss;  //Used for the conversion of number to string
            ss<<i;
            string num=ss.str();    //Sets number to the contents of the stream
            maze[currRow][currColumn]=num;//Number is set in maze path
            if(row-1==currRow && column-1== currColumn){    //If the current row and current column is equal the 									//the destination(14,14)
                display(maze, row, column);      //Display Maze, Found destination
                cout<<endl;
                return true;
            }
	   else{
                onePath(maze,currRow+1,currColumn,row,column,i+1);   //Check down and if there is a '.'(path)
                onePath(maze,currRow,currColumn+1,row,column,i+1);  //Check right  for a '.'(pathway)
                onePath(maze,currRow-1,currColumn,row,column,i+1);  //Check up for a '.'(pathway)
                onePath(maze,currRow,currColumn-1,row,column,i+1);  //Check left for a '.'(pathway)
            }
     maze[currRow][currColumn]="."; //If path leads to a dead end, Backtrack to last position in pathway
				    //Mark failed pathway with '.'
     return true;
    }
     return false; //if outside of maze boundaries, return false
}

void display(string **maze, int row, int column){   //Display Maze
	for(int r=0; r<row; r++){
    	   for(int c=0; c<column; c++){
        cout<<setw(3)<< maze[r][c]; //Set width of 3 for all elements of maze to align each column
}
	cout<< endl;
}
}
