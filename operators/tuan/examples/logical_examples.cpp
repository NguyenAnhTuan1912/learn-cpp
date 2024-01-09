/*
  @author Nguyen Anh Tuan
  Trong bài này mình sẽ lấy các ví dụ về các toán tử logic.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>

using namespace std;

int main() {
  /*
    Trong bài này thì mình sẽ lấy ví dụ bằng bài toán kinh điển trong môn
    Nhập môn lập trình hay cơ sở lập trình hay lập trình cơ bản.

    Tính số tiền trên mỗi kw điện mà người dùng cần phải trả biết:
    - (Condition 1) Số tiền được tính trên mỗi kw điện từ 0-1 là 5000 đồng.
    - (Condition 2) Số tiền được tính trên mỗi kw điện từ 1-5 là 10000 đồng.
    - (Condition 3) Số tiền được tính trên mỗi kw điện từ 5-15 là 15000 đồng.
  */
  float kw, total;
  short
    n_cost_lvl_1 = 5000, max_kw_lvl_1 = 1,
    n_cost_lvl_2 = 10000, max_kw_lvl_2 = 5,
    n_cost_lvl_3 = 15000, max_kw_lvl_3 = 15;

  cout << "Nhap so kw dien da dung: "; cin >> kw; cout << endl;

  // Tính tiền điện.
  // Sử dụng toán tử && (AND)
  // (Condition 1)
  if(kw > 0 && kw <= max_kw_lvl_1) {
    total += kw * n_cost_lvl_1;
  };

  // (Condition 2)
  if(kw > max_kw_lvl_1 && kw <= max_kw_lvl_2) {
    total += kw * n_cost_lvl_2;
  };

  // (Condition 3)
  if(kw > max_kw_lvl_3) {
    total +=
      (max_kw_lvl_1 * n_cost_lvl_1)
      + (max_kw_lvl_2 * n_cost_lvl_2)
      + ((kw - max_kw_lvl_3) * n_cost_lvl_3);
  };

  cout << "Value of total: " << total << " VND." << endl;

  cout << "\n";

  // Hay thử với một số logic khác.
  /*
    1. Nếu như ngoài trời mưa, thì không thể đi chơi.
    2. Néu như ngoài trời mưa hay không nắng thì không thể đi chơi.
    3. Nếu như là ban ngày và ngoài trời không mưa hay trời nắng thì có thể đi chơi.
  */
  bool is_day, is_rain, is_sunny;

  cout << "Bay gio co phai la ban ngay? "; cin >> is_day; cout << "\n";
  cout << "Hom nay co mua khong? "; cin >> is_rain; cout << "\n";
  cout << "Hom nay co nang khong? "; cin >> is_sunny; cout << "\n";

  // 1. condition
  if(is_rain) {
    cout << "Khong the ra ngoai choi.\n";
  } else {
    cout << "Co the ra ngoai choi.\n";
  };

  // 2. condition
  if(is_rain || !is_sunny) {
    cout << "Khong the ra ngoai choi.\n";
  } else {
    cout << "Co the ra ngoai choi.\n";
  };

  // 3. condition. (Đảo điều kiện).
  if(!is_day || is_rain || !is_sunny) {
    cout << "Khong the ra ngoai choi.\n";
  } else {
    cout << "Co the ra ngoai choi.\n";
  };

  return 0;
};
