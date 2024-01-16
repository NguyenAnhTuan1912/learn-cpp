/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy bài tập ví dụ về higher-order function với lambda.

  Đề bài:
  1. Đầu tiên là một function A sẽ nhận vào các hàm tính toán, hàm đó sẽ trả về một lambda
  và lambda này sẽ nhận vào hai tham số dùng để tính dựa trên các hàm được truyền vào function A trước đó.
  Ngoài ra trong function A sẽ nhận vào một lambda để tính kết quả giữa result hiện tại với kết quả tính
  của mỗi hàm tính toán trong mỗi lần lặp.

*/

#include <iostream>
// Để sử dụng được class function thì mình phải include lib này
#include <functional>

// Khai báo một số type.
/*
  Cái này có liên quan tới template, nhưng giải thích sơ qua.
  Hàm này sẽ trả về một function, function đó nhận 2 tham số
  có kiểu dữ liệu là float và có kiểu dữ liệu trả về cũng là float.
*/
typedef std::function<float(float, float)> CalculatorFunction;
typedef CalculatorFunction ComputeResultFunction;
typedef CalculatorFunction ComputeResultFunctionCallBack;

// Khai báo một namespace chứa các lambdas.
namespace Lambdas {



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

ComputeResultFunction GetComputeResultFn
(
  CalculatorFunction fns[],
  int N,
  ComputeResultFunctionCallBack Cb
) {
  // Trả về một lambda.
  return [fns, N, Cb](float a, float b) {
    float result = 0;

    for(int i = 0; i < N; i ++) {
      result = Cb(result, fns[i](a, b));
    };

    return result;
  };
};

};

using namespace std;
using namespace Lambdas;
using namespace Functions;

int main() {
  // Khai báo 2 số
  float a = 10, b = 4, result = 0;
  int N = 2;
  // Khai báo một mảng Calculator Function.
  CalculatorFunction fns[N] = { Add, Add };

  // Khai báo một lambda để tính kết quả của tích lũy và kết quả của calculator
  auto ComputeAccAndCurrResult = [](float acc, float curr) { return acc + curr; };
  // Lấy ResultingFunction
  auto ComputeResult = GetComputeResultFn(fns, N, ComputeAccAndCurrResult);

  result = ComputeResult(a, b);

  cout << "Value of result: " << result << endl;

  return 0;
};

