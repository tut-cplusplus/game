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

vector<string> Image::getTokens(string str) const
{

	vector<string> tokens;
	while (str.length()) {
		size_t pos = str.find(" ");
		if (pos == string::npos) {
			tokens.push_back(str);
			break;
		}
		string token(str, 0, pos);
		tokens.push_back(token);
		str.erase(0, pos + 1);
	}
	return tokens;
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

	char* buf = new char[BUF_SIZE];
	fin.getline(buf, BUF_SIZE);
	if (string(buf, 2) != "P6")
		throw InvalidFileException();
	fin.getline(buf, BUF_SIZE);
	if (buf[0] == '#') {
		fin >> width >> height;
	} else {
		vector<string> tokens = getTokens(string(buf));
		width = atoi(tokens[0].c_str());
		height = atoi(tokens[1].c_str());
	}
	int colorNum;
	fin >> colorNum;
	if (colorNum != 255)
		throw InvalidFileException();
	fin.seekg(0, fin.beg);
	fin.seekg(0, fin.end);
	streampos length = fin.tellg();
	fin.seekg((int)length - width * height * 3, fin.beg);
	//fin.read(buf, 1);
	delete[] buf;
	allocate();
	unsigned char* ptr = data;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			const int n = 3;
			unsigned char color[n];
			fin.read((char*)color, n);
			for (int k = 0; k < n; k++)
				*ptr++ = color[k];
			*ptr = 0xFF;
			int sum = (int)color[0] + color[1] + color[2];
			if (sum == 3 * 255 || sum == 0)
				*ptr = 0x00;
			ptr++;
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

