#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File
{
public:
	File() {
		filename = "empty";
		filesize = 0;
	}
	File(string filename, int filesize) {
		this->filename = filename;
		this->filesize = filesize;
	}
	~File() {
	}

	void print() {

	}

	void setFileName(string filename) {
		this->filename = filename;
	}
	string getFileName() {
		return filename;
	}
	void setFileSize(int filesize) {
		this->filesize = filesize;
	}
	int getFileSize() {
		return filesize;
	}

protected:
	string filename;
	int filesize;
};

class ImageFile : public File
{
public:
	ImageFile() : File() {
		width = 0;
		height = 0;
	}
	ImageFile(string filename, int filesize, int width, int height) {
		this->filename = filename;
		this->filesize = filesize;
		this->width = width;
		this->height = height;		
	}
	~ImageFile() {
	}

	void print() {
		cout << getFileName() << " is a "
			<< width << "x" << height << " image file "
			<< "(" << getFileSize() << ")" << endl;
	}

	void setWidth(int width) {
		this->width = width;
	}
	int getWidth() {
		return width;
	}
	void setHeight(int height) {
		this->height = height;
	}
	int getHeight() {
		return height;
	}

private:
	int width, height;
};

class AudioFile : public File 
{
public:
	AudioFile() : File() {
		duration = 0;
	}
	AudioFile(string filename, int filesize, int duration) {
		this->filename = filename;
		this->filesize = filesize;
		this->duration = duration;
	}
	~AudioFile() {
	}

	void print() {
		cout << getFileName() << " is a "
			<< duration << " seconds long audio file "
			<< "(" << getFileSize() << ")" << endl;
	}

	void setDuration(int duration) {
		this->duration = duration;
	}
	int getDuration() {
		return duration;
	}	

private:
	int duration;
};

class DocumentFile : public File 
{
public:
	DocumentFile() : File() {
		nrOfWords = 0;
	}
	DocumentFile(string filename, int filesize, int nrOfWords) {
		this->filename = filename;
		this->filesize = filesize;
		this->nrOfWords = nrOfWords;
	}
	~DocumentFile() {
	}

	void print() {
		cout << getFileName() << " is a "
			<< nrOfWords << " words long document file "
			<< "(" << getFileSize() << ")" << endl;
	}

	void setNrOfWords(int nrOfWords) {
		this->nrOfWords = nrOfWords;
	}
	int getNrOfWords() {
		return nrOfWords;
	}

private:
	int nrOfWords;
};

class VideoFile : public File
{
public:
	VideoFile() : File() {
		width = 0;
		height = 0;
		duration = 0;
	}
	VideoFile(string filename, int filesize, int width, int height, int duration) {
		this->filename = filename;
		this->filesize = filesize;
		this->width = width;
		this->height = height;
		this->duration = duration;
	}
	~VideoFile() {
	}

	void print() {
		cout << getFileName() << " is a "
			<< duration << " seconds long "
			<< width << "x" << height << " video file " 
			<< "(" << getFileSize() << ")" << endl;
	}

	void setWidth(int width) {
		this->width = width;
	}
	int getWidth() {
		return width;
	}
	void setHeight(int height) {
		this->height = height;
	}
	int getHeight() {
		return height;
	}
	void setDuration(int duration) {
		this->duration = duration;
	}
	int getDuration() {
		return duration;
	}

private:
	int width, height, duration;
};

int main()
{
	File file;
	ImageFile image;
	AudioFile audio;
	DocumentFile document;
	VideoFile video;

	string type;
	string imageType = "jpg", imageType_2 = "png";
	string audioType = "mp3";
	string documentType = "pdf", documentType_2 = "odt";
	string videoType = "mp4", videoType_2 = "mkv";
	
	int size = 0, width = 0, height = 0, nrOfWords = 0, audioDuration = 0, videoDuration = 0;
		
	ifstream MyReadFile("filelist.txt");

	while (MyReadFile >> type >> size >> width, nrOfWords, audioDuration >> height >> videoDuration) 
	{		
		if (type.find(imageType) || type.find(imageType_2)) 
		{
			image.setFileName(type);
			image.setFileSize(size);
			image.setWidth(width);
			image.setHeight(height);
			image.print();
		}
		else if (type.find(audioType))
		{
			audio.setFileName(type);
			audio.setFileSize(size);
			audio.setDuration(audioDuration);
			audio.print();
		}
		else if (type.find(documentType) || type.find(documentType_2))
		{
			document.setFileName(type);
			document.setFileSize(size);
			document.setNrOfWords(nrOfWords);
			document.print();
		}
		else if (type.find(videoType) || type.find(videoType_2))
		{
			video.setFileName(type);
			video.setFileSize(size);
			video.setWidth(width);
			video.setHeight(height);
			video.setDuration(videoDuration);
			video.print();
		}
	}

	MyReadFile.close();
}