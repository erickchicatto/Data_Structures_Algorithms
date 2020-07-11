#include <iostream>
#include <stdio.h>
#include <stdlib.h>


struct Array {
	int A[10];
	int size;
	int lenght;
};

void Display(struct Array arr) {
	int i;
	printf("Elements are \n");
	for (i = 0; i < arr.lenght;i++) {
		printf("%d",arr.A[i]);
	}
}

void Append(struct Array *arr, int x){ // dir, x
	if (arr->lenght < arr->size) { // length < size , lengt = [x x x x x x x] , size = #elements, 5<10 
		arr->A[arr->lenght++] = x; // A[length++] = x  
	}
}


void Insert(struct Array *arr,int index, int x){

	int i;

	if(index>=0 && index <= arr ->lenght){

		for (i = arr->lenght; i > index;i--) {
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = x;
		arr->lenght++;

	}
}


int Delete(struct Array *arr, int index) {
	
	int x = 0;
	int i ;
	if (index>=0 && index < arr->lenght) {
		
		x = arr->A[index];
		for (i = index; i < arr->lenght - 1;i++) {
			arr->A[i] = arr->A[i + 1];
		}

		arr->lenght--;
		return x;

	}

	return 0;
}
/*int LinearSearch(struct Array arr, int key ){
	int i;
	for (i = 0; arr.lenght;i++){
		if(key==arr.A[i]){
			return i;
		}
		return -1;
	}
}		Se modifica el codigo 
*/

void swap(int* x, int* y) {  // pero solo las direcciones 2,3, paso por referencia para que su alcance sea mayor 
	int temp;
	temp = *x; // temp = 2
	*x = *y; // x= 3
	*y = temp; // y = 2 
}		// 3,2



int LinearSearch(struct Array *arr, int key) {
	int i;
	for (i = 0; arr->lenght; i++) { // -> Se le va a pasar la direccion 
		if (key == arr->A[i]) {
			// transposition 
			swap(&arr->A[i],&arr->A[i-1]);
			/*swap(&arr->A[i],&arr->A[0]);    move Head	
			2*/
			return i;
		}
	}
	return -1;
}

int BinarySearch(struct Array arr , int key) { // aqui no pasamos la direcion 
	int l, mid, h;
	l = 0;
	h = arr.lenght - 1;
	
	while(l<=h){

		mid = (l + h) / 2;
		
		if (key == arr.A[mid]) {
			return mid;
		}

		else if (key < arr.A[mid]) {
			h = mid - 1;
		}

		else {
			l = mid + 1;
		}

	}
	return -1;
}




int main(){

    std::cout << "Data Structures  !\n";
    
	struct Array arr = {{2,3,4,5,6},10,5};

	//printf("%d \n", LinearSearch(&arr,5));

	printf("%d \n",BinarySearch(arr,5));
	Display(arr);
	//Append(&arr,8);
	
	//Insert(&arr,2,10);
	//Delete(&arr,2);

	return 0;
}


