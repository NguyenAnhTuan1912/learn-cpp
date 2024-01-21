/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về pointer và array.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

// Hàm lặp mảng
void PrintArray(int a[], int N) {
  for(int i = 0; i < N; i++)
    if(i < N - 1) cout << a[i] << " ";
    else cout << a[i] << "\n";
};

// Hàm này sẽ dùng con trỏ để lặp với mảng.
void PrintArrayWithPointer(int* ptr_begin, int N) {
  int* ptr_end = ptr_begin + N;
  for(; ptr_begin != ptr_end; ptr_begin++) {
    if(ptr_begin < ptr_end - 1) cout << *ptr_begin << " ";
    else cout << *ptr_begin << "\n";
  }
};

int main() {
  // Khai báo mảng
  int
    N = 5,
    arr[N] = { 20, -102, 13, 42, -100 };

  // Khai báo con trỏ
  int* ptr_arr = arr;

  // In ptr_arr và arr
  cout << "Value of ptr_arr: "<< ptr_arr << endl;
  cout << "Value of arr: " << arr << endl;

  cout << "\n";

  // In con trỏ
  cout << "Print Array\n";
  PrintArray(arr, N);

  cout << "\n";

  // Truy cập vào phần tử đầu tiên và thứ 2 của mảng
  cout << "Access first element\n";

  cout << "Value of arr[0]: " << arr[0] << endl;
  cout << "Value of *ptr_arr: " << *ptr_arr << endl;
  cout << "Value of arr[1]: " << arr[1] << endl;
  cout << "Value of *ptr_arr: " << *(++ptr_arr) << endl;

  cout << "\n";

  cout << "Print array without pointer\n";

  int* ptr_arr_02 = arr;
  PrintArrayWithPointer(ptr_arr_02, N);

  cout << "\n";

  return 0;
};
