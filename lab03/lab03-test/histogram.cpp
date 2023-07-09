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

void show_histogram_svg(const vector<int>& freak_sections, const int section_count) {

	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = 300;
	const int TEXT_LEFT = 20;
	const int TEXT_BASELINE = 20;
	const int BLOCK_WIDTH = 50;
	const int BLOCK_HEIGHT = 30;
	const int BLOCK_LEN = 10;
	const double FREAK_LIMIT = 30;

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

	double shift = 0;
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
	svg_end();
}