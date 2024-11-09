# Система управления университетом

### Обзор
**Система управления университетом** — это консольное приложение на C++, которое симулирует управление студентами и курсами в университете. Этот проект включает операции с базой данных SQL с использованием SQLite для хранения и управления данными о студентах и курсах, включая записи на курсы и обновление информации о студентах.

### Функции
- **Добавить студента**: Создание нового профиля студента с именем, возрастом и специальностью.
- **Добавить курс**: Добавление нового курса в базу данных университета.
- **Записать студента на курс**: Запись студента на определенный курс.
- **Отобразить студентов**: Показать всех студентов, зарегистрированных в базе данных.
- **Отобразить курсы**: Показать все доступные курсы в базе данных.
- **Отобразить записи на курсы**: Показать все записи, связывающие студентов с их курсами.
- **Обновить специальность студента**: Обновление специальности студента.

### Структура проекта
Проект следует модульному дизайну, чтобы обеспечить хорошую организацию и поддерживаемость функциональности:

- **Main.cpp**: Содержит основную функцию, которая обрабатывает взаимодействие с пользователем через меню.
- **Database.h / Database.cpp**: Определяет и реализует класс `Database`, который инкапсулирует операции с базой данных SQLite.
- **Student.h / Student.cpp**: Определяет и реализует класс `Student`, который управляет данными студента, такими как имя, возраст, специальность и записанные курсы.

### Схема базы данных
- **Students**: Хранит информацию о студентах (ID, имя, возраст, специальность).
- **Courses**: Хранит информацию о курсах (ID, название).
- **Enrollments**: Хранит связи между студентами и курсами (ID студента, ID курса).

### Как собрать и запустить
Для компиляции и запуска проекта вам понадобится компилятор C++, например, **g++**:

1. **Клонируйте репозиторий** (или загрузите исходные файлы):
   ```sh
   git clone <repository-url>
   ```

2. **Перейдите в каталог проекта**:
   ```sh
   cd UniversityManagementSystem
   ```

3. **Соберите проект**:
   Вы можете собрать проект с помощью **g++**, включив все файлы `.cpp`:
   ```sh
   g++ Main.cpp Database.cpp Student.cpp -o UniversityManagementSystem -lsqlite3
   ```

4. **Запустите приложение**:
   ```sh
   ./UniversityManagementSystem
   ```

### Пример использования
```
Menu:
1. Add Student
2. Add Course
3. Enroll Student in Course
4. Display Students
5. Display Courses
6. Display Enrollments
7. Update Student Major
8. Exit
Enter your choice: 1
Enter student name: Alice
Enter student age: 20
Enter student major: Computer Science
Student added successfully.
```

### Зависимости
- Совместимый с C++17 компилятор (например, **g++**).
- **SQLite3**: Проект использует SQLite для управления данными, требуются библиотека и заголовочные файлы SQLite3.

### Возможные улучшения
- **Оценки студентов**: Добавить функциональность для управления оценками студентов по каждому курсу.
- **Предварительные требования для курсов**: Реализовать систему предварительных требований для некоторых курсов.
- **Аутентификация пользователей**: Добавить роли пользователей и аутентификацию для управления доступом к данным.
