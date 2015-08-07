
// fps.cpp 


#include "fps.h"

namespace MyFps {
	Fps::Fps() {
		this->refresh_per_second = 1;
		this->r_time = clock();
		this->start_time = clock();
		this->real_fps = 0;
		this->counter_frame = 0;
		this->all_frame = 0;
		this->average_fps = 0;
		this->red = 1;
		this->green = 1;
		this->blue = 1;
		this->text_after_fps = "fps : ";
	}

	Fps::Fps(int refresh_per_second, double x, double y, double color_red, double color_green, double color_blue, char* text_after_fps) {
		this->r_time = clock();
		this->start_time = clock();
		this->real_fps = 0;
		this->counter_frame = 0;
		this->all_frame = 0;
		this->average_fps = 0;
		this->red = 1;
		this->green = 1;
		this->blue = 1;
		this->text_after_fps = text_after_fps;
		this->red = color_red;
		this->green = color_green;
		this->blue = color_blue;
		this->x = x;
		this->y = y;
		this->refresh_per_second = refresh_per_second;
	}

	Fps::Fps(int refresh_per_second, double x, double y, double color[3], char* text_after_fps) {
		this->refresh_per_second = refresh_per_second;
		this->r_time = clock();
		this->start_time = clock();
		this->real_fps = 0;
		this->counter_frame = 0;
		this->all_frame = 0;
		this->average_fps = 0;
		this->red = 1;
		this->green = 1;
		this->blue = 1;
		this->text_after_fps = text_after_fps;
		this->red = color[0];
		this->green = color[1];
		this->blue = color[2];
		this->x = x;
		this->y = y;
	}

	void Fps::plusFrame() {
		++all_frame;
		++counter_frame;

		if (clock() - r_time >= 1000 / refresh_per_second) {
			real_fps = counter_frame*refresh_per_second;
			counter_frame = 0;
			r_time = clock();
		}
	}

	void Fps::changeCoordinate(double x, double y) {
		this->x = x;
		this->y = y;
	}

	void Fps::changeColor(double red, double green, double blue) {
		this->red = red;
		this->green = green;
		this->blue = blue;
	}

	void Fps::changeTextAfterFps(char* text) {
		text_after_fps = text;
	}

	void Fps::showFps() {
		glColor3d(red, green, blue);
		sprintf_s(f, "%d", realFps());

		glRasterPos2f(x, y);

		//string = text_after_fps;
		for (c = text_after_fps; *c != '\0'; c++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		}

		//string = f;
		for (c = f; *c != '\0'; c++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		}
	}

	unsigned int Fps::realFps() {
		return real_fps;
	}

	unsigned int Fps::averageFps() {
		(clock() - start_time) > 0 ? average_fps = 1000 * all_frame / (clock() - start_time) : average_fps = 0;
		return average_fps;
	}

	unsigned int Fps::allFrame() {
		return all_frame;
	}

	unsigned int Fps::allTime() {
		return (clock() - start_time);
	}
}