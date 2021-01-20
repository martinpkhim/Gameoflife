#ifndef GRID
#define GRID

#include  <vector>
#include <stdint.h>
#include <Cell.h>

class Grid 
{
public:
	Grid();
	Grid(uint16_t rowNum, uint16_t colNum, std::vector<Cell> cells);
	~Grid();
	
	uint16_t GetColNum();
	uint16_t GetRowNum();
	
	void DrawGrid();
	void ResizeGrid();
	void InitGrid();
	void InitCell(std::vector<Cell>);
	void Evolve(bool bound);
	bool CheckNeighbour(Cell sCell, bool bound);
	
private:
	uint16_t columns;
	uint16_t rows;
	std::vector<std::vector<Cell>> rawGrid;
	std::vector<std::vector<Cell>> rawGridBuffer;
};

#endif