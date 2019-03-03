#pragma once
#include <memory>
#include "Cell.h"
#include "Prebuilt.h"

std::unique_ptr<Cell[]> setInfinite(std::unique_ptr<Cell[]> infinite)
{
	infinite[24 * 64 + 35].setLife(1);
	infinite[25 * 64 + 35].setLife(1);
	infinite[25 * 64 + 36].setLife(1);
	infinite[26 * 64 + 36].setLife(1);
	infinite[26 * 64 + 37].setLife(1);
	infinite[27 * 64 + 36].setLife(1);
	infinite[27 * 64 + 37].setLife(1);
	infinite[27 * 64 + 38].setLife(1);
	infinite[28 * 64 + 36].setLife(1);
	infinite[28 * 64 + 37].setLife(1);
	infinite[29 * 64 + 35].setLife(1);
	infinite[29 * 64 + 36].setLife(1);
	infinite[30 * 64 + 35].setLife(1);

	infinite[26 * 64 + 30].setLife(1);
	infinite[26 * 64 + 31].setLife(1);
	infinite[27 * 64 + 30].setLife(1);
	infinite[27 * 64 + 31].setLife(1);
	infinite[28 * 64 + 30].setLife(1);
	infinite[28 * 64 + 31].setLife(1);

	infinite[27 * 64 + 26].setLife(1);
	infinite[27 * 64 + 27].setLife(1);
	infinite[28 * 64 + 27].setLife(1);
	infinite[28 * 64 + 26].setLife(1);

	infinite[48 * 64 + 23].setLife(1);
	infinite[48 * 64 + 24].setLife(1);
	infinite[49 * 64 + 24].setLife(1);
	infinite[50 * 64 + 21].setLife(1);
	infinite[50 * 64 + 22].setLife(1);
	infinite[50 * 64 + 23].setLife(1);
	infinite[51 * 64 + 21].setLife(1);

	infinite[28 * 64 + 47].setLife(1);
	infinite[29 * 64 + 47].setLife(1);
	infinite[30 * 64 + 47].setLife(1);

	infinite[28 * 64 + 49].setLife(1);
	infinite[30 * 64 + 49].setLife(1);
	infinite[27 * 64 + 50].setLife(1);
	infinite[28 * 64 + 50].setLife(1);
	infinite[29 * 64 + 50].setLife(1);
	infinite[30 * 64 + 50].setLife(1);
	infinite[31 * 64 + 50].setLife(1);
	infinite[26 * 64 + 51].setLife(1);
	infinite[26 * 64 + 52].setLife(1);
	infinite[27 * 64 + 51].setLife(1);
	infinite[27 * 64 + 52].setLife(1);
	infinite[31 * 64 + 51].setLife(1);
	infinite[31 * 64 + 52].setLife(1);
	infinite[32 * 64 + 51].setLife(1);
	infinite[32 * 64 + 52].setLife(1);

	infinite[26 * 64 + 58].setLife(1);
	infinite[27 * 64 + 56].setLife(1);
	infinite[28 * 64 + 56].setLife(1);
	infinite[29 * 64 + 55].setLife(1);
	infinite[27 * 64 + 60].setLife(1);
	infinite[29 * 64 + 61].setLife(1);
	infinite[30 * 64 + 61].setLife(1);
	infinite[30 * 64 + 60].setLife(1);
}
std::unique_ptr<Cell[]> setBird(std::unique_ptr<Cell[]> bird)
{
	bird[25 * 64 + 13].setLife(1);
	bird[25 * 64 + 14].setLife(1);
	bird[26 * 64 + 11].setLife(1);
	bird[26 * 64 + 12].setLife(1);
	bird[26 * 64 + 14].setLife(1);
	bird[26 * 64 + 15].setLife(1);
	bird[27 * 64 + 11].setLife(1);
	bird[27 * 64 + 12].setLife(1);
	bird[27 * 64 + 13].setLife(1);
	bird[27 * 64 + 14].setLife(1);
	bird[28 * 64 + 12].setLife(1);
	bird[28 * 64 + 13].setLife(1);

	bird[33 * 64 + 13].setLife(1);
	bird[33 * 64 + 14].setLife(1);
	bird[34 * 64 + 10].setLife(1);
	bird[34 * 64 + 11].setLife(1);
	bird[34 * 64 + 12].setLife(1);
	bird[34 * 64 + 14].setLife(1);
	bird[34 * 64 + 15].setLife(1);
	bird[35 * 64 + 10].setLife(1);
	bird[35 * 64 + 11].setLife(1);
	bird[35 * 64 + 12].setLife(1);
	bird[35 * 64 + 13].setLife(1);
	bird[35 * 64 + 14].setLife(1);
	bird[36 * 64 + 11].setLife(1);
	bird[36 * 64 + 12].setLife(1);
	bird[36 * 64 + 13].setLife(1);

	bird[41 * 64 + 13].setLife(1);
	bird[41 * 64 + 14].setLife(1);
	bird[42 * 64 + 9].setLife(1);
	bird[42 * 64 + 10].setLife(1);
	bird[42 * 64 + 11].setLife(1);
	bird[42 * 64 + 12].setLife(1);
	bird[42 * 64 + 14].setLife(1);
	bird[42 * 64 + 15].setLife(1);
	bird[43 * 64 + 9].setLife(1);
	bird[43 * 64 + 10].setLife(1);
	bird[43 * 64 + 11].setLife(1);
	bird[43 * 64 + 12].setLife(1);
	bird[43 * 64 + 13].setLife(1);
	bird[43 * 64 + 14].setLife(1);
	bird[44 * 64 + 10].setLife(1);
	bird[44 * 64 + 11].setLife(1);
	bird[44 * 64 + 12].setLife(1);
	bird[44 * 64 + 13].setLife(1);

	bird[49 * 64 + 13].setLife(1);
	bird[49 * 64 + 14].setLife(1);
	bird[50 * 64 + 8].setLife(1);
	bird[50 * 64 + 9].setLife(1);
	bird[50 * 64 + 10].setLife(1);
	bird[50 * 64 + 11].setLife(1);
	bird[50 * 64 + 12].setLife(1);
	bird[50 * 64 + 14].setLife(1);
	bird[50 * 64 + 15].setLife(1);
	bird[51 * 64 + 8].setLife(1);
	bird[51 * 64 + 9].setLife(1);
	bird[51 * 64 + 10].setLife(1);
	bird[51 * 64 + 11].setLife(1);
	bird[51 * 64 + 12].setLife(1);
	bird[51 * 64 + 13].setLife(1);
	bird[51 * 64 + 14].setLife(1);
	bird[52 * 64 + 9].setLife(1);
	bird[52 * 64 + 10].setLife(1);
	bird[52 * 64 + 11].setLife(1);
	bird[52 * 64 + 12].setLife(1);
	bird[52 * 64 + 13].setLife(1);
}