/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy bài tập ví dụ về higher-order function với lambda.

  Đề bài:
  1. Đầu tiên là một function A sẽ nhận vào các hàm tính toán, hàm đó sẽ trả về một lambda
  và lambda này sẽ nhận vào hai tham số dùng để tính dựa trên các hàm được truyền vào function A trước đó.
  Ngoài ra trong function A sẽ nhận vào một lambda để tính kết quả giữa result hiện tại với kết quả tính
  của mỗi hàm tính toán trong mỗi lần lặp.

  2. Viết một function B nhận vào một mảng, N phần tử của mảng và một lambda, hàm này sẽ lặp qua mảng đó và
  dùng lambda để thao tác từng phần tử của mảng.

  3. Viết một function C tương tự như function B ở câu hai, nhưng lambda có thể trả về giá trị của từng
  phần tử mà nó lặp qua, từ đó có thể thay đổi giá trị của phần tử đó trong function C.

  4. Làm lại tất cả các bài trên nhưng dùng với vector và không có đối số N.
*/

#include <iostream>
// Để sử dụng được class function thì mình phải include lib này
#include <functional>
// Thêm lib này để dùng vector
#include <vector>

// Khai báo một số type.
/*
  Cái này có liên quan tới template, nhưng giải thích sơ qua.
  Hàm này sẽ trả về một function, function đó nhận 2 tham số
  có kiểu dữ liệu là float và có kiểu dữ liệu trả về cũng là float.
*/
typedef std::function<float(float, float)> CalculatorFunction;
typedef CalculatorFunction ComputeResultFunction;
typedef CalculatorFunction ComputeResultFunctionCallBack;
typedef std::function<void(float, int, int)> VoidIterationCallerFunction;
typedef std::function<float(float, int, int)> IterationCallerFunction;

// Khai báo một namespace chứa các lambdas.
namespace Lambdas {

VoidIterationCallerFunction _PrintElement_L = [](float element, int N, int index) {
  if(index == N - 1) std::cout << element;
  else std::cout << element << " ";
};

IterationCallerFunction _MultiWith_2_L = [](float element, int N, int index) {
  return element * 2;
};

IterationCallerFunction _AddWith_10_L = [](float element, int N, int index) {
  return element + 10;
};

};
// Khai báo một namespace chứa các functions.
namespace Functions {

float Add(float a, float b) {
  return a + b;
};

float Sub(float a, float b) {
  return a - b;
};

float Div(float a, float b) {
  return a / b;
};

float Mul(float a, float b) {
  return a * b;
};

// Hàm compose các calculator function để tạo ra một hàm compute.
ComputeResultFunction GetComputeResultFn
(
  CalculatorFunction fns[],
  int N,
  ComputeResultFunctionCallBack _Cb_L
) {
  // Trả về một lambda.
  return [fns, N, _Cb_L](float a, float b) {
    float result = 0;

    for(int i = 0; i < N; i ++) {
      result = _Cb_L(result, fns[i](a, b));
    };

    return result;
  };
};

// Hàm này sẽ lặp qua một mảng giống for_each
void ForEach(float numbers[], int N, VoidIterationCallerFunction _Cb_L) {
  for(int i = 0; i < N; i++) {
    _Cb_L(numbers[i], N, i);
  };
};

// Hàm này sẽ lặp qua một mảng giống với map
void Map(float numbers[], int N, IterationCallerFunction _Cb_L) {
  for(int i = 0; i < N; i++) {
    numbers[i] = _Cb_L(numbers[i], N, i);
  };
};

// Hàm compose các calculator function để tạo ra một hàm compute với vector.
ComputeResultFunction GetComputeResultWithVectorFn
(
  std::vector<CalculatorFunction> fns,
  ComputeResultFunctionCallBack _Cb_L
) {
  int N = fns.size();

  // Trả về một lambda.
  return [fns, N, _Cb_L](float a, float b) {
    float result = 0;

    for(int i = 0; i < N; i ++) {
      result = _Cb_L(result, fns[i](a, b));
    };

    return result;
  };
};

// Hàm này sẽ lặp qua một mảng giống for_each nhưng dùng với vector
void ForEachWithVector
(
 std::vector<float> numbers,
 VoidIterationCallerFunction _Cb_L
) {
  int N = numbers.size();

  for(int i = 0; i < N; i++) {
    _Cb_L(numbers.at(i), N, i);
  };
};

// Hàm này sẽ lặp qua một mảng giống với map nhưng dùng với vector
void MapWithVector
(
 std::vector<float> &numbers,
 IterationCallerFunction _Cb_L
) {
  int N = numbers.size();

  for(int i = 0; i < N; i++) {
    numbers.at(i) = _Cb_L(numbers.at(i), N, i);
  };
};

};

using namespace std;
using namespace Lambdas;
using namespace Functions;

int main() {
  // Khai báo 2 số
  float a = 10, b = 4, result = 0;
  int N = 2, M = 10, J = 5;
  // Khai báo một mảng Calculator Function.
  CalculatorFunction fns[N] = { Add, Add };
  // Khai báo một mảng số
  float
    numbers[M] = { -1, 23, 42, -100, 12, 45, 16, 90, 10, -55 },
    numbers_02[J] = { 10, 9, -5, 2, 100 };

  // Khai báo 2 vector
  vector<float>
    numbers_vec = { -10, 12, 33, 99, 45, 90, 100, 39 },
    numbers_vec_02 = { 0, 1, 9, 5, -19, 20, 3 };
  // Khai báo một vector chứa các calculator function
  vector<CalculatorFunction> fns_vec = { Add, Mul, Add, Sub };

  // Khai báo một lambda để tính kết quả của tích lũy và kết quả của calculator
  auto ComputeAccAndCurrResult = [](float acc, float curr) { return acc + curr; };
  // Lấy ResultingFunction
  auto ComputeResult = GetComputeResultFn(fns, N, ComputeAccAndCurrResult);

  result = ComputeResult(a, b);

  cout << "Exercise 1\n";
  cout << "Value of result: " << result << endl;
  cout << "\n";

  cout << "Exercise 2\n";
  ForEach(numbers, M, _PrintElement_L);
  cout << "\n";

  cout << "Exercise 3\n";
  Map(numbers_02, J, _MultiWith_2_L);
  ForEach(numbers_02, J, _PrintElement_L);
  cout << "\n";

  cout << "Exercise 4\n";

  // Lấy ResultingFunction
  auto ComputeResult02 = GetComputeResultWithVectorFn(fns_vec, ComputeAccAndCurrResult);

  result = ComputeResult02(a, b);

  cout << "Value of result: " << result << endl;
  cout << "\n";

  cout << "Original Vectors\n";
  cout << "numbers_vec: "; ForEachWithVector(numbers_vec, _PrintElement_L); cout << endl;
  cout << "numbers_vec_02: "; ForEachWithVector(numbers_vec_02, _PrintElement_L); cout << endl;
  cout << "\n";

  MapWithVector(numbers_vec, _MultiWith_2_L);
  MapWithVector(numbers_vec_02, _AddWith_10_L);

  cout << "Modified Vectors\n";
  cout << "numbers_vec: "; ForEachWithVector(numbers_vec, _PrintElement_L); cout << endl;
  cout << "numbers_vec_02: "; ForEachWithVector(numbers_vec_02, _PrintElement_L); cout << endl;

  cout << "\n";

  return 0;
};

