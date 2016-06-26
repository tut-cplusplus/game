#include <iostream>
#include <fstream>

#include "Image.hpp"

using namespace std;

void Image::allocate(void)
{
	if (data != nullptr)
		delete[] data;
	data = new unsigned char[width * height * 4];
	if (data == nullptr)
		throw CannotAllocateException();
}

Image::Image()
	: data(nullptr)
{

}

Image::Image(const string& fpath)
	: data(nullptr)
{
	readPPM(fpath);
}

Image::Image(const Image& image)
	: width(image.width), height(image.height), data(nullptr)
{
	allocate();
	copy(image.data, image.data + width * height * 4 - 1, data);
}

Image::~Image()
{
	delete[] data;
}

void Image::readPPM(const string& fpath)
{
	ifstream fin(fpath, ios::in | ios::binary);
	if (!fin)
		throw FileCannotOpenException();

	char buf[BUF_SIZE];
	fin.getline(buf, BUF_SIZE);
	if (string(buf) != "P6")
		throw InvalidFileException();
	fin.getline(buf, BUF_SIZE);
	fin >> width >> height;
	int colorNum;
	fin >> colorNum;
	if (colorNum != 255)
		throw InvalidFileException();
	fin.read(buf, 1);
	allocate();
	unsigned char* ptr = data;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int n = 3;
			unsigned char color[n];
			fin.read((char*)color, n);
			for (int k = 0; k < n; k++)
				*ptr++ = color[k];
			*ptr++ = 0x00;
		}
	}
}
void Image::writePPM(const string& fpath)
{
	ofstream fout(fpath, ios::out | ios::binary);
	if (!fout)
		throw FileCannotOpenException();

	fout << "P6" << endl;
	fout << "#comment" << endl;
	fout << width << " " << height << endl;
	fout << 255 << endl;
	unsigned char* ptr = data;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fout.write((const char*)ptr, 3);
			ptr += 4;
		}
	}

}

