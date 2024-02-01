# Operators
Toán tử, thứ không thể thiếu trong các phương trình toán học, vật lý và cũng như là trong lập trình.

## About
Trong C++, có rất nhiều loại toán tử với các chức năng khác nhau, từ toán tử thao tác số, đến toán tử thao tác bits hay thậm trí là các toán tử được tùy chỉnh lại cho một số kiểu dữ liệu đặc biệt, và nhớ chú ý tới độ ưu tiên của toán tử.

## Outlines
- About Operator in C++
  - Arithmetic Operators
  - Relational Operators
  - Logical Operators
  - Bitwise Operators
  - Assignment Operators
  - Ternary Operators
- Precedence
- Falsy Values
- User-Defined Operators (Operator Overloading)

## Objectives
- Hiểu được các thức hoạt động của toán tử.
- Custom được các toán tử.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/14TcMU4YlKYUO92n8dU9-pMhyGhw6qUvBjxnx6SD0Us4/edit?usp=sharing)

Toán tử trong lập trình là phần cơ bản nhất, nhưng cũng là một trong những phần quan trọng nhất trong lập trình. Nó là nền tảng để phát triển, để tình toán, để thực hiện trong các chương trình phần mềm (khoa học cũng như là thương mại).

Mình có 6 loại toán tử, và kết quả của mỗi toán tử này đều trả về một giá trị tùy theo kiểu dữ liệu của toán hạng thực hiện nó. Ngoài ra toán tử (với hành vi mặc định) chỉ có thể dùng với scalar type, còn nếu muốn dùng với non-scalar type thì mình phải định nghĩa nạp chồng toán tử cho object đó. Điểm chung của các loại toán tử này là dùng với kiểu số nguyên như là __short__, __int__, __long__, __long long__ và với __unsigned__ của mỗi kiểu vừa liệt kê vừa rồi và kiểu __char__.

Các loại toán tử đó là
- __Arithmetic Operators__: toán tử số học, các toán tử này chỉ có thể dùng với kiểu số nguyên và char như đã nói ở trên. Ngoài ra thì mình có thể nạp chồng toán tử loại này cho các non-scalar type.
- __Relational Operators__: toán tử so sánh, giống với toán tử số học thì cũng có thể dùng với kiểu số nguyên và char, đồng thời mình có thể nạp chồng toán tử cho các non-scalar type.
- __Logical Operators__: toán tử logic, nó sẽ tương tác ở level giá trị. Tương tự như toán tử số thì nó sẽ tương tác với kiểu số nguyên và char, đồng thời cũng có thể nạp chồng toán tử loại này với non-scalar type. Ngoài ra, thì dạng toán tử này sẽ tương tác với kiểu boolean, trong các lệnh như là if…else, while, do…while.
- __Bitwise Operators__: toán tử logic bit, nhưng nó sẽ tương tác ở level bit. Tương tự như toán tử số thì nó sẽ tương tác với kiểu số nguyên và char, đồng thời cũng có thể nạp chồng toán tử loại này với non-scalar type. Tùy theo tiêu chuẩn và Number Interpreter thì trên cùng một toán tử sẽ cho ra kết quả khác nhau.
- __Assignment Operators__: toán tử gán, khi biểu thức là 2 loại toán tử số hoặc hoặc logic bit, thì có thể kết hợp thành dạng rút gọn. Toán tử gán cũng có thể được nạp chồng.
- __Ternary Operators__: toán tử ba ngôi, sẽ cho ra 1 trong 2 giá trị của lần lượt 2 biểu thức được tách bởi “:”. Toán tử ba ngôi không thể được nạp chồng.

Chỉ có những toán tử như ., .\*, ::, ?: là không thể được nạp chồng.

Tuy string là một non-scalar type, nhưng mình có thể dùng + để nối 2 chuỗi lại.

Khi nạp chồng một toán tử với hai số hạng (binary operators) thì sẽ có một hàm ẩn được chương trình định nghĩa với tham số truyền vào được đảo lại, và phép tính sẽ được đảo lại ở phần return của hàm ẩn.

Cuối cùng là, trong C++, chỉ có false là falsy value, còn lại những giá trị nào khi chuyển đổi về boolean mà cho ra false, thì cũng có thể xem là falsy value.