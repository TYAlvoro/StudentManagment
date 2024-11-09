#include "Database.h"

// Конструктор: открытие базы данных
Database::Database(const std::string& db_name) {
  if (sqlite3_open(db_name.c_str(), &db_) != SQLITE_OK) {
    throw std::runtime_error("Unable to open database"); // Ошибка при открытии базы данных
  }
}

// Деструктор: закрытие базы данных
Database::~Database() {
  sqlite3_close(db_);
}

// Метод для выполнения SQL-команды без возврата результата
void Database::execute(const std::string& sql) {
  char* error_message = nullptr;
  if (sqlite3_exec(db_, sql.c_str(), nullptr, nullptr, &error_message) != SQLITE_OK) {
    std::string error_str = "SQL Error: " + std::string(error_message); // Формирование сообщения об ошибке
    sqlite3_free(error_message); // Освобождение памяти, выделенной для сообщения об ошибке
    throw std::runtime_error(error_str); // Выбрасывание исключения
  }
}

// Метод для выполнения SQL-запроса с использованием callback-функции
void Database::query(const std::string& sql, int (*callback)(void*, int, char**, char**)) {
  char* error_message = nullptr;
  if (sqlite3_exec(db_, sql.c_str(), callback, nullptr, &error_message) != SQLITE_OK) {
    std::string error_str = "SQL Error: " + std::string(error_message); // Формирование сообщения об ошибке
    sqlite3_free(error_message); // Освобождение памяти, выделенной для сообщения об ошибке
    throw std::runtime_error(error_str); // Выбрасывание исключения
  }
}
