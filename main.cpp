#include "Database.h"
#include "Student.h"
#include <iostream>
#include <limits>

// Callback-функция для отображения результатов запроса
int display_callback(void* NotUsed, int argc, char** argv, char** col_name) {
  for (int i = 0; i < argc; i++) {
    std::cout << col_name[i] << ": " << (argv[i] ? argv[i] : "NULL") << std::endl;
  }
  std::cout << "---------------------" << std::endl;
  return 0;
}

// Функция для отображения меню
void displayMenu() {
  std::cout << "\nMenu:\n";
  std::cout << "1. Add Student\n";
  std::cout << "2. Add Course\n";
  std::cout << "3. Enroll Student in Course\n";
  std::cout << "4. Display Students\n";
  std::cout << "5. Display Courses\n";
  std::cout << "6. Display Enrollments\n";
  std::cout << "7. Update Student Major\n";
  std::cout << "8. Exit\n";
  std::cout << "Enter your choice: ";
}

int main() {
  try {
    // Создаем или подключаемся к базе данных
    Database db("university.db");

    // Создаем таблицы в базе данных, если они не существуют
    db.execute("CREATE TABLE IF NOT EXISTS Students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
        age INTEGER NOT NULL,
        major TEXT NOT NULL);");

    db.execute("CREATE TABLE IF NOT EXISTS Courses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL);");

    db.execute("CREATE TABLE IF NOT EXISTS Enrollments (
    student_id INTEGER,
    course_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES Students(id),
    FOREIGN KEY(course_id) REFERENCES Courses(id));");

    bool running = true;
    while (running) {
      displayMenu(); // Отображение меню
      int choice;
      std::cin >> choice;

      // Проверка на корректный ввод
      if (std::cin.fail()) {
        std::cin.clear(); // Очистка состояния потока ввода
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорирование оставшегося ввода
        std::cout << "Invalid input. Please enter a number.\n";
        continue;
      }

      switch (choice) {
        case 1: { // Добавление студента
          std::string name;
          int age;
          std::string major;
          std::cout << "Enter student name: ";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << "Enter student age: ";
          std::cin >> age;
          std::cout << "Enter student major: ";
          std::cin.ignore();
          std::getline(std::cin, major);
          db.execute("INSERT INTO Students (name, age, major) VALUES ('" + name + "', " + std::to_string(age) + ", '" + major + "');");
          std::cout << "Student added successfully.\n";
          break;
        }
        case 2: { // Добавление курса
          std::string course_name;
          std::cout << "Enter course name: ";
          std::cin.ignore();
          std::getline(std::cin, course_name);
          db.execute("INSERT INTO Courses (name) VALUES ('" + course_name + "');");
          std::cout << "Course added successfully.\n";
          break;
        }
        case 3: { // Запись студента на курс
          int student_id, course_id;
          std::cout << "Enter student ID: ";
          std::cin >> student_id;
          std::cout << "Enter course ID: ";
          std::cin >> course_id;
          db.execute("INSERT INTO Enrollments (student_id, course_id) VALUES (" + std::to_string(student_id) + ", " + std::to_string(course_id) + ");");
          std::cout << "Student enrolled in course successfully.\n";
          break;
        }
        case 4: { // Отображение всех студентов
          std::cout << "Students in the database:" << std::endl;
          db.query("SELECT * FROM Students;", display_callback);
          break;
        }
        case 5: { // Отображение всех курсов
          std::cout << "Courses in the database:" << std::endl;
          db.query("SELECT * FROM Courses;", display_callback);
          break;
        }
        case 6: { // Отображение всех записей на курсы
          std::cout << "Enrollments in the database:" << std::endl;
          db.query("SELECT Students.name, Courses.name FROM Enrollments
          JOIN Students ON Enrollments.student_id = Students.id
          JOIN Courses ON Enrollments.course_id = Courses.id;", display_callback);
          break;
        }
        case 7: { // Обновление специальности студента
          int student_id;
          std::string new_major;
          std::cout << "Enter student ID to update major: ";
          std::cin >> student_id;
          std::cout << "Enter new major: ";
          std::cin.ignore();
          std::getline(std::cin, new_major);
          db.execute("UPDATE Students SET major = '" + new_major + "' WHERE id = " + std::to_string(student_id) + ";");
          std::cout << "Student major updated successfully.\n";
          break;
        }
        case 8: { // Выход из программы
          running = false;
          break;
        }
        default: { // Некорректный выбор
          std::cout << "Invalid choice. Please try again.\n";
        }
      }
    }
  } catch (const std::exception& e) { // Обработка исключений
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
