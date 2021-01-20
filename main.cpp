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

	
	Grid baseGrid(30,70, colony);
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
