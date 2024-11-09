#include "Student.h"
#include <iostream>

// Конструктор класса Student
Student::Student(int id, const std::string& name, int age, const std::string& major)
    : id_(id), name_(name), age_(age), major_(major) {}

// Получение ID студента
int Student::getId() const {
  return id_;
}

// Получение имени студента
std::string Student::getName() const {
  return name_;
}

// Получение возраста студента
int Student::getAge() const {
  return age_;
}

// Получение специальности студента
std::string Student::getMajor() const {
  return major_;
}

// Метод для записи на курс
void Student::enrollInCourse(const std::string& course) {
  courses_.push_back(course); // Добавление курса в список курсов студента
}

// Метод для отображения курсов, на которые записан студент
void Student::displayCourses() const {
  std::cout << "Courses for " << name_ << ":\n";
  for (const auto& course : courses_) {
    std::cout << " - " << course << "\n";
  }
}
