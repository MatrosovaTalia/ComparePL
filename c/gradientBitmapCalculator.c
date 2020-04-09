#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillGradientLine(unsigned char* arr, int line, int w, unsigned char a, 
                                                            unsigned char b);
unsigned char* generateGrayGradient(int h, int w, unsigned char a, 
                                                  unsigned char b);
void saveGradient(unsigned char* arr, int h, int  w, unsigned char b);


int main(){
    int h = 50;
    int w = 50;
    unsigned char a = 55;
    unsigned char b = 233;

    clock_t start, end;
    double gradient_time;
    
    start = clock();
    generateGrayGradient(h, w, a, b);
    end = clock();
    gradient_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", gradient_time);

    // saveGradient(arr, h, w, b);


    return 0;
}

void fillGradientLine(unsigned char* arr, int line, int w, unsigned char a, 
                                                            unsigned char b) {
	unsigned char delta = b - a;
	int offset = line * w;
	for (int i = 0; i < w; i++){
		float fraction = (float) i / (float) w;
		arr[offset + i] = a + (unsigned char)((float) delta * fraction);
	}
    return;
};

unsigned char* generateGrayGradient(int h, int w, unsigned char a, 
                                                  unsigned char b){
	int size = w * h;
	unsigned char* arr = (unsigned char*)malloc(size *sizeof(unsigned char));
	for (int i = 0; i < h; i++){
		fillGradientLine(arr, i, w, a, b);
	}
	return arr;
}

void saveGradient(unsigned char* arr, int h, int  w, unsigned char b) {
	printf("P2\n%d %d\n%d\n", w, h, b);
	for(int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			printf("%d ", arr[i * w + j]);
		}
		printf("\n");
	}
    return;
}
