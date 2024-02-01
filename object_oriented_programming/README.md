# Object Oriented Programming
Đưa đối tượng bên ngoài cuộc sống vào trong chương trình dưới dạng thuộc tính và phương thức.

## About
Lập trình hướng đối tượng là kiến thức, kĩ năng, code paradigm mà mọi lập trình viên đều nên biết. Khi áp dụng lập trình hướng đối tượng, thì tư duy lập trình phải xoay quanh đối tượng đó.

## Outlines
- Class, Object vs Instance
  - Properties
  - Methods
  - Access qualifiers
  - Static members
- Constructor and Destructor
  - Constructor
  - Copy constructor
  - Move constructor
  - Destructor
- 4 Properties of OOP

## Objectives
- Tư duy mới mẻ trong lập trình.
- Hiểu được lập trình hướng đối thượng.
- Phục vụ cho việc học `Design Paterrns`.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/1gJ3QlhmqeR5ck3RKrLNdxx0DqNt1hwJzfBYhS5TV8k4/edit?usp=sharing)

Lập trình hướng đối tượng thay đổi về cách mà các lập trình viên phát triển phần mềm, ứng dụng; thay đổi tư duy, suy nghĩ về cách tiếp cận và giải quyết vấn đề. Tạo ra nhiều câu trả lời, giải pháp hơn cho các vấn đề thực tế, các vấn đề ngoài cuộc sống hoặc có thể mang tính khoa học hơn.

Khi nhắc tới lập trình hướng đối tượng thì mình phải nhớ ngay đến những việc sau: phân tích đối tượng để xem đối tượng có thuộc tính và phương thức gì; liên hệ các đối tượng có liên quan tới đối tượng đó và bài toán đó; cài đặt code dựa trên những gì đã phân tích.

Một đối tượng sẽ gồm 2 phần chính là thuộc tính và phương thức. Các thuộc tính và phương thức này có thể được khai báo và định nghĩa ở trong một lớp đối tượng. Lớp đối tượng này sẽ được dùng để khởi tạo instance, dùng để thao tác kiểu dữ liệu và một số công năng khác. Lớp đối tượng giống như bản vẽ của một sản phẩm (__instance__), dựa vào đó mà mình tạo ra sản phẩm.

Trong lập trình hướng đối tượng thì có một số phương thức đặc biệt, bao gồm: hàm khởi tạo (__constructor__), hàm hủy (__destructor__). Riêng với C++ thì mình sẽ có thêm các phương thức như là: hàm khởi tạo sao chép (cú pháp: `MyClass(const MyClass& obj)`) và hàm toán tử sao chép (Copy __constructor__ and copy assignment operator); hàm khởi tạo di chuyển (cú pháp: `MyClass(MyClass&& obj)`) và hàm toán tử di chuyển (Move __constructor__ and move assignment). Khi mình không định nghĩa các hàm này thì trình biên dịch sẽ ngầm định định nghĩa nó.

Các thuộc tính và phương thức được gọi chung là member, các member này có thể được truy cập thông qua instance được tạo từ lớp đối tượng, hoặc có thể được quy cập qua con trỏ mà đang trỏ tới instance của lớp đối tượng đó, hoặc cũng có thể dùng toán tử :: để truy cập vào các static member. Các static members là các members tồn tại trong mọi instance, được chia sẻ bởi các instance hay thậm chính là chính lớp đối tượng đó, các members này nên được khởi tạo ngay sau khi định nghĩa xong lớp đối tượng chứa nó và phải được khởi tạo trước bất kì một instance nào được tạo ra.

Khi nói tới truy cập thì OOP cho mình một giải pháp đó là “quyền truy cập” được quy định bởi các __Access Qualifiers__. Có 3 loại chính:
- __private__: là AQ mặc định. Nó chỉ cho phép các member được dùng trong nội bộ. Không thể truy cập từ các instances hoặc các lớp được kế thừa.
- __protected__: nó chỉ cho phép các member được dùng trong nội bộ và các lớp được kế thừa, nhưng không thể truy cập từ các instances.
- __public__: nó cho phép truy cập thoải mái.

