#ifndef CELL
#define CELL

#include <stdint.h>


class Cell
{
public:
	Cell();
	Cell(uint16_t xVal, uint16_t yVal, bool iState);
	~Cell();
	
	void SetPlace(uint16_t xVal, uint16_t yVal);
	void GetPlace(uint16_t *xVal, uint16_t *yVal);
	void SetY(uint16_t nY);
	uint16_t GetY();
	void SetX(uint16_t nX);
	uint16_t GetX();
	char GetLiveCellSymbol();
	char GetDeadCellSymbol();
	void SetState(bool nState);
	bool GetState();
	
private:
	uint16_t x;
	uint16_t y;
	bool state;
	char deadCell;
	char liveCell;
};

#endif