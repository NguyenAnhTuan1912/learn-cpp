/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ trả về dữ liệu trong hàm.
  Vì hàm trả về một giá trị và không trả về giá trị mình đã
  quá rõ cho nên ở đây mình sẽ ví dụ về hàm trả về nhiều giá trị.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <tuple>
#include <stdarg.h>

using namespace std;

struct Result {
  float avg_;
  float sum_;
};

// Định nghĩa một kiểu dữ liệu mới (user-defined type)
typedef tuple<float, float> ResultPair_Tuple;

// Cách 1: dùng với struct
Result GetSumAndAvg(float numbers[], int N) {
  float sum = 0, avg = 0;

  for(int i = 0; i < N; i++) {
    sum += numbers[i];
  };

  avg = sum / N;

  return { avg, sum };
}

// Cách 2: dùng với tuple
ResultPair_Tuple GetSumAndAvgTuple(float numbers[], int N) {
  float sum = 0, avg = 0;

  for(int i = 0; i < N; i++) {
    sum += numbers[i];
  };

  avg = sum / N;

  return { avg, sum };
}

int main() {
  int N;

  // Nhập số phần tử.
  cout << "Nhap so phan tu N: "; cin >> N; cout << endl;

  float numbers[N];

  // Nhập mảng số.
  cout << "Nhap mang so: ";

  for(int i = 0; i < N; i++) {
    cin >> numbers[i];
  };

  cout << "\n";
  cout << "\n";

  cout << "Multiple return values with Struct\n";

  Result r = GetSumAndAvg(numbers, N);

  cout << "Sum of r: " << r.sum_ << endl;
  cout << "Avg of r: " << r.avg_ << endl;

  cout << "\n";

  ResultPair_Tuple r2 = GetSumAndAvgTuple(numbers, N);

  cout << "Multiple return values with Tuple\n";

  cout << "Sum of r2: " << get<1>(r2) << endl;
  cout << "Avg of r2: " << get<0>(r2) << endl;

  // Hoặc có thể là dùng tuple như này
  float avg, sum;
  tie(avg, sum) = GetSumAndAvgTuple(numbers, N);

  cout << "Result of sum: " << sum << endl;
  cout << "Result of avg: " << avg << endl;

  cout << "\n";

  return 0;
};
