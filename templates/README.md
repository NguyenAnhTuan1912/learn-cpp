# Templates
Khi có quá nhiều thứ nhưng muốn làm bằng một tác vụ, thì tác vụ đó sẽ là tác vụ chung chung :))

## About
Khi một hàm mà nhiệm cụ của nó quá tổng quát, thì khi đó mình sẽ nhớ tới ngay `template`, ở một số ngôn ngữ khác như Java, C# hay Typescript thì nó được gọi là generic. Khái niệm template rất quan trọng, nó giúp cho code gọi hơn, clean hơn và dễ maintain hơn.

## Outlines
- Introduce about Template in C++
- Type Parameters (Type of Template Parameters)
- Non-Type Parameters
- Default Template Arugments
- Function Templates
- Class Templates
  - Template nesting & friend member function template
- Partial Ordering of Function/ Class Templates
- Template Specialization


## Objectives
- Hiểu được về datatype overload (không biết gọi có đúng không).
- Hiểu được về generic.
- Hiểu được cách viết code tổng quát cho nhiều kiểu dữ liệu.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/1Usr8pRT7VOaDk65nF6_BiLlOK41pS_oWiwGPnUb0bac/edit?usp=sharing)

Việc sử dụng template sẽ giúp cho mình tối ưu được thời gian phát triển và tiết kiệm được nhiều dung lượng của source code hơn, nhung đồng thời việc sử dụng nhiều template sẽ làm cho thời gian biên dịch chương trình lâu hơn (máy khỏe thì không phải lo). Qua bài này thì mình cũng nắm được một phần về __Generic Programming__ cũng như là thêm một hướng suy nghĩ “trừu tượng” trong việc phát triển ứng dụng, phần mềm.

Cú pháp:
```cpp
template<typename T, …> MyFunc(T t);
```
Template có arguments và nó được gọi là __Type arguments__. Các arguments này được đặt trong cặp dấu <> và có thể truyền thông qua cặp dấu đó khi gọi template.

Trong C++ sẽ có 2 loại templates:
- __Function Template__: với kiểu template này thì khó hơn và trình biên dịch nó đọc sẽ khác hơn so với loại còn lại, vì template type arguments sẽ áp dụng cho function arguments. Trình biên dịch sẽ dựa vào các lần gọi của function và dựa vào đó để xử lý các template đó, đồng thời nó cũng sẽ dựa vào đối số của các template đó.
- __Class Template__: với kiểu template này thì dễ dàng hơn, khi mà template type arguments nó chỉ áp dụng cho các members trong class. Nên trình biên dịch sẽ xử lý dễ dàng hơn, nhưng đồng thời cũng sẽ gây ra một số lỗi không mong muốn.

Ngoài việc truyền type thì mình còn có thể truyền value vào trong __Type Parameters__. Nhưng không nên truyền theo kiểu này. Chỉ nên dùng trong các trường hợp đặc thù và thật sự cần thiết khi dùng tới, về phần này thì mình có nói ở trong phần Non-type parameters. Giống với function argument thì type argument cũng có default value, gọi là __default type__.

Các template cũng sẽ phân biệt từng loại đối số giống với __Function Overloading__, nhưng sẽ có một chút khác biệt. Dạng `MyFunc(T t)` gọi là trường hợp tổng quát nhất, nghĩa là ít cụ thể nhất trong điều kiện bình thường. Và nếu như xuất hiện dạng này thì có thể sẽ không khai báo được các dạng sau: `MyFunc(T& t)`, `MyFunc(const T& t)`, `MyFunc(T&& t)`; vì cơ bản thì khi gọi template, trình biên dịch nó không phân biệt được tham trị vào tham chiếu. Nó chỉ phân biệt được khi hàm đó được gọi, nhưng không phân biệt được thì làm sao có thể gọi được? Nếu như các dạng trên cùng tồn tại với dạng tổng quát nhất thì mình sẽ gặp lỗi __Ambiguous Call__.

Vậy còn `MyFunction(T* t)`, `MyFunction(const T\*)` thì sao? Đến đây thì mình có thêm khái niệm là __Partial Ordering__ và __Specialized Template__ (cái này thì đã có ở trên). Với __Partial Ordering__ thì nó phải dựa vào __Specialized Template__ để chọn ra template nào sẽ được thực thi. `MyFunction(T* t)`, `MyFunction(const T\*)` nó khác biệt với `MyFunc(T t)` vì 2 thằng này cụ thể hơn, cho nên sẽ không gây ra lỗi __Ambiguous Call__. Và nếu như truyền vào template các kiểu dữ liệu “lạ hơn” thì nó sẽ gọi `MyFunc(T t)`, bởi vì lúc này không có template nào có thể handle được nên `MyFunc(T t)` sẽ là thằng cụ thể nhất, đó là sơ lược về cách __Partial Ordering__ hoạt động.

Ngoài việc template hóa một class thì mình còn có thể template hóa một function members của class đó. Ở đây thì có một số điều phải lưu ý:
- Khi trong class template có template member function, thì lưu ý tới việc định nghĩa bên ngoài class template đó với scope resolution operator. Vì lúc này thì mình cần phải khai báo 2 template, một là cho class và một là cho function member đó.
- Template Nesting, nghĩa là  trong một class template sẽ có một hoặc nhiều các class template khác. Có thể sẽ có sâu hơn là một cấp, nên khi định nghĩa các function member ngoài template class đó (không quan tâm tới function member đó là template hay không) thì cũng chú ý tới số các template khi đang khai báo.
- Nếu trong lớp đối tượng có một hoặc nhiều __friend function member__ thì chỉ nên khai báo chứ không định nghĩa FFM bên trong class. Vì template sẽ được trình biên dịch tạo thành nhiều lớp thật, mà FFM lại không chỉ thuộc về lớp đó, nên khi đó nó sẽ bị lỗi Redefinition.

Cuối cùng là __Template Specialization__, ở trên thì mình chỉ nói về “đánh giá” còn trong phần này thì mình sẽ làm cho template “cụ thể” hơn. Cú pháp của nó sẽ như thế này:

```cpp
// Original
template<typename T>
class AnyClass {};
template<typename K, typename V>
class Dictionary {};

// Specialization Edition
template<>
class AnyClass<int> {};
template<typename K>
class Dictionary<int, K> {};
```

Với Specialization Edition thì Type Argument sẽ ít hơn Original Edition 1 hoặc nhiều Argument, và khi ít hơn bao nhiều thì mình sẽ truyền vào Type Parameter bấy nhiêu type/ value. Còn khi nào cần cụ thể các template thì đọc thêm trong phần Template Specialization.