#include<iostream>
/* Linear Regression
  Created 10/31/2024
*/
float average(float set[], int len) {
	float sum = 0;
	for (int i = 0; i < len; i++) {
		sum += set[i];
	}
	return sum / len;
}

float linear(float x, float m, float x1, float y1) {
	return (m * (x - x1)) + y1;
}

float cost(float x[], float y[], int len, float m, float x1, float y1) {
	//dx is 1
	float cost = 0.0;
	for (int i = 0; i < len; i++) {
		cost += (linear(x[i], m, x1, y1) - y[i]) * (linear(x[i], m, x1, y1) - y[i]);
	}
	return cost;
}

float costDerivative(float x[], float y[], int len, float m, float x1, float y1) {
	//definition of a derivative
	float h = 0.0001;
	float fx = cost(x, y, len, m, x1, y1);
	float fxh = cost(x, y, len, m + h, x1, y1);
	return (fxh - fx) / h;
}

int main() {
	
	float x[] = { 1.0 , 2.0, 3.0, 4.0, 5.0 };
	float y[] = { 0.2,  1.32, 2.2, 3.41, 4.91 };
	int len = 5;

	float x1 = average(x, len);
	float y1 = average(y, len);

	float m = 1.0;

	for(int i = 0; i < 500; i++) { // run this loop for more accuracy
		float costD = costDerivative(x, y, len, m, x1, y1);
		m = m - costD/100.0;
	}

	float b = (m * -x1) + y1;
 
	printf("y = %fx + %f", m, b);


}