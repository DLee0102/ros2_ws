#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_interfaces/msg/address_book.hpp"

using std::placeholders::_1;

class AddressBookSubscriber : public rclcpp::Node
{
public:
  AddressBookSubscriber()
  : Node("address_book_subscriber")
  {
    address_book_subscriber_ = 
      this->create_subscription<more_interfaces::msg::AddressBook>("address_book", 10, std::bind(&AddressBookSubscriber::topic_callback, this, _1));

  }
private:
  void topic_callback(const more_interfaces::msg::AddressBook & msg)
  {
    RCLCPP_INFO_STREAM(this->get_logger(), "Receive info: \nFirst: " << msg.first_name << "  Last: " << msg.last_name << "  Phone Number: " << msg.phone_number << std::endl);
  }
  rclcpp::Subscription<more_interfaces::msg::AddressBook>::SharedPtr address_book_subscriber_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddressBookSubscriber>());
  rclcpp::shutdown();
  return 0;
}