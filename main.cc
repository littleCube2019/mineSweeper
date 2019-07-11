#include "map.h"
#include <iostream>
using namespace std;
void blank(int num){
	for(int i=0;i<num;i++)
		printf("\n");	
}




int main(){
	int size;
	blank(100);
	cout<<"This is a simple minesweeper game"<<endl;
	blank(30);
	while(1){
		cout<<"please enter the size you want to play(4~9))";
		cin>>size;
		getchar();
		if(size>=4 && size<=9){
			break;
		}
		blank(100);
		if(size<4)
			cout<<"\ntoo small,please enter it again.\n";
		if(size>9)
			cout<<"\ntoo large,please enter it again.\n";
	
		
	}
	Map app(size,size);
	Map under(size,size);

	under.Generate();
	int counter=0;
	int  result=-3;
	while(counter<size*size-size){
		int row=0,col=0;
		int sure=0;
		while(sure==0){
			sure=0;
			while(1){
				blank(100);
				app.Print();
				blank(30);
				//under.Print();
				cout<<"choose a valid row";
				cin>>row;
				getchar();
				if(row>size && row<1){
					cout<<"invalid row!\n";
				}
				else{
					cout<<endl;
					break;
				}
			}
			while(1){
				blank(100);
				app.Print();
				blank(30);
				//under.Print();
				cout<<"choose a valid column";
				cin>>col;
				getchar();
				if(col>size && col<1){
					cout<<"invalid column!\n";		
				}
				else{
					cout<<endl;
					break;	
				}

			}
			if(app.getCell(row,col)!=-2){
				cout<<"it`s alredy chosen\npress any key continue";
				//cout<<counter;
				getchar();
				continue;	
			}
			while(1){
				blank(100);
				app.sure(row,col);
				blank(30);
				char ch;
				cout<<"\nAre you choose here(y/n)";
				cin>>ch;
				if(ch=='y') {sure=1;break;}
				else if(ch=='n'){break;}
				else{continue;}
			}
		}
		result=app.Sweep(row,col,under.getCell(row,col));

		if(result==-1){
			break;	
		}
		counter++;
	}
	blank(100);
	if(result==-1) {
		cout<<"Mine booooooom.You lose!\n";
	}
	else if(result >= 0){
		cout<<"Wow,you win the game.You did a great job!\n";	
	}
	
	
	return 0;	
}
