# Function
Khi chương trình quá lớn và khó để theo dõi, thì lúc này chương trình đó cần được chia nhỏ.

## About
Hàm là một trong những chủ đề cơ bản trong lập trình, là các chương trình con được cài đặt để thực hiện các tác vụ từ tổng quát nhất tới cụ thể nhất.

## Outlines
- Function
  - Pass by value or reference
  - Default value
  - Argument list
  - Parts of function
- Return Types, Value(s)
  - Return types
  - Return value(s)
- Overloading
- Inline Function
- Lambda Expression
  - Capture clause
  - Higher-order lambda
- Operator Function (Operator Overloading)

## Objectives
- Hiểu được cách định nghĩa hàm.
- Nắm được chỗ nào cần phải tách thành hàm, chỗ nào không.
- Viết được những hàm tổng quát nhất và những hàm cụ thể nhất.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/1ygMhXyB1vk91v6ScR7fawFHIc9EaheaLcN2ce6exGIc/edit?usp=sharing)

Có 3 loại functions (theo quan điểm của mình):
- __Function Object__: là kiểu function cơ bản, thuần túy nhất trong cpp mà được khai báo & định nghĩa với cú pháp cổ điển `type_name function_name(type_name arg) {};` Function Object không thể được khai báo trong Local Scope, nhưng có thể khai báo ở trong namespace, class hoặc struct nhưng khi này thì function object còn được gọi là Member Function. Tùy vào nơi mà nó được khai báo, thì mỗi function sẽ có các khả năng truy cập khác nhau giữa function đối với các object khác và giữa các object khác với function.
- __Overloaded Operator__: mình cho rằng các overloaded operators (thậm chí là các default operators) là function bởi vì mình chỉ có thể ghi đè nó bằng cách tạo ra một function với từ khóa operator, nó cũng nhận tham số và trả về tham số như bao function khác nhưng chính bản thân nó cũng có một số quy tắc khá đặc biệt mà Function Object không có.
- __Lambda__: chắc chắn là function, lambda tiện lợi hơn Function Object khi mà lambda có thể khai báo được ở mọi nơi. Để khai báo được với lambda thì mình sẽ khai báo giống với khai báo biến, ngoài ra thì dùng từ khóa auto hoặc là một UDT nào đó.

Một đối số của function thì có thể truyền bằng 2 kiểu: _Pass by value_ (truyền tham trị) và _Pass by reference_ (truyền tham chiếu). Khi gọi function, thì đối số tương ứng với vị trí của tham số truyền vào sẽ là đại diện của tham số đó ở trong thân hàm. 

- __Pass by value__: khi một đối số được truyền tham trị, thì trình biên dịch sẽ tạo ra một biến mới và copy lại giá trị của tham số vào trong biến mới đó, kể cả có là scalar hay non-scalar.
- __Pass by reference__: khi một đối số được truyền tham chiếu, thì trình biên dịch sẽ không khởi tạo một biến mới, mà lấy đối số làm đại diện cho chính tham số đó trong thân hàm.

Tùy thuộc vào bài toán mà chương trình giải quyết, thì mình phải sử dụng tham trị và tham số sao cho hợp lý, bởi vì quản lý bộ nhớ trong chương trình là rất quan trọng.

Một function sẽ truyền vào trong đó một số lượng các tham số cố định, số lượng tham số này đã được định nghĩa khi đang khai báo hàm. Nhưng mình cũng có thể truyền vào một biến số số lượng các tham số với Ellipsis (...). Và dùng thư viện tiêu chuẩn stdarg.h để có thể đọc được các đối số trong (...). Tham số trong list sẽ không được check kiểu dữ liệu, compiler sẽ bỏ qua nó, cho nên trong quá trình thao tác với các đối số trong list thì mình phải tự động gán cứng kiểu dữ liệu cho từng đối số (để cho dễ thì dùng switch case), và các đối số này được chuyển đối kiểu dữ liệu theo kiểu __Promotion Conversion__. Để lấy được giá trị trong thân hàm thì mình phải có các từ khóa sau:
- __va_list__: tạo ra một con trỏ của list. Mình sẽ dùng con trỏ này cho các function ở sau.
- __va_start__: bắt đầu sử dụng list, mình sẽ truyền con trỏ và giá trị trước đó vào trong này. Nếu không có giá trị trước đó thì nghĩa là nó là giá trị đầu tiên.
- __va_arg__: truyền vào con trỏ và kiểu dữ liệu để lấy ra tham số hợp lý, tham số này chính là tham số hiện tại mà con trỏ va_list đang trỏ tới. Chỉ có thể lấy được tham số sau khi va_start được gọi và trước khi va_end kết thúc. Khi lấy hết đối số trong list thì con trỏ va_list sẽ trỏ về NULL. Đặc biệt là khi lấy giá trị thì phải đúng kiểu dữ liệu.
- __va_end__: truyền vào con trỏ, hàm này sẽ kết thúc việc dùng list và reset con trỏ.

