/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về non-type parameter.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

namespace Example_01 {

// Tạo ra một template để in mảng
template<typename T, int N>
void PrintArray(T arr[]) {
  for(int i = 0; i < N; i++) {
    if(i < N - 1) cout << arr[i] << " ";
    else cout << arr[i] << endl;
  };
};

};

// Một số hàm
constexpr int GetN(int n = 5) { return n; };
int GetRandNumber(int from, int to) { return (rand() % (to - from + 1)) + from; };
void FillArrayWithRanNumbers(int arr[], int N) {
  for(int i = 0; i < N; i++) arr[i] = GetRandNumber(1, 100);
};

int main() {
  // Khởi tạo một số biến
  int INVALID_N = 10;
  constexpr int VALID_N = 5;
  const int VALID_N_02 = 10;

  /*
    Khởi tạo các mảng. Cách khởi tạo này sẽ tương ứng với cách dùng
    value parameters của template bên dưới.
  */
  int arr_01[VALID_N];
  int arr_02[VALID_N_02];
  int arr_03[GetN(7)];
  int arr_04[GetN()];

  // Điền các giá trị ngẫu nhiên cho arr_01 và arr_02
  FillArrayWithRanNumbers(arr_01, VALID_N); // 5 elements
  FillArrayWithRanNumbers(arr_02, VALID_N_02); // 10 elements
  FillArrayWithRanNumbers(arr_03, GetN(7)); // 7 elements
  FillArrayWithRanNumbers(arr_04, GetN()); // 5 elements

  cout << "Print arrays\n";
  // Cách dùng các value value parameters cho template
  cout << "Element of arr_01: "; Example_01::PrintArray<int, VALID_N>(arr_01);
  cout << "Element of arr_02: "; Example_01::PrintArray<int, VALID_N_02>(arr_02);
  cout << "Element of arr_03: "; Example_01::PrintArray<int, GetN(7)>(arr_01);
  cout << "Element of arr_04: "; Example_01::PrintArray<int, GetN()>(arr_02);

  return 0;
};
