#include "stdafx.h"
#include "Bitmap.hpp"

Bitmap::Bitmap()
{
}

Bitmap::~Bitmap()
{
}

void Bitmap::load_bitmap(std::string file_name)
{
	std::ifstream bitmap_filestream;
	bitmap_filestream.open(file_name, std::ifstream::in | std::ifstream::binary);

	// Parse the bitmap data
	bitmap_filestream.read(this->header_, 54);

	std::string header(this->header_);
	LOG_DEBUG("Bitmap header: " + header);

	this->dataPos_ = *(int*)&(this->header_[10]);	// 0x0a
	this->imageSize_ = *(int*)&(this->header_[34]);	// 0x22
	this->width_ = *(int*)&(this->header_[18]);		// 0x12
	this->height_ = *(int*)&(this->header_[22]);	// 0x16

	LOG_DEBUG("Data Position:" + std::to_string(this->dataPos_));
	LOG_DEBUG("Image Size:" + std::to_string(this->imageSize_));
	LOG_DEBUG("Width:" + std::to_string(this->width_));
	LOG_DEBUG("Height:" + std::to_string(this->height_));

	int buffer_size = this->width_ * this->height_ * 3; // 3 bytes per pixel (one for each of B, G, R)

	this->data_ = new char[buffer_size];

	// ??? Waste the rest of the bytes between end of header and start of data pos?
	bitmap_filestream.read(this->data_, this->dataPos_ - 54);

	bitmap_filestream.read(this->data_, buffer_size);

	bitmap_filestream.close();
}

int Bitmap::get_width() const
{
	return this->width_;
}

int Bitmap::get_height() const
{
	return this->height_;
}

int Bitmap::get_data_pos() const
{
	return this->dataPos_;
}

char* Bitmap::get_data() const
{
	return this->data_;
}