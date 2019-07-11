#include "map.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//-3:null    -2:covered  -1:mine



Map::Map(int inr,int inc){
	row=inr+2;  //for bound issue
	col=inc+2;
	numMine=inr;
	map=new int* [row];
	for(int i=0;i<row;i++){
		map[i]=new int[col];
		for(int j=0;j<col;j++){
			if(i==0||i==row-1 ||j==0 ||j==col-1){
				map[i][j]=-3;	
			}

			else
				map[i][j]=-2;
		}
	}
	
}	

int Map::getCell(int r,int c){
	return map[r][c];	
}

void Map::_set(int r,int c,int s){
	map[r][c]=s;  //assume r,c is already valid!
}


void Map::Print(){
	//print col number
	cout<<"      Col"<<endl<<"      ";

	for(int i=1;i<col-1;i++){
		cout<<" "<<i<<" ";	
	}
	cout<<endl;


	//print row & grid

	for(int i=1;i<row-1;i++){
		if(i==1)cout<<"Row "<<i<<" ";
		else cout<<"    "<<i<<" ";

		for(int j=1;j<col-1;j++){
			if(map[i][j]==-3){
				cout<<"   ";	
			}
			else if(map[i][j]==-2){
				cout<<"[ ]";	
			}
			else if(map[i][j]==-1){
				cout<<"[*]";	
			}
			else{
				cout<<"["<<map[i][j]<<"]";
			}
					
		}
		cout<<endl;
	}	
}
void Map::sure(int r,int c){
	//print col number
	cout<<"      Col"<<endl<<"      ";

	for(int i=1;i<col-1;i++){
		cout<<" "<<i<<" ";	
	}
	cout<<endl;


	//print row & grid

	for(int i=1;i<row-1;i++){
		if(i==1)cout<<"Row "<<i<<" ";
		else cout<<"    "<<i<<" ";
		for(int j=1;j<col-1;j++){
			if(i==r && j==c) cout<<"[X]";
			else{
				if(map[i][j]==-3){
					cout<<"   ";	
				}
				else if(map[i][j]==-2){
					cout<<"[ ]";	
				}
				else if(map[i][j]==-1){
					cout<<"[*]";	
				}
				else{
					cout<<"["<<map[i][j]<<"]";
				}
			}		
		}
		cout<<endl;
	}	
}

bool Map::_inBound(int r,int c){
	if(r<row-1 && r>0 && c>0 && c<col-1)
		return  true;
	else
		return false;	
}
int Map::_checkMine(int r,int c){
	int num=0;
	for(int i=r-1;i<=r+1;i++){
		for(int j=c-1;j<=c+1;j++){
				if(map[i][j]==-1){
					num++;		
				}
			
		}	
	}
	return num;	
}

int Map::Sweep(int r,int c,int s){
	map[r][c]=s;
	return s;	
}

void Map::Generate(){
	srand(time(NULL));
	for(int i=0;i<numMine;i++){
		int r=rand()%(row-2)+1;
		int c=rand()%(col-2)+1;
		if(map[r][c]==-1){
			i--;
			continue;	
		}
		map[r][c]=-1;
	}	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		   if(map[i][j]!=-1){
			if(i==0||i==row-1 ||j==0 ||j==col-1){
				map[i][j]=-3;	
			}

			else
				map[i][j]=_checkMine(i,j);
		   }
		}	
	}
	
}


Map::~Map(){
	for(int i=0;i<row;i++){
		delete map[i];
	}
	delete map;	
}
		
	
