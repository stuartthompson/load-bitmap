#pragma once
#ifndef LOADBITMAP_APPLICATION_BITMAP_HPP
#define LOADBITMAP_APPLICATION_BITMAP_HPP

#include "stdafx.h"

class Bitmap
{
public:
	Bitmap();
	~Bitmap();

	void load_bitmap(std::string file_name);

	int get_width() const;
	int get_height() const;
	int get_data_pos() const;
	char* get_data() const;

private:
	char header_[54];			// Bitmap files begin with a 54-byte header
	unsigned int dataPos_;		// Position in file where actual data begins
	unsigned int width_;		// Image width
	unsigned int height_;		// Image height
	unsigned int imageSize_;	// width * height * 3 (RGB per pixel)
	char* data_;				// Actual RGB data
};

#endif