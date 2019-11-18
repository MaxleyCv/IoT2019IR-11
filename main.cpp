#include <iostream>
#include <math.h>

class Vector{
private:
    int A[5];
public:
    void setVectorel(int a){
        static int ptr = 0;
           this -> A[ptr] = a;
           if (ptr == 4) ptr = -1;
           ptr++;
    }
    int mul(){
        int s = 1;
        for (int i = 0; i< 5; i++){
            s *= A[i];
        }
        return s;
    }
    int* get_arr(){
        return A;
    }
    void SetArrEl(int c){

            std::cin >> this -> A[c];

    }
    friend void PrintArr(Vector* A, int n);
    void merge(int start, int mid, int end) {
        int temp[5];
        int i = start, j = mid+1, k = 0;

        while(i <= mid && j <= end) {
            if(this -> A[i] <= this -> A[j]) {
                temp[k] = this -> A[i];
                k += 1; i += 1;
            }
            else {
                temp[k] = this -> A[j];
                k += 1; j += 1;
            }
        }

        while(i <= mid) {
            temp[k] = this -> A[i];
            k += 1; i += 1;
        }

        while(j <= end) {
            temp[k] = this -> A[j];
            k += 1; j += 1;
        }

        // copy temp to original interval
        for(i = start; i <= end; i += 1) {
            this -> A[i] = temp[i - start];
        }
    }

    void mergeSort(int start, int end) {

        if(start < end) {
            int mid = (start + end) / 2;
            mergeSort(start, mid);
            mergeSort( mid+1, end);
            merge(start, mid, end);
        }

    }
};

void PrintArr(Vector* A, int n){
    for(int i = 0; i<n; ++i)
    {
        std::cout << A -> A[i];
    }
    std::cout << std::endl;
}


int main() {
    Vector A[5];
    for (int i = 0; i<5; i++)
    for (int j = 0; j<5;j++){
        A[j].SetArrEl(i);
    }
    Vector R;
    Vector Fs;
    for (int i = 0; i<5; i++)
        A[i].mergeSort(0, 4);
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++) {
            std::cout << A[j].get_arr()[i] << "\t ";
            R.setVectorel(A[j].get_arr()[i]);
        }
        Fs.setVectorel(R.mul());
        std::cout << std::endl;
    }
    std::cout << "f[i]" << std::endl;
    double sum = 0;
    for (int i = 0; i< 5; i++) {
        sum += pow(abs(Fs.get_arr()[i]), 0.2);
        std::cout << pow(abs(Fs.get_arr()[i]), 0.2) << " ";
    }
    std::cout << std::endl;
    std::cout << "F(f[i]): \n" << sum/5 << std::endl;
    return 0;
}