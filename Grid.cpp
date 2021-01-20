#include <Grid.h>
#include <iostream>

Grid::Grid()
{
	columns = 50;
	rows = 30;
	ResizeGrid();
	InitGrid();
	//DrawGrid();
}

Grid::Grid(uint16_t rowNum,uint16_t colNum, std::vector<Cell> cells)
{
	columns = colNum;
	rows = rowNum;
	ResizeGrid();
	InitGrid();
	InitCell(cells);
	//DrawGrid();
	
}


Grid::~Grid()
{
}


uint16_t Grid::GetColNum()
{
	return columns;
}

uint16_t Grid::GetRowNum()
{
	return rows;
}

void Grid::DrawGrid()
{
	for(uint16_t i = 0;i < rawGrid.size();i++)
	{
		for(uint16_t j = 0;j < rawGrid[i].size();j++)
		{
			std::cout << rawGrid.at(i).at(j).GetState();
		}
		std::cout << std::endl;
	}
}

void Grid::ResizeGrid()
{
	rawGrid.resize(rows);
	rawGridBuffer.resize(rows);
	for(uint16_t i = 0;i < rows;i++)
	{
		rawGrid.at(i).resize(columns);
		rawGridBuffer.at(i).resize(columns);
	}
	
}

void Grid::InitGrid()
{
	for(uint16_t i = 0;i < rawGrid.size();i++)
	{
		for(uint16_t j = 0;j < rawGrid.at(i).size();j++)
		{
			rawGrid.at(i).at(j).SetState(false);
			rawGrid.at(i).at(j).SetX(j);
			rawGrid.at(i).at(j).SetY(i);
			
			rawGridBuffer.at(i).at(j).SetState(false);
			rawGridBuffer.at(i).at(j).SetX(j);
			rawGridBuffer.at(i).at(j).SetY(i);
		}
		
	}
}

void Grid::InitCell(std::vector<Cell> cells)
{
	for(uint16_t i = 0;i < cells.size();i++)
	{
		rawGrid.at(cells.at(i).GetX()).at(cells.at(i).GetY()).SetState(true);
		rawGridBuffer.at(cells.at(i).GetX()).at(cells.at(i).GetY()).SetState(true);
	}
}

bool Grid::CheckNeighbour(Cell sCell, bool bound)
{
	bool shouldLive = false;
	// Check the neighbouring 8 cells
	// Count the live cells
	uint8_t liveCount = 0;
	
	//Make things overlap
	int16_t topY = 0, bottomY = 0,
			 rightX = 0, leftX = 0,
			 midY = 0, midX = 0;
			 
	topY = sCell.GetY()-1;
	bottomY = sCell.GetY()+1;
	rightX = sCell.GetX()+1;
	leftX = sCell.GetX()-1;
	midX = sCell.GetX();
	midY = sCell.GetY();
	

	if(bound)
	{
		if(topY < 0)
		{
			topY = 0;
		}
		
		if(bottomY > (rows-1))
		{
			bottomY = (rows-1);
		}
		
		if(rightX > (columns-1))
		{
			rightX = (columns-1);
		}
		
		if(leftX < 0)
		{
			leftX = 0;
		}
	}
	else
	{
		if(topY < 0)
		{
			topY += rows;
		}
		
		if(bottomY > (rows-1))
		{
			bottomY -= (rows-1);
		}
		
		if(rightX > (columns-1))
		{
			rightX -= (columns-1);
		}
		
		if(leftX < 0)
		{
			leftX += columns;
		}
	}
	
	
	//Bottom left
	if(rawGridBuffer.at(bottomY).at(leftX).GetState())
	{
		liveCount++;
	}
	//Middle left
	if(rawGridBuffer.at(midY).at(leftX).GetState())
	{
		liveCount++;
	}
	//Top left
	if(rawGridBuffer.at(topY).at(leftX).GetState())
	{
		liveCount++;
	}
	// Top middle
	if(rawGridBuffer.at(topY).at(midX).GetState())
	{
		liveCount++;
	}
	// Top right
	if(rawGridBuffer.at(topY).at(rightX).GetState())
	{
		liveCount++;
	}
	// Right middle
	if(rawGridBuffer.at(midY).at(rightX).GetState())
	{
		liveCount++;
	}
	// Right bottom
	if(rawGridBuffer.at(bottomY).at(rightX).GetState())
	{
		liveCount++;
	}
	// Middle bottom
	if(rawGridBuffer.at(bottomY).at(midX).GetState())
	{
		liveCount++;
	}
	
	if((bottomY == (rows-1)) || ((topY) == 0) || (rightX == (columns-1)) || (leftX == 0))
	{
		liveCount = 0;
	}
	
	if(sCell.GetState())
	{
		if(liveCount == 2 || liveCount == 3)
		{
			shouldLive = true;
		}
	}
	else
	{
		if(liveCount == 3)
		{
			shouldLive = true;
		}
	}

	

	return shouldLive;
}

void Grid::Evolve(bool bound)
{
	bool newState = false;
	
	// Sweep through all of the cells in the grid
	for(uint16_t i = 0;i < rawGrid.size();i++)
	{
		for(uint16_t j = 0;j < rawGrid.at(i).size();j++)
		{
			newState = CheckNeighbour(rawGridBuffer.at(i).at(j),bound);
			rawGrid.at(i).at(j).SetState(newState);
		}
	}
	rawGridBuffer = rawGrid;
}