#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define UNUSED(x) (void)(x)

#define FILENAME_RED   "rawdata/img-5400x3600x8-r.bin"
#define FILENAME_GREEN "rawdata/img-5400x3600x8-g.bin"
#define FILENAME_BLUE  "rawdata/img-5400x3600x8-b.bin"
#define FILENAME_OUT   "img.bmp"

#define X_RESOLUTION 5400
#define Y_RESOLUTION 3600

void open_files(FILE** file_red, FILE** file_green, FILE** file_blue, FILE** file_out) {
	// open rgb raw data files
	if( (*file_red = fopen(FILENAME_RED, "rb")) == NULL) {
		fprintf(stderr, "Cannot open " FILENAME_RED);
		perror(" ");
		exit(1);
	}
	
	if( (*file_green = fopen(FILENAME_GREEN, "rb")) == NULL) {
		fprintf(stderr, "Cannot open " FILENAME_GREEN);
		perror(" ");
		exit(1);
	}
	
	if( (*file_blue = fopen(FILENAME_BLUE, "rb")) == NULL) {
		fprintf(stderr, "Cannot open " FILENAME_BLUE);
		perror(" ");
		exit(1);
	}
	
	// open output file
	if( (*file_out = fopen(FILENAME_OUT, "wb")) == NULL) {
		fprintf(stderr, "Cannot open " FILENAME_OUT);
		perror(" ");
		exit(1);
	}
}

void write_header(FILE* file_out) {
	// TODO: insert code here
}

void write_data(FILE* file_red, FILE* file_green, FILE* file_blue, FILE* file_out) {
	// TODO: insert code here
}

int main(int argc, char** argv) {
	UNUSED(argc);
	UNUSED(argv);
	FILE* file_red;
	FILE* file_green;
	FILE* file_blue;
	FILE* file_out;
	
	open_files(&file_red, &file_green, &file_blue, &file_out);
	
	write_header(file_out);
	
	write_data(file_red, file_green, file_blue, file_out);
	
	fclose(file_red);
	fclose(file_green);
	fclose(file_blue);
	fclose(file_out);
}