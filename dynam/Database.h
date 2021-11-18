#include <iostream>
#include "Worker.h"
#include <vector>

namespace Records {

const int kMaxEmployees = 10;

class Database {
 public:
  Database();
  ~Database();
  std::string addWorker(std::string inFirstName, std::string inLastName);
  Worker* getWorker(int inEmployeeNumber);
  Worker* getWorker(std::string inFirstName, std::string inLastName);

  std::string displayAll();
  std::string displayCurrent();

  std::string deleteAll();
  std::string deleteCurrent();

  std::string promoteAll(int sal);
  std::string promoteCurrent(int sal);

  std::string demoteAll(int sal);
  std::string demoteCurrent(int sal);

  int worker_count();
  int get_current();
  bool is_empty();


 protected:
  std::vector<Worker *> my_workers;
  int cur_worker;
};
}
