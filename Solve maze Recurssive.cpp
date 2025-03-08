#include<iostream>
using namespace std;
bool isSafe(int arr[5][5],int x,int y)
{
	return(x>=0 && x<5 && y>=0 && y<5 && arr[x][y] == 1);
}
bool solvemaze(int maze[5][5],int output[5][5],int x,int y)
{
	if(x==4 && y==4)//reached destination...
	{
		output[x][y] = 1;
		return true;
	}
	if(isSafe(maze,x,y))
	{
		output[x][y] = 1;
		if (solvemaze(maze,output,x,y+1))
		{
			return true;
		}
		if (solvemaze(maze,output,x+1,y))
		{
			return true;
		}
		output[x][y] = 0;//backtrack
		return false;
	}
	return false;
}
int main()
{
	int maze[5][5] = {
						{1,0,1,0,1},
						{1,1,1,1,1},
						{0,1,0,1,1},
						{1,0,0,1,1},
						{1,1,1,0,1}
					};
	int output[5][5] = {0};
	solvemaze(maze,output,0,0);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		cout<<output[i][j]<<"\t";
		}
		cout<<endl;
	}

	
}