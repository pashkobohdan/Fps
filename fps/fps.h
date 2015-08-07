
// fps.h


#include <glut.h>	// for library functions glut
#include <ctime>	// for function clock()
#include <stdio.h>	// for function sprintf()

#pragma comment(lib, "fps")

namespace MyFps {
	class Fps {
	private:
		double x, y;
		double red, green, blue;
		unsigned int real_fps;		//fps in this moment
		unsigned int r_time;		//time in this moment
		unsigned int start_time;	//start time
		unsigned int average_fps;	//average value of fps
		unsigned int counter_frame;	//counter of frame (in 1 period)
		unsigned int all_frame;		//all frame

		int type;					// display type fps
		unsigned int refresh_per_second;

		char* text_after_fps;		// text that is displayed after fps
		char f[4];					// array for save fps
		char *c;
		char *string;

	public:

		Fps();														// default constructor

		Fps(int refresh_per_second, double x, double y, double color_red, double color_green, double color_blue, char* text_after_fps);

		Fps(int refresh_per_second, double x, double y, double color[3], char* text_after_fps);

		void plusFrame();											// plus one frame to all_frame and r_frame

		void changeCoordinate(double x, double y);					// change coordinate for show real_fps

		void changeColor(double red, double green, double blue);	// change color of text (real_fps)

		void changeTextAfterFps(char* text);						// change text_after_fps

		void renderText(char *string, float x, float y);			// render text (with start coordinate)

		void renderText(char *string);								// render text (without start coordinate)

		void showFps();												// show real_fps in screen

		unsigned int realFps();										// caluluate real_fps and return him

		unsigned int averageFps();									// calculate average_fps and return him

		unsigned int allFrame();									// return all_frame (for all time)

		unsigned int allTime();										// return all_time
	};
}
