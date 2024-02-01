# Structuring Codebase
Quản lý source code

## About
Cấu trúc mã nguồn, đây là thứ cơ bản các lập trình viên khi làm việc chung phải nắm được. Tuy là cơ bản, nhưng nó rất quan trọng trong dự án, nhất là khi mà dự án càng ngày càng lớn hơn.

## Outlines
- Scope
  - Global scope & local scope
  - Namespace scope
  - Class scope
- Namespace
- Code Splitting: Header/ CPP Files

## Objectives
- Nắm rõ được cách tổ chức thư mục của dự án.
- Nắm rõ được cách cấu trúc của source code.
- Nắm được cách làm việc chung khi lập tình.

## Brief
Các bạn có thể đọc thêm [tại đây](https://docs.google.com/document/d/1FkL1SNrKBHw6udQWVNufz3wbO_zuVeo1-At1yFyQ-9w/edit?usp=sharing)

Để dễ dàng nâng cấp, sửa chữa & cải tiến mã nguồn thì việc quản lý mã nguồn & dự án rất quan trọng, buộc mình phải tuân theo các quy tắc về __scope__, __header__, __linkage__ của các identifier hay quy tắc __ODR__ (xem [tại đây](https://en.wikipedia.org/wiki/One_Definition_Rule)).

Với scope thì mình có 2 loại chính: __Global__ và __Local__
- __Global Scope__: là scope mà nó không nằm trong cặp dấu {} nào cả (thật đấy), ngoài ra thì nó là scope chứa hàm main.
- __Local Scope__: là bất kì scope nào mà nó nằm trong một scope khác, scope có độ sâu nhỏ nhất là scope gần với Global nhất, thường là scope của hàm main, scope của các global function.

Khi có một biến được khai báo ở bên trong một scope, mà ở bên ngoài scope đó lại có một biến khác giống như thế, thì chương trình sẽ ưu tiên biến ở scope bên trong hơn => Chương trình sẽ ưu tiên những biến có cùng cấp, nếu không thì nó sẽ ưu tiên những biến có độ sâu nhỏ và gần nó nhất (cái này mình gọi là chồng biến). Khi chương trình thực thi xong một scope, thì giá trị của các biến (với scalar type) thì sẽ được dọn đi, nhưng với một số scope đặc biệt thì không.

Ngoài ra còn có 2 scope đặc biệt khác như là: __Namespace__ và __Class__
- __Namespace__: là một scope mà nó được đặt name, ngoài ra nó còn có tính chất phân tách - tập hợp (cái này là mình tự gọi), nghĩa là mình có thể phân tách phần định nghĩa của namespace ra và trình biên dịch sẽ tập hợp nó lại về cùng một namespace sau cùng, với điều kiện là các namespace được tách ra này phải có cùng một tên. Mình có thể lồng một namespace bên trong một namespace khác, ngoài ra dùng từ khóa __inline__ với một namespace bên trong để thực hiện kỹ thuật versioning.
- __Class__: bản thân nó cũng là một scope, nhưng các member của nó đặc biệt hơn namespace hay các scope khác. Bản thân nó không chứa các biến, mà nó chỉ chứa phần khai báo của biến đó và các biến đó chỉ được tạo ra với một phương thức đặc biệt. Với class thì nó có thể tạo ra đối tượng.

Các Unnamed/ Anonymous Namespace sẽ “tàn hình” giữa các Translation Unit, còn với các Namespace bình thường thì không. Cho nên các Unnamed/ Anonymous Namespace sẽ thích hợp làm nơi để khai báo các biến, hàm, class, struct, union, enum,... cục bộ của một file mà các file khác không thể truy cập tới.

Và cuối cùng, để tránh bị lỗi trùng tên các biến hoặc lặp lại định nghĩa, thì mình nên dùng tới header file. Với Header file thì mình có thể include nó vào các definition hoặc header file khác cần tới nó. Và nên include header file thay vì là definition file. Cùng với đó là kết hợp với namespace và nắm được linkage của các identifiers trong dự án sẽ giúp tránh tối đa errors, bugs và exceptions không mong muốn.

(Fun fact: các thư viện mà mình include thì thường là sẽ là header file của nó).