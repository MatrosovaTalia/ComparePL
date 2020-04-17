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

    double gradient_time;
    
    struct timespec start, end, elapsed;
    clock_gettime(CLOCK_REALTIME, &start);
    generateGrayGradient(h, w, a, b);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed.tv_nsec = end.tv_nsec - start.tv_nsec;
    elapsed.tv_sec  = end.tv_sec - start.tv_sec;
    
    printf ("%lf\n", 1000 * elapsed.tv_sec + elapsed.tv_nsec / 1e6);
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
