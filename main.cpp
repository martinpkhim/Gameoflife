#include <stdio.h>
#include <iostream>
#include <printf.h>
#include <vector>
#include <Grid.h>
#include <Cell.h>

#include <unistd.h>

#define		BOUND_ON		true
#define		BOUND_OFF		false

int main(int argc, char **argv)
{
	std::vector<Cell> colony;
	colony.push_back(Cell(5,34,true));
	colony.push_back(Cell(5,35,true));
	colony.push_back(Cell(5,36,true));
	colony.push_back(Cell(6,36,true));
	colony.push_back(Cell(6,34,true));
	colony.push_back(Cell(7,36,true));
	colony.push_back(Cell(4,33,true));
	colony.push_back(Cell(3,31,true));
	colony.push_back(Cell(4,33,true));
	colony.push_back(Cell(7,35,true));
	colony.push_back(Cell(6,33,true));
	
	colony.push_back(Cell(15,34,true));
	colony.push_back(Cell(15,35,true));
	colony.push_back(Cell(15,36,true));
	colony.push_back(Cell(16,36,true));
	colony.push_back(Cell(16,34,true));
	colony.push_back(Cell(17,36,true));
	colony.push_back(Cell(14,33,true));
	colony.push_back(Cell(13,31,true));
	colony.push_back(Cell(14,33,true));
	colony.push_back(Cell(17,35,true));
	colony.push_back(Cell(16,33,true));
	
	
	colony.push_back(Cell(10,22,true));
	colony.push_back(Cell(11,21,true));
	colony.push_back(Cell(12,20,true));
	colony.push_back(Cell(9,21,true));
	colony.push_back(Cell(8,20,true));
	colony.push_back(Cell(7,21,true));
	
	colony.push_back(Cell(10,32,true));
	colony.push_back(Cell(11,31,true));
	colony.push_back(Cell(12,30,true));
	colony.push_back(Cell(9,31,true));
	colony.push_back(Cell(8,30,true));
	colony.push_back(Cell(7,31,true));
	
	
	colony.push_back(Cell(18,32,true));
	colony.push_back(Cell(19,31,true));
	colony.push_back(Cell(18,30,true));
	colony.push_back(Cell(14,31,true));
	colony.push_back(Cell(16,30,true));
	colony.push_back(Cell(15,31,true));
	 

	
	Grid baseGrid(40,100, colony);
	baseGrid.DrawGrid();

	while(1)
	{
		// Evolve the cell colony
		// Redraw the Grid
		//usleep(30000);	// fast
		usleep(200000);		// moderate
		//sleep(1);			// slow
		system("clear");
		baseGrid.Evolve(BOUND_ON);
		baseGrid.DrawGrid();
	}
	
	return 0;
}
