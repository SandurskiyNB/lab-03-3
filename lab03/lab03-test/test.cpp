#include "histogram.h"
#include <cassert>
void test__find_minmax() {

	double min = 0;
	double max = 0;
	find_minmax({ 1, 2, 3 }, 3, min, max);
	assert(min == 1);
	assert(max == 3);

	min = 0;
	max = 0;
	find_minmax({ -1, -2, -3 }, 3, min, max);
	assert(min == -3);
	assert(max == -1);

	min = 0;
	max = 0;
	find_minmax({ 1, 1, 1 }, 3, min, max);
	assert(min == 1);
	assert(max == 1);

	min = 0;
	max = 0;
	find_minmax({ 1 }, 1, min, max);
	assert(min == 1);
	assert(max == 1);

	min = 0;
	max = 0;
	find_minmax({}, 0, min, max);
	assert(min == 0);
	assert(max == 0);
}

void test__svg_frame() {
	int rightX;
	int downY;
	svg_frame(false, 50, 30, 10, 5, 15, 3, rightX, downY);
	assert(rightX == 115);
	assert(downY == 125);
}
int main() {
	test__find_minmax();
	test__svg_frame();
}