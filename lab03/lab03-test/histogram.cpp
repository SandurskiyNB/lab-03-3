#include "histogram.h"
void find_minmax(const vector<double>& numbers, const int numbers_count, double& min, double& max) {
	if (numbers_count == 0)
		return;
	min = numbers[0];
	max = numbers[0];
	for (int i = 1; i < numbers_count; i++)
		if (numbers[i] < min)
			min = numbers[i];
		else
			if (numbers[i] > max)
				max = numbers[i];
}
void svg_begin(double width, double height) {
	cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
	cout << "<svg ";
	cout << "width='" << width << "' ";
	cout << "height='" << height << "' ";
	cout << "viewBox='0 0 " << width << " " << height << "' ";
	cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
	cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
	cout << "<text x='" << left << "' ";
	cout << "y='" << baseline << "'";
	cout << ">" << text << "</text>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
	cout << "<rect ";
	cout << "x='" << x << "' ";
	cout << "y='" << y << "' ";
	cout << "width='" << width << "' ";
	cout << "height='" << height << "' ";
	cout << "stroke='" << stroke << "' ";
	cout << "fill='" << fill << "'/>\n";
}

void svg_frame(bool scaling, int block_width, int block_height, int block_len, int max_freak, int offset_frame, int section_count, int& rightX, int& downY, string stroke) {
	rightX;
	if (scaling)
		rightX = 365;
	else
		rightX = block_width + max_freak * block_len + offset_frame;
	downY = 5 + offset_frame + block_height * section_count + offset_frame;

	cout << "<line x1='5' y1='5' x2 ='" << rightX << "' y2='5' stroke='red' stroke-width='1' stroke-dasharray='5 5'/>";
	cout << "<line x1='" << rightX << "' y1='5' x2 ='" << rightX << "' y2='" << downY << "' stroke='" << stroke << "' stroke-width='1' stroke-dasharray='5 5'/>";
	cout << "<line x1='" << rightX << "' y1='" << downY << "' x2 ='5' y2='" << downY << "' stroke='" << stroke << "' stroke-width='1' stroke-dasharray='5 5'/>";
	cout << "<line x1='5' y1='" << downY << "' x2 ='5' y2='5' stroke='red' stroke-width='1' stroke-dasharray='5 5'/>";
}

void show_histogram_svg(const vector<int>& freak_sections, const int section_count) {

	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = 300;
	const int TEXT_LEFT = 20;
	const int TEXT_BASELINE = 20;
	const int BLOCK_WIDTH = 50;
	const int BLOCK_HEIGHT = 30;
	const int BLOCK_LEN = 10;
	const double FREAK_LIMIT = 30;
	const int OFFSET_FRAME = 15;

	// Поиск максимальной частоты среди частот всех корзин
	int max_freak = freak_sections[0];
	for (int i = 1; i < section_count; i++)
		if (freak_sections[i] > max_freak)
			max_freak = freak_sections[i];

	// Проверка, требуется ли выполнять масштабирование
	bool scaling;
	if (max_freak > FREAK_LIMIT)
		scaling = true;
	else
		scaling = false;

	double shift = 20;
	svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
	for (int i = 0; i < section_count; i++) {
		double section_width;
		if (scaling)
			section_width = BLOCK_LEN * freak_sections[i] / (max_freak / FREAK_LIMIT);
		else
			section_width = BLOCK_LEN * freak_sections[i];
		svg_text(TEXT_LEFT, TEXT_BASELINE + shift, to_string(freak_sections[i]));
		svg_rect(BLOCK_WIDTH, shift, section_width, BLOCK_HEIGHT, "blue", "green");
		shift += BLOCK_HEIGHT;
	}
	//svg_frame(scaling, BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_LEN, max_freak, OFFSET_FRAME, section_count);
	svg_end();
}