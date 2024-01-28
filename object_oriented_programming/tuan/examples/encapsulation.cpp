/*
  @author Nguyen Anh Tuan
  Trong này mình sẽ lấy ví dụ về encapsulation.

  Ấn build để nó hiện ra từng message của lỗi.
  Để thực thi và xem các ví dụ thì comment những chỗ code lỗi lại.
*/

#include <iostream>
#include <vector>

using namespace std;

namespace TicketTypesEnum {

enum _TicketTypesEnum_ {
  Normal = 'N',
  Vip = 'V',
  Premium = 'P'
};

};

// Các struct
struct TicketType {
  TicketTypesEnum::_TicketTypesEnum_ type;
  short price;
};

// Lớp Audience
// Áp dụng tính đóng gói
class Audience {
private:
  string _id_;
  string _name_;
  short _budget_;
  bool _is_checkin_ = false;
  TicketTypesEnum::_TicketTypesEnum_ _ticket_type_;

public:
  Audience() = default;
  Audience(
    string i, string n, short b,
    TicketTypesEnum::_TicketTypesEnum_ tt
  ): _id_{i}, _name_{n}, _budget_{b}, _ticket_type_{tt} {};

  // Methods
  string GetId() { return _id_; };
  string GetName() { return _name_; };
  short GetBudget() { return _budget_; };
  short GetCheckInStatus() { return _is_checkin_; };
  TicketTypesEnum::_TicketTypesEnum_ GetTicketType() { return _ticket_type_; };

  void SetId(string id) { _id_ = id; };
  void SetName(string name) { _name_ = name; };
  void SetBudget(short budget) { _budget_ = budget; };
  void SetCheckInStatus(bool is_checkin) { _is_checkin_ = is_checkin; };
  void SetTicketType(TicketTypesEnum::_TicketTypesEnum_ ticket_type) { _ticket_type_ = ticket_type; };

  void Print() {
    cout
      << "Id: [" << _id_ << "], "
      << "Name: [" << _name_ << "], "
      << "Budget: [" << _budget_ << "], "
      << "Buy ticket yet? [" << ((_is_checkin_ == true) ? "Yes" : "No") << "], "
      << "Ticket: [" << char(_ticket_type_) << "]\n";
  };
};

// Một số hàm
void PrintListOfAudiences(const std::vector<Audience>& audiences) {
  for(Audience aud: audiences) aud.Print();
}

// Lớp MusicFestival
// Áp dụng tính đóng gói
class MusicFestival {
private:
  // Các thuộc tính sẽ ở trong này.
  std::vector<TicketType> _tickets_{
    {TicketTypesEnum::Normal, 100},
    {TicketTypesEnum::Vip, 500},
    {TicketTypesEnum::Premium, 1200}
  };
  std::vector<Audience> _audiences_;
  bool _is_start_ = false;
  bool _is_end_ = false;

public:
  MusicFestival() = default;

  // Method
  void PrintTicketPrices() {
    cout << "Ticket Prices: \n";
    for(TicketType ticket_type_info: _tickets_) {
      switch(ticket_type_info.type) {
        case TicketTypesEnum::Normal: { cout << "Normal: " << ticket_type_info.price << endl; break; };
        case TicketTypesEnum::Vip: { cout << "Vip: " << ticket_type_info.price << endl; break; };
        case TicketTypesEnum::Premium: { cout << "Premium: " << ticket_type_info.price << endl; break; };
      };
    };
  };

  // (*)
  void BuyTicket(Audience& aud, TicketTypesEnum::_TicketTypesEnum_ ticket_type) {
    cout << aud.GetName() << " is buying...\n";
    if(_is_start_ || _is_end_) {
      cout << "Cannot buy ticket right now!!!\n";
      return;
    };

    short price = [&]() {
      for(int i = 0; i < _tickets_.size(); i ++) {
        if(ticket_type == _tickets_[i].type) return _tickets_[i].price;
      };
      return (short)0;
    } ();

    if(price > aud.GetBudget()) {
      cout << "This audience is not sufficient to buy this ticket.\n";
      return;
    };

    aud.SetCheckInStatus(true);
    aud.SetBudget(aud.GetBudget() - price);

    _audiences_.push_back(aud);

    cout << "Check-out done!!!\n";
  };

  void PrintListOfAudiences() {
    ::PrintListOfAudiences(_audiences_);
  };

  void StartEvent() {
    this->_is_start_ = true;
    this->_is_end_ = false;
  };

  void EndEvent() {
    this->_is_start_ = false;
    this->_is_end_ = true;
  };
};

// Một số hàm
void PerformBuyTicket(MusicFestival& fes, std::vector<Audience>& audiences) {
  for(Audience& aud: audiences) {
    if(aud.GetCheckInStatus()) continue;
    fes.BuyTicket(aud, aud.GetTicketType());
    cout << endl;
  };
};

int main() {
  // Khởi tạo các instances
  MusicFestival new_year_fes;

  // In bản giá
  new_year_fes.PrintTicketPrices();

  cout << endl;

  std::vector<Audience> audiences{
    Audience("aud_01", "Nguyen Anh Tuan", 2000, TicketTypesEnum::Premium),
    Audience("aud_02", "Tran Lan Anh", 3000, TicketTypesEnum::Premium),
    Audience("aud_03", "Nguyen Van Long", 200, TicketTypesEnum::Vip),
    Audience("aud_04", "Hoang Van Thu", 1000, TicketTypesEnum::Normal),
    Audience("aud_05", "Le Van", 500, TicketTypesEnum::Vip),
  };

  cout << "List of people that want to join\n";
  PrintListOfAudiences(audiences);
  cout << endl;

  // Tiến hành mua vé
  cout << "Buy ticket\n";
  PerformBuyTicket(new_year_fes, audiences);
  cout << endl;

  // In danh sách thính giả
  cout << "List of official audiences\n";
  new_year_fes.PrintListOfAudiences();
  cout << endl;

  // Thêm một số audience mới
  audiences.push_back(Audience("aud_06", "Le Van Tam", 3000, TicketTypesEnum::Vip));
  audiences.push_back(Audience("aud_07", "Carl Johnson", 5000, TicketTypesEnum::Vip));

  cout << "Re-print list of people that want to join\n";
  PrintListOfAudiences(audiences);
  cout << endl;

  // Dừng sự kiện
  cout << "End \"New year festival\"\n";
  new_year_fes.EndEvent();
  cout << endl;

  PerformBuyTicket(new_year_fes, audiences);
  cout << endl;

  cout << "Re-print list of people that want to join\n";
  PrintListOfAudiences(audiences);
  cout << endl;

  return 0;
};
