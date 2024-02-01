# Pointer
Không khó hiểu, nhưng rối rắm bậc nhất.

## About
Con trỏ được dùng khi thao tác sâu vào trong bộ nhớ, thay vì chỉ lấy value của một biến thì giờ mình sẽ lấy vùng nhớ của biến đó để có thể thay đổi value của biến đó trong một tác vụ, chương trình con khác.

## Outlines
- Pointer
  - Raw pointer
  - Pointer with "new" keyword
  - Constant pointer
  - Initialization and member access
  - Pointer and array
  - Pointer and function
  - Smart pointers
- Reference
  - Lvalue reference with & declarator
  - Rvalue reference with && declarator
- This (Pointer) Keyword

## Objectives
- Hiểu được cách thức hoạt động của con trỏ.
- Áp dụng được con trỏ.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/15U1sRoYSODQ_2Q8CbztXeTmqdf2EB9JwSM3M_tYkhKw/edit?usp=sharing)

Con trỏ là một biến dùng để lưu địa chỉ vùng nhớ của một vùng nhớ khác bên trong nó, được định nghĩa theo cú pháp `type_name* ptr_var_name = &var_name;` bởi vì value của con trỏ là vùng nhớ nên mình phải dùng toán tử & để trích xuất địa chỉ vùng nhớ của biến. Tùy vào số lượng `*` trong phần khai báo, thì sẽ cho biết cấp của con trỏ; Để trỏ tới một con trỏ thì mình sẽ cần một con trỏ cấp 2, và để trỏ tới một con trỏ cấp 2 thì mình cần một con trỏ cấp 3, tương tự như thế, để trỏ tới con trỏ cấp __n - 1__ thì mình cần con trỏ cấp __n__.

Khi con trỏ trỏ tới một object nào đó, thì mình sẽ cần phải dùng toán tử -> để truy cập vào các member của object đó. Đó là lý do vì sao khi dùng toán tử this để truy cập vào các member của object thì mình phải dùng tới toán tử đó.

__const__ và __volatile__ qualifier có thể dùng với con trỏ và nó có một số ý nghĩa sau (ở đây chỉ xét __const__, vì nó rõ ràng hơn):
- __T*__: con trỏ, không cần phải nói quá nhiều, mình có thể trỏ sang vùng nhớ khác và sửa dữ liệu của vùng nhớ mà nó trỏ tới.
- __const T*__: là con trỏ hằng, nó sẽ không thể sửa dữ liệu của vùng nhớ mà nó trỏ tới nhưng vẫn có thể trỏ tới vùng nhớ khác.
- __T* const__: là hằng con trỏ, nó có thể sửa được dữ liệu của vùng nhớ mà nó trỏ tới nhưng không thể trỏ tới vùng nhớ khác.
- __const T* const__: là hằng con trỏ hằng, nó không thể trỏ tới vùng nhớ khác và không thể thay đổi dữ liệu của vùng nhớ mà nó trỏ tới.

Có hai kiểu để cấp phát bộ nhớ cho một con trỏ: __Stack Allocation__ và __Heap Allocation__.

- __Stack Allocation__: để cấp phát kiểu này thì mình chỉ cần cấp phát object như bình thường. Khi object được dùng xong (hết một scope, hàm được thực thi xong,...) thì chương trình sẽ tự động xóa nó đi ra khỏi stack để giải phóng bộ nhớ.
- __Heap Allocation__: để cấp phát kiểu này thì mình phải dùng thêm từ khóa new. Khi object được dùng xong, thì nó sẽ không được xóa, mà còn tồn tại ở trong Heap nên khi dùng xong thì mình phải dùng delete để xóa đi object đó.

Chính vì kiểu cấp phát bộ nhớ cho Heap, nên pointer được chia làm 2 loại:
- __Raw pointer__: là các pointer mà được khởi tạo và cấp phát như hai cách trên.
- __Smart pointer__: thì bọn này thực chất là các wrapper, nó bọc raw pointer lại và quản lý các raw pointer đó. Đến khi out of scope thì raw pointer đó sẽ bị xóa.

Có 3 loại smart pointers:
- __unique_ptr__: là pointer mà chỉ cho phép raw pointer có duy nhất một owner là chính pointer này, không thể copy hay chia sẻ raw pointer của unique_ptr cho các smart pointer khác.
- __shared_ptr__: là pointer mà trong đó nó cho phép raw pointer có nhiều owner, ngoài ra thì nó còn có thêm một object nữa để quản lý số đếm các tham chiếu tới raw pointer.
- __weak_ptr__: là pointer dùng để hủy các liên kết vòng giữa các shared_ptr.

Lvalue của Array chính là con trỏ mà nó trỏ đến vị trí đầu tiên của mảng, và Array cũng là một dạng con trỏ đặc biệt, các thành phần của nó sẽ liên tiếp nhau trong RAM. Mình cũng có thể dùng pointer để duyệt một mảng bằng cách tăng hoặc giảm địa chỉ mà con trỏ đang trỏ tới.

Con trỏ tới một function được dùng trong kỹ thuật “Callback”, truyền một hàm này vào hàm khác mà không cần phải copy function đó. Nhưng về sau thì người ta dùng kỹ thuật khác hiệu quả hơn là Lambda (xem thêm trong bài Function).

Khác với con trỏ thì tham chiếu là một biến đặc biệt mà nó cũng lưu trữ địa chỉ vùng nhớ của biến mà nó tham chiếu tới và một tham chiếu không thể thay đổi tham chiếu tới một vùng nhớ khác được, nên khi tạo tham chiếu thì mình phải khởi tạo luôn vùng nhớ mà muốn nó tham chiếu tới. Để khai báo được một tham chiếu thì mình phải dùng cú pháp:

```cpp
type_name& ptr_var_name = var_name;
```

Nên khi gán một tham chiếu với một object khác, thì có nghĩa là mình đang thay đổi value của vùng nhớ mà tham chiếu đó đang tham chiếu tới.
Với function thì sẽ nhận và trả về 2 loại tham chiếu:
- __Lvalue Reference__: là loại tham chiếu mà nó tham chiếu tới một identify cụ thể, có vùng nhớ, có địa chỉ.
- __Rvalue Reference__: là loại tham chiếu tới một Temporary Object, và không thể được tham chiếu bởi các tham chiếu khác trong chương trình (tham chiếu ẩn).

Tùy vào từng tác vụ thì Lvalue hoặc là Rvalue Reference sẽ được sử dụng. Nhưng khi truyền một object lớn vào trong function, thì nên truyền nó dưới dạng tham chiếu, để tránh việc chương trình copy value của nó làm cho hiệu xuất của chương trình giảm đi.