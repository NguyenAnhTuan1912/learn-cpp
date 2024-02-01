# Datatype, Memory
Kiểu dữ liệu và bộ nhớ là những thứ cơ bản nhất mà những người học lập trình cần phải biết.

## About
Trong chủ đề này thì tụi mình sẽ tìm hiểu về các kiểu dữ liệu và bộ nhớ trong chương trình C++. Datatype và Memory là hai thứ cơ bản nhất trong một chương trình C++, nó quyết định đến hiệu năng của chương trình, trông có vẻ như hai thứ này không liên quan nhưng thực chất rất liên quan tới nhau.

Các bạn có thể xem ví dụ kĩ hơn trong các folder có _tên_người_tham_gia/exmples_ và cùng với bài tập ở _tên_người_tham_gia/exercises_.

## Outline
- About Type in C++
- Built-in Types, Size and Size Overflow
  - Built-in types and size
  - Size overflow
  - String type
  - Array type
  - User-defined type (UDT)
- Type Conversion
  - Implicit type conversion
  - Explicit type conversion
- Memory
  - Stack
  - Heap
  - Comparison between Stack and Heap
  - Data Segment
- Dynamic Allocation
- Temporary Object, Lvalues and Rvalues

## Objectives
- Hiểu và nhớ được các kiểu dữ liệu.
- Quản lý bộ nhớ tốt hơn.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/1FCU6BYo8DS7KuC80TKv0eb_kFkf6OTOnaKeh9X5XRHM/edit?usp=sharing)

Kiểu dữ liệu (Data type) là phần cơ bản trong ngôn ngữ lập trình, nhưng cũng như là phần quan trọng nhất. Để chương trình được tối ưu hơn thì phải hiểu về kiểu dữ liệu. Trong C++, chia ra làm hai lớp kiểu dữ liệu chính
- __Scalar Type__: là những kiểu dữ liệu mà trong đó nó chỉ chứa một giá trị đơn duy nhất.
- __Non-scalar Type__: là những kiểu dữ liệu mà trong nó nó sẽ chứa theo cấu trúc phức tạp hơn.

“string” là một kiểu dữ liệu đặc biệt, nó không được hỗ trợ chính thức như các kiểu dữ liệu built-in khác, nhưng nó vẫn được hỗ trợ thông qua thư viện tiêu chuẩn của C/C++ (ý tưởng của nó là con trỏ tới một mảng kiểu char).

Mỗi một biến đều có Value Range, là khoảng giá trị mà biến đó có thể chứa được, hay vùng nhớ của biến đó chứa được, gồm 2 đầu nút là Min value và Max value.
Mỗi kiểu dữ liệu sẽ được cấp phát một lượng vùng nhớ trong RAM theo như định nghĩa của nhà phát triển. Đây gọi là cấp phát tĩnh (Static Allocation), nếu như vùng nhớ đó (đại diện là biến) mà lưu giá trị có số bits (biểu diễn ở dạng nhị phân) mà lớn hơn vùng nhớ được cấp phát, thì chương trình sẽ tự động bớt đi số bits bằng cách lấy giá trị đó trừ đi cho Max value, điều này đồng nghĩa với việc là dữ liệu của mình đã bị sai.

Array, là kiểu dữ liệu mà trong đó nó được cấp phát nhiều vùng nhớ, các vùng nhớ này liên tiếp và liên quan tới nhau. Nếu như trong RAM không còn vùng nhớ để có thể chứa đủ Array, thì khi đó Array sẽ ít vùng nhớ hơn trong khai báo.

Ngoài các built-in types ra, thì C++ còn cho phép người lập trình tự định nghĩa các kiểu dữ liệu (User-defined type) với các từ khóa như là __class__, __struct__, __enum__ và __union__.

__struct__ và __union__ giống hệt nhau, nhưng khác biệt ở chỗ là cách dùng bộ nhớ của hai thằng này. Khi mình khai báo __struct__ và khởi tạo object mới, thì chương trình sẽ cấp phát tất cả bộ nhớ mà __struct__ đã định nghĩa, có nghĩa là __struct__ định nghĩa bao nhiêu, thì nó sẽ xài bấy nhiêu. Nhưng với __union__ thì lại khác, cho dù __union__ có định nghĩa N thuộc tính trong đó thì chỉ có duy nhất 1 thuộc tính được dùng, có nghĩa là __union__ định nghĩa bao nhiêu, thì chỉ dùng cho 1. Khi một __union__ object được khởi tạo, thì chương trình chỉ cấp cho nó một vùng nhớ duy nhất, và tất cả các thuộc tính sẽ lưu chung giá trị cho vùng nhớ này. Nên khi một thuộc tính được dùng, thì chương trình sẽ xóa giá trị trong vùng nhớ đó, và gán giá trị mới nếu như thuộc tính đó được gán giá trị, nếu như không có thì vùng nhớ đó được gán tự động.

__enum__ thì đơn giản chỉ là một danh sách hằng số được tăng giá trị tự động. Nghĩa là nó là một danh sách “chỉ đọc” đã được định nghĩa từ trước. Dùng __enum__ để nhất quán dữ liệu cho một thuộc tính nào đó cần giới hạn lại khoảng dữ liệu, loại,...

Và để cho tiện lợi hơn, thì C++ sẽ tự động chuyển đổi kiểu dữ liệu và cung cấp cho mình một số hàm để chuyển đổi kiểu dữ liệu. Việc chuyển đổi kiểu dữ liệu rất quan trọng cho việc tính toán, giống như khi cộng ký tự với số, thì ký tự buộc phải được chuyển về số mới có thể thực hiện được phép cộng.

Giá trị trong C++ được chia thành nhiều loại, với mỗi loại sẽ có các quy tắc để chương trình có thể sử dụng được nó.

- __gvalue__: là biểu thức mà nó xác định identity của biến, hàm.
- __prvalue__: là giá trị được tạo ra từ toán tử hoặc các phép tính khác. Nó không có địa chỉ để tham chiếu tới
- __lvalue__: là biến, phần tử mảng, thành phần lớp,... nó có địa chỉ để tham chiếu tới.
- __xvalue__: là giá trị có địa chỉ, nhưng chương trình không thể truy cập được nữa. Dùng để khởi tạo tham chiếu tới rvalue.
- __rvalue__: có thể là prvalue hoặc xvalue.

Và với Temporary Operator được tạo ra để dùng với một prvalue, kiểu giá trị không thể truy cập tới ngoài trình biên dịch.
Memory sẽ được chia thành 4 nơi:
- __Stack__: là nơi được dùng để lưu trữ các biến cục bộ, các biến được lưu trong này sẽ được xóa đi khi sử dụng xong.
- __Heap__: giống với stack, nhưng khi một object được cấp phát bộ nhớ trong này thì nó phải cần một con trỏ trong stack để trỏ về object đó.
- __Code__: là file văn bản của code, nó chứa dữ liệu động không thể thay đổi trong quá trình thực thi.
- __Data__: là phần để lưu các biến toàn cục, biến tĩnh và biến tĩnh cục bộ cùng với dữ liệu khởi tạo của các biến đó.
- __BSS__: giống với data, nhưng khác ở chỗ là nó sẽ lưu các biến toàn cục, biến tĩnh và biến tĩnh cục bộ không có dữ liệu khởi tạo.