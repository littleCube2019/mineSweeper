#ifndef MAP_H
#define MAP_H

class Map{	
    public:
    	//constructor
	Map(int ,int );
    	
	int getCell(int ,int);

    	//functional
	int Sweep(int,int,int);	
	void Print(); 
	void Generate();
	void sure(int,int);
	bool _inBound(int ,int );
		
	//destructor
	~Map();
	
	
    private:
	int row;
	int col;
	int  _checkMine(int,int);
	void _set(int,int,int);
	int **map;
	int numMine;
};







#endif

