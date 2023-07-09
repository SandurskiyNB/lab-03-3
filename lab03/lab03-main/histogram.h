#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;
// Функция поиска минимума и максимума среди чисел
void find_minmax(const vector<double>& numbers, const int numbers_count, double& min, double& max);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "blue", string fill = "green");
void svg_frame(bool scaling, const int block_width, const int block_height, const int block_len, const int max_freak, const int offset_frame, const int section_count, int& rightX, int&downY, const string stroke = "red");
void show_histogram_svg(const vector<int>& freak_sections, const int section_count);