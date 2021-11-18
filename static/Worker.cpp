#include "Worker.h"

namespace Records {

Worker::Worker() : adress(""), pasport(""), first_name(""), last_name(""), salary(1000) {}

void Worker::hire() { hired = true; }

void Worker::fire() { hired = false; }

std::string Worker::display() {
  std::string res =  "ПIБ:" + first_name + " " + last_name
            + "\nКод працiвника: " + std::to_string(worker_code)
            + "\nКод посади: " + std::to_string(post_code)
            + "\nВiк: " + std::to_string(age)
            + "\nСтать: " + sex
            + "\nАдреса: " + adress
            + "\nПаспорт: " + pasport
            + "\nЗарплатня: " + std::to_string(salary) + "\n\n";

  return res;
}

void Worker::promote(int amount) {salary += amount;}
void Worker::demote(int amount) {salary -= amount;}

// Accessors and setters
int Worker::get_worker_code() {return worker_code;};
int Worker::get_age(){return age;};
int Worker::get_post_code() {return post_code;};
int Worker::get_salary() {return salary;};

void Worker::set_worker_code(int _code) {worker_code =_code;}
void Worker::set_age(int _age){age = _age;}
void Worker::set_post_code(int _post_code) {post_code = _post_code;}
void Worker::set_salary(int _salary) {salary = _salary;}

std::string Worker::get_sex() {return sex;};
bool Worker::get_hired() {return hired;};

void Worker::set_sex(std::string _sex) {sex = _sex;};
void Worker::set_hired(int _hired) {hired = _hired;}

std::string Worker::get_adress() {return adress;};
std::string Worker::get_pasport() {return pasport;};
std::string Worker::get_first_name() {return first_name;};
std::string Worker::get_last_name() {return last_name;};

void Worker::set_adress(std::string _adress) {adress =_adress;}
void Worker::set_pasport(std::string _pasport) {pasport = _pasport;}
void Worker::set_first_name(std::string _first_name) {first_name = _first_name;}
void Worker::set_last_name(std::string _last_name) {last_name = _last_name;}
}
