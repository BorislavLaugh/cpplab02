#include <iostream>

namespace Records {

const int kDefaultStartingSalary = 30000;

class Worker {

 public:
  Worker();
  void hire();
  void fire();
  std::string display();

  void promote(int amount);
  void demote(int amount);

  // Accessors and setters
  int get_worker_code();
  int get_age();
  int get_post_code();
  int get_salary();

  void set_worker_code(int _code);
  void set_age(int _age);
  void set_post_code(int _post_code);
  void set_salary(int _salary);

  std::string get_sex();
  bool get_hired();

  void set_sex(std::string _sex);
  void set_hired(int _hired);

  std::string get_adress();
  std::string get_pasport();
  std::string get_first_name();
  std::string get_last_name();

  void set_adress(std::string _adress);
  void set_pasport(std::string _pasport);
  void set_first_name(std::string _first_name);
  void set_last_name(std::string _last_name);

 private:
  int worker_code;
  int age;
  std::string sex;
  std::string adress;
  std::string pasport;
  std::string first_name;
  std::string last_name;
  int post_code;
  int salary;
  bool hired;
};
}