Người ta khuyến khích làm mình không nên dùng Argument List như thế này, bởi vì nó còn nhiều hạn chế. Thay vào đó là nên dùng một số kỹ thuật khác.

Nạp chồng hàm là kỹ thuật mà trong đó một hàm có thể có nhiều định nghĩa. Các hàm nạp chồng được phân biệt bởi đối số và kiểu dữ liệu của đối số. Khi nạp chồng hàm, thì trình biên dịch sẽ tạo ra một bộ các Candidate Functions dựa theo các đối số và kiểu dữ liệu của nó. Khi một hàm có overloads được gọi thì trình biên dịch sẽ kiểm tra giữa các bộ Candidate Function và tìm ra function phù hợp nhất, nếu như tìm thấy nhiều hơn một thì sẽ báo lỗi. Nhưng trước khi đi tìm ra function phù hợp nhất thì compiler phải chuyển kiểu dữ liệu của tham số cho giống với đối số đã được khai báo, với tính chất này thì trình biên dịch sẽ không phân biệt được giữa tham trị, tham trị hằng (const) và tham trị thay đổi bất ngờ (volatile), nhưng sẽ phân biệt được giữa tham chiếu, tham chiếu hằng và tham chiếu thay đổi bất ngờ.

Lưu ý khi gọi một hàm mà có overload, thì tốt nhất hãy chuyển kiểu dữ liệu của tham số mà các overloads có hỗ trợ để tránh gây ra lỗi. Trong quá trình convert thì một Temporary Object sẽ được tạo ra để giữ giá trị vừa mới chuyển đối, khi này TO sẽ không có địa chỉ hay identifier, nó là anonymous object nên với các overload nào mà có đối số là tham chiếu, thì sẽ gây ra lỗi. Và chỉ có tham chiếu hằng mới có thể tham chiếu tới Temporary Object đó, bởi vì tham chiếu hằng cũng sẽ được tạo một Temporary Object khác.

Inline Function là kỹ thuật mà trong đó trình biên dịch sẽ đặt phần thân hàm inline vào nơi mà hàm đó được gọi. Kỹ thuật này nhằm để tối ưu việc gọi function, với những function có khả năng gọi nhiều và có thể gây “quá tải” cho chương trình. Tuy nhiên, kỹ thuật này cũng có một điểm trừ là nó sẽ làm cho source nặng hơn sau khi build, bởi vì nó copy phần thân hàm đến những nói mà hàm đó được gọi. Để khai báo được inline function thì mình dùng từ khóa inline trước mỗi function được khai báo và nên nhớ thì từ khóa này chỉ là gợi ý chứ không phải buộc trình biên dịch inline hàm này tại nơi nó được gọi. Không nên dùng inline function trong hàm đệ quy, trong vòng lặp...

Cuối cùng, Lambda Expression, với ai đã quen với Javascript thì Lambda nó giống với Function Expression. Lambda giống như biến, vì hầu hết nó có thể được khai báo ở mọi nơi và tiện lợi khi dùng với các hàm algorithm hoặc asynchronous. Một function muốn gọi một function khác thông qua đối số: khi chưa có lambda thì function đó phải được truyền dưới dạng là một con trỏ và dùng con trỏ đó để gọi function, còn với lambda thì mình có thể truyền thẳng lambda đó vào bên trong function luôn vì nó có tính chất giống với biến. Lambda có thể được truyền vào function với rvalue hoặc là lvalue.

Lambda có tính đóng (closure) chặt chẽ, khi trong phần thân của lambda mà muốn truy cập các biến bên ngoài thì nó phải được khai báo ở trong Capture Clause ([]) với các default-capture là & và = tương ứng với tham chiếu và tham trị và tất cả các biến được capture sẽ là hằng chứ không còn là biến.

Khi muốn capture tất cả các biến ở bên ngoài thân lambda thì mình chỉ cần dùng ([&]) hoặc ([=]). Nếu như trong capture clause có ([&]) hoặc ([=]) thì các biến được capture sau đó sẽ không được phép có dạng lần lượt tương ứng là &identifier hoặc =identifier. Ví dụ bên ngoài có 3 biến là a, b, và c, thì để có thể capture a và b là tham chiếu và c là tham trị thì trong capture clause mình phải khai báo như sau: [&, =c]. Với các biến static thì không cần phải capture.