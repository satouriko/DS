#include <iostream>

using namespace std;

void max2(int A[], int lo, int hi, int &x1, int &x2);

int main()
{
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	int x1, x2;
	max2(A, 0, n, x1, x2);
	cout << "Max1:" << A[x1] << "\n";
	cout << "Max2:" << A[x2] << endl;
}

void max2(int A[], int lo, int hi, int &x1, int &x2)
{
	if(lo + 2 == hi) {
		if(A[lo] > A[lo+1]) {
			x1 = lo; x2 = lo+1;
		}
		else {
			x1 = lo+1; x2 = lo;
		}
		return;
	}
	if(lo + 3 == hi) {
		if(A[lo] > A[lo+1]) {
			if(A[lo] > A[lo+2]) {
				x1 = lo; x2 = lo+2;
			}
			else {
				x1 = lo+2; x2 = lo;
			}
		}
		else {
			if(A[lo+1] > A[lo+2]) {
				x1 = lo+1; x2 = lo+2;
			}
			else {
				x1 = lo+2; x2 = lo+1;
			}
		}
		return;
	}
	int mid = (lo + hi) >>1;
	int xl1, xl2; max2(A, lo, mid, xl1, xl2);
	int xr1, xr2; max2(A, mid, hi, xr1, xr2);
	if(A[xl1] > A[xr1]) {
		x1 = xl1;
		if(A[xl2] > A[xr1])
			x2 = xl2;
		else
			x2 = xr1;
	}
	else
	{
		x1 = xr1;
		if(A[xr2] > A[xl1])
			x2 = xr2;
		else
			x2 = xl1;
	}
}