Và từ đây mình sẽ sinh ra tính chất đầu tiên của OOP (nói đầu tiên cũng không đúng, vì nói cái nào trước cũng được, nhưng mà tính chất này tiếp xúc ngay từ lần đầu học OOP).
__Encapsulation__ (tính đóng gói): ẩn các thuộc tính của lớp đối tượng và chỉ cho phép truy cập thông qua phương thức, từ đó mình có thể bảo mật trên các phương thức đó. Điểm trừ là khi truy cập thuộc tính thì chương trình phải “tốn công” gọi hàm.

Và để mã nguồn ngắn gọn hơn, logic hơn, thực tế hơn thì OOP còn có thêm một tính chất là __Inheritance__ (tính kế thừa). Lớp được kế thừa sẽ sở hữu “ngầm” các thuộc tính và phương thức (public và protected) của lớp kế thừa, ngoài ra thì lớp được kế thừa còn có thể định nghĩa lại các hàm ảo, nhưng không phải là các hàm ảo final. Khi kế thừa từ một lớp thì lớp được kế thừa nên tránh việc khai báo lại các thuộc tính đã có ở lớp đối tượng, vì điều đó sẽ gây bug (không lỗi). Một lớp đối tượng không thể kế thừa một lớp khác nhiều lần, nhưng cũng có thể có hiện tượng kế thừa lặp, nó xảy ra khi một lớp kế thừa từ 2 lớp khác nhau, nhưng hai lớp kế thừa đó lại được kế thừa lại chung một lớp, lúc này sẽ gây nên lỗi không rõ ràng cho trình biên dịch.

Để khắc phục được vấn đề này, thì C++ hỗ trợ cho mình từ khóa virtual, biến các member thành member ảo (chỉ hoạt động với phương thức). Các phương thức khi được khai báo với từ khóa virtual thì có nghĩa là phương thức đó là ảo, và có thể dùng để tái định nghĩa lại ở trong các lớp được kế thừa. Còn khi kế thừa lớp ảo thì nó sẽ đảm bảo chỉ có một bản sao của lớp kế thừa tồn tại trong “cây kế thừa”, nên khi đó mình đã giải quyết được vấn đề tên.

Từ đây, mình có thêm một tính chất nữa là __Abstraction__ (tính trừu tượng). Tính trừu tượng đẩy OOP lên một tầm cao mới, buộc các lập trình viên phải bỏ qua suy nghĩ “phương thức này hoạt động như thế nào?” thành “phương thức này hành động gì?”. Bởi vì khi trừu tượng hóa một đối tượng, thì sẽ giúp cho chính đối tượng đó có thêm nhiều các đối tượng liên quan. Trong các ngôn ngữ lập trình hướng đối tượng khác, thì một lớp đối tượng sẽ được khai báo rõ ràng với từ khóa abstract đằng trước từ khóa class khi khai báo lớp đối tượng. Nhưng với C++ thì nó không được rõ ràng cho lắm, vì một lớp trừu tượng nó phải có ít nhất một hoặc nhiều Pure Virtual Function (Hàm ảo thuần), hàm ảo thuần là phương thức được khai báo với từ khóa virtual và gán = 0 (Pure Specifier). Hàm ảo thuần buộc các lớp được kế thừa phải định nghĩa nó, còn với hàm ảo thì nó được khai bảo ở lớp kế thừa nên cũng không cần phải định nghĩa ở lớp được kế thừa nữa.

Từ các tính chất trên và một số tính chất khác của lập trình, thì OOP còn có một tính chất nữa: __Polymorphism__ (tính đa hình). Một đối tượng, nó có thể là nhiều thứ khác nhau, cũng tương tự với phương thức. Từ đó mình sẽ có 2 kiểu đa hình, một là compiler time và hai là run time.

Với compile-time thì có __Function Overloading__ và __Operator Overloading__; với run time-thì mình có __Virtual Function__. Riêng FO và OO là hai khái niệm nằm ngoài OOP, và thực chất tính đa hình này cũng nằm ngoài OOP, nhưng vì OOP với Polymorphism đi cùng với nhau rất hợp lý, nên đây cũng được xem là 1 trong 4 tính chất phổ biến của lập trình hướng đối tượng.

Về các tính chất này thì xem thêm ở cuối mỗi ví dụ mà mình đã rút ra được một số nhận định trong quá trình lấy ví dụ đó, để có thể hiểu hơn về OOP trong C++, cũng như là khái niệm chung chung của OOP.