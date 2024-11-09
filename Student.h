#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Класс, представляющий студента
class Student {
 public:
  Student(int id, const std::string& name, int age, const std::string& major); // Конструктор
  int getId() const; // Получение ID студента
  std::string getName() const; // Получение имени студента
  int getAge() const; // Получение возраста студента
  std::string getMajor() const; // Получение специальности студента
  void enrollInCourse(const std::string& course); // Метод для записи на курс
  void displayCourses() const; // Метод для отображения курсов, на которые записан студент

 private:
  int id_; // ID студента
  std::string name_; // Имя студента
  int age_; // Возраст студента
  std::string major_; // Специальность студента
  std::vector<std::string> courses_; // Курсы, на которые записан студент
};

#endif