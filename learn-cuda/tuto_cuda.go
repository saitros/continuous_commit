package main

/*
void square(float *a, int N);
*/

import (
	"C"
	"fmt"
)

func Square(a []float32){
	C.square((*C.float)(&a[0]), C.int(len(a)))
}

func main(){
	a := []float32{1.0, 2.0, 3.0}
	Square(a)
	fmt.Println(a)
}

