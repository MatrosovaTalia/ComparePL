package main

import (
	"fmt"
	"time")

func fillGradientLine(arr []uint8, line int, w int, a uint8, b uint8) {
	delta := b - a
	offset := line * w
	for i := 0; i < w; i++ {
		fraction := float32(i) / float32(w)
		arr[offset + i] = a + uint8(float32(delta) * fraction)
	}
}
func generateGrayGradient(h int, w int, a uint8, b uint8) []uint8 {
	size := w * h
	arr := make([]uint8, size)
	for i := 0 ; i < h; i++ {
		fillGradientLine(arr, i, w, a, b)
	}
	return arr
}

func saveGradient(arr []uint8, h int, w int, b uint8) {
	fmt.Printf("P2\n%d %d\n%d\n", w, h, b)
	for i := 0 ; i < h; i++ {
		for j := 0 ; j < w; j++ {
			fmt.Print(arr[i * w + j])
			fmt.Print(" ")
		}
		fmt.Println("")
	}
}

func main() {
	h := 1000
	w := 1000
	a := uint8(55)
	b := uint8(233)
	start := time.Now()
	generateGrayGradient(h, w, a, b)
	elapsed := float32(time.Since(start).Nanoseconds()) / 1000000
	
	fmt.Printf("%f\n", elapsed)
}
