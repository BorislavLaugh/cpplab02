#include <algorithm>
#include <memory>
#include "Database.h"

using namespace Records;

std::string command_list =
    "\n1 Додати працiвника"
    "\n2 Дiстати працiвника за номером"
    "\n3 Дiстати працiвника ПIБ"
    "\n4 Показати усiх"
    "\n5 Показати поточного"
    "\n6 Видалити усiх"
    "\n7 Видалити поточного"
    "\n8 Пiдвищити усiх"
    "\n9 Пiдвищити поточного"
    "\n10 Понизити усiх"
    "\n11 Понизити поточного"
    "\n12 Вивести номер поточного"
    "\n13 К-ть працiвникiв"
    "\n\nВведiть команду:";

std::string get_command(std::string com) {
  std::string command;
  std::cout << com;
  std::cin >> command;

  return command;
}

void addWorker(Database& db) {
  std::string first_name = get_command("Введiть Iм`я: ");
  std::string last_name = get_command("Введiть Прiзвище: ");
  std::cout << db.addWorker(first_name, last_name) << std::endl;
}

void getWorker_with_name(Database& db) {
  std::string first_name = get_command("Введiть Iм`я: ");
  std::string last_name = get_command("Введiть Прiзвище: ");

  try {
    auto worker = db.getWorker(first_name, last_name);

    std::cout << "Працiвника з iменем " << worker->get_first_name() << " "
              << worker->get_last_name() << " дiстали з бази";
  } catch (std::out_of_range& e) {
    std::cerr << "Працiвник вiдсутнiй в бд" << std::endl;
  }
}

void getWorker_with_code(Database& db) {
  auto num = get_command("Введiть номер: ");
  if (!std::all_of(num.begin(), num.end(), ::isdigit)) {
    std::cerr << "Команда повинна бути числом" << std::endl;
    return;
  }

  try {
    auto worker = db.getWorker(stoi(num));
    std::cout << "Працiвника з iменем " << worker->get_first_name() << " "
              << worker->get_last_name() << " дiстали з бази";
  } catch (std::out_of_range& e) {
    std::cerr << "Працiвник вiдсутнiй в бд" << std::endl;
  }
}

int start_commandline() {
  std::cout << "Створю worker1 на купi та worker2 на стеку" << std::endl;

  Database db;

  while (true) {
    auto command = get_command(command_list);

    if (std::all_of(command.begin(), command.end(), ::isdigit)) {
      switch (stoi(command)) {
        case 1: {
          addWorker(db);
        } break;
        case 2: {
          getWorker_with_code(db);
        } break;
        case 3: {
          getWorker_with_name(db);
        } break;
        case 4: {
          std::cout << db.displayAll() << std::endl;
        } break;
        case 5: {
          std::cout << db.displayCurrent() << std::endl;
        } break;
        case 6: {
          std::cout << db.deleteAll() << std::endl;
        } break;
        case 7: {
          std::cout << db.deleteCurrent() << std::endl;
        } break;
        case 8: {
          std::cout << db.promoteAll(1000) << std::endl;
        } break;
        case 9: {
          std::cout << db.promoteCurrent(1000) << std::endl;
        } break;
        case 10: {
          std::cout << db.demoteAll(1000)<< std::endl;
        } break;
        case 11: {
          std::cout << db.demoteCurrent(1000)<< std::endl;
        };
        case 12: {
          std::cout << "Номер поточного:" << db.get_current() << std::endl;
        } break;
        case 13: {
          std::cout << "К-ть працiвникiв:" << db.worker_count() << std::endl;
        } break;
        default:
          std::cerr << "Неiснуюча команда" << std::endl;
          break;
      }
    } else
      std::cerr << "Команда повинна бути числом" << std::endl;
  }

  return 0;
}
