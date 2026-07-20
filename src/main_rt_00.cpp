#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
 

/*
Simple class to implement an image saved in PPM format
https://netpbm.sourceforge.net/doc/ppm.html
Few applications load it.
One is IrfanView: https://www.irfanview.com/
*/
struct image {
	image(int _w, int _h) :w(_w), h(_h) { data.resize(w * h * 3, 0); } // initialize buffer (RGB per pixel)
	unsigned int w, h;

	std::vector<int>  data;

	// Set a pixel value (values expected in 0..255)
	template <class S>
	void set_pixel(int i, int j, S  r, S  g, S  b) {
		j = h - 1 - j; // flip vertically for image coordinate system
		data[(j * w + i) * 3] = (unsigned char)r;
		data[(j * w + i) * 3 + 1] = (unsigned char)g;
		data[(j * w + i) * 3 + 2] = (unsigned char)b;
	}

	// Save image as ASCII PPM (P3) file
	void save(const char* filename) {
		ofstream f;
		f.open(filename);
		f << "P3\n";
		f << w << " " << h << std::endl;

		// max color value: use maximum found in buffer 
		// note: it cannot be 0 or laoder will fail, so we use max with 1
		f << std::max(1, *(std::max_element(data.begin(), data.end()))) << std::endl;

		// write each pixel as "R G B" per line
		for (unsigned int i = 0; i < data.size() / 3; ++i)
			f << data[i * 3] << " " << data[i * 3 + 1] << " " << data[i * 3 + 2] << std::endl;
		f.close();
	}
};


int main(int args, char** argv) {
	int sx = 800;
	int sy = 800;
	image a(sx, sy); 


	// iterate over image pixels
	for (int i = 0; i < a.w; ++i)
		for (int j = 0; j < a.h; ++j) 
			a.set_pixel(i, j,0,0,0); // write pixel

	a.save("rendering_00.ppm"); // save to disk
	return 0;
}
