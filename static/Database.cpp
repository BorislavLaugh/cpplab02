#include "Database.h"
#include <algorithm>

namespace Records {

Database::Database() : cur_worker(0) {}

Database::~Database() { deleteAll(); }

int Database::worker_count() { return my_workers.size(); }

int Database::get_current() { return getWorker(cur_worker)->get_worker_code(); }

bool Database::is_empty() {
  if (worker_count() == 0) {
    std::cout << "Працiвникiв немаэ" << std::endl;
    return true;
  }
  return false;
}

std::string Database::addWorker(std::string inFirstName, std::string inLastName) {
  auto current = new Worker();

  current->set_first_name(inFirstName);
  current->set_last_name(inLastName);
  current->set_worker_code(worker_count() + 1);
  cur_worker = current->get_worker_code();
  my_workers.push_back(current);
  return  "Працiвник створенний: " + inFirstName + " " + inLastName + "\n";
}

Worker* Database::getWorker(int inEmployeeNumber) {
  auto res = my_workers.at(inEmployeeNumber - 1);
  cur_worker = inEmployeeNumber;
  return res;
}

Worker* Database::getWorker(std::string inFirstName, std::string inLastName) {
  for (auto worker : my_workers) {
    if (worker->get_first_name() == inFirstName &&
        worker->get_last_name() == inLastName) {
      cur_worker = worker->get_worker_code();
      return worker;
    }
  }
  throw std::out_of_range("");
}

std::string Database::displayAll() {
  std::string res;

  if (is_empty()) {
    return "БД порожня";
  }

  for (auto iter : my_workers) {
    res += "Даннi працiвника " + std::to_string(iter->get_worker_code()) + ": \n"
           "ПIБ: " + iter->get_first_name() + " " + iter->get_last_name() +
           "\nЗарплатня: " + std::to_string(iter->get_salary()) + "\n\n";
  }
  return res;
}

std::string Database::displayCurrent() {
  std::string res;

  if (is_empty()) {
    return "БД порожня";
  }

  auto iter = getWorker(cur_worker);
  res += "Даннi працiвника " + std::to_string(iter->get_worker_code()) + ": \n"
         "ПIБ: " + iter->get_first_name() + " " + iter->get_last_name() +
         "\nЗарплатня: " + std::to_string(iter->get_salary()) + "\n";
  return res;
}

std::string Database::deleteAll() {
  if (is_empty()) {
    return "БД порожня";
  }

  for (auto worker : my_workers) {
    delete worker;
  }
  my_workers.clear();
  cur_worker = 0;
  return "Всiх працiвникiв видалено";
}

std::string Database::deleteCurrent() {
  if (is_empty()) {
    return "БД порожня";
  }
  auto iter = std::find_if(my_workers.begin(), my_workers.end(),
                           [this](Worker* worker) {
                             return worker->get_worker_code() == cur_worker;
                           });
  delete *iter;
  my_workers.erase(iter);
  cur_worker = my_workers.size();
  return "Поточного працiвника видалено";
}

std::string Database::promoteAll(int sal) {
  if (is_empty()) {
    return "БД порожня";
  }

  for (auto worker : my_workers) {
    worker->promote(sal);
  }
  return "Всiх працiвникiв пiдвищено на " + std::to_string(sal);
}

std::string Database::promoteCurrent(int sal) {
  if (is_empty()) {
    return "БД порожня";
  }

  auto iter = getWorker(cur_worker);
  iter->promote(sal);
  return "Поточного працiвника пiдвищено на " + std::to_string(sal);
}

std::string Database::demoteAll(int sal) {
   std::string res;

  if (is_empty()) {
    return "БД порожня";
  }

  for (auto worker : my_workers) {
    if (worker->get_salary() > 1000) {
        worker->demote(sal);
        res += "Працiвника " + std::to_string(worker->get_worker_code()) + " понизили на " + std::to_string(sal) + "\n";

    }
    else
      res += "Працiвник " + std::to_string(worker->get_worker_code())
                + " вже на мiнiмальнiй ставцi\n";
  }
  return res;
}

std::string Database::demoteCurrent(int sal) {
    std::string res;
  if (is_empty()) {
    return "БД порожня";
  }

  auto iter = getWorker(cur_worker);
  if (iter->get_salary() > 1000) {
      iter->demote(sal);
      res += "Працiвника " + std::to_string(iter->get_worker_code()) + " понизили на " + std::to_string(sal) + "\n";
  }
  else
      res += "Працiвник " + std::to_string(iter->get_worker_code())
                + " вже на мiнiмальнiй ставцi\n";

  return res;
}
}
