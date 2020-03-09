#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int count11 = 0;

void sortAndCountInv (int C[], int n)
{
    if(n > 1) {
        int n1 = ceil((double)n/2);
        int n2 = n/2;
        int A[n1];
        int B[n2];
        int index = 0;
        for(int i = 0; i < n1; i++) {
            A[index] = C[i];
            index++;
        }
        index = 0;
        for(int i = n1; i < n; i++) {
            B[index] = C[i];
            index++;
        }

        sortAndCountInv(A, n1);
        sortAndCountInv(B, n2);

        //A is left half
        //B is right half

        index = 0;
        int i = 0; //index for A
        int j = 0; //index for B
        while(i < n1 && j < n2) {

            if(A[i] <= B[j]) {
                //no inversion
                C[index] = A[i];
                index++;
                i++;
            }
            else {
                //inversion ,YES
                count11 += (n1 - i);
                C[index] = B[j];
                index++;
                j++;
            }
        }
        for(; i < n1; i++) {
            C[index] = A[i];
            index++;
        }
        for(; j < n2; j++) {
            C[index] = B[j];
            index++;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sortAndCountInv(array, n);

    cout << count11 << endl;

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

}
