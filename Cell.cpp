#include <Cell.h>

Cell::Cell()
{
	x = 0;
	y = 0;
	state = false;
}

Cell::Cell(uint16_t xVal, uint16_t yVal, bool iState)
{
	x = xVal;
	y = yVal;
	state = iState;
}

Cell::~Cell()
{
	
}

void Cell::SetPlace(uint16_t xVal, uint16_t yVal)
{
	x = xVal;
	y = yVal;
}

void Cell::GetPlace(uint16_t *xVal, uint16_t *yVal)
{
	*xVal = x;
	*yVal = y;
}

void Cell::SetX(uint16_t nX)
{
	x = nX;
}

uint16_t Cell::GetX()
{
	return x;
}

void Cell::SetY(uint16_t nY)
{
	y = nY;
}

uint16_t Cell::GetY()
{
	return y;
}

void Cell::SetState(bool nState)
{
	state = nState;
}

bool Cell::GetState()
{
	return state;
}