#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <stdexcept>
#include <sqlite3.h> // подключение библиотеки SQLite для взаимодействия с базой данных

// Класс для работы с базой данных
class Database {
 public:
  Database(const std::string& db_name); // Конструктор: открывает соединение с базой данных
  ~Database(); // Деструктор: закрывает соединение с базой данных
  void execute(const std::string& sql); // Метод для выполнения SQL-команды
  void query(const std::string& sql, int (*callback)(void*, int, char**, char**)); // Метод для выполнения запроса с callback-функцией

 private:
  sqlite3* db_; // Указатель на базу данных SQLite
};

#endif