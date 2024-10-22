#include <iostream>
#include <vector>
#include <string>

// Класс Resource
class Resource {
private:
    int id;
    std::string title;
    std::string author;
    std::string category;
    int year;
    std::string access_link;
    int views;

public:
    // Конструктор по умолчанию
    Resource() : id(0), title(""), author(""), category(""), year(0), access_link(""), views(0) {}

    // Конструктор с параметрами
    Resource(int id, const std::string& title, const std::string& author, const std::string& category, int year, const std::string& access_link, int views) 
    : id(id), title(title), author(author), category(category), year(year), access_link(access_link), views(views) {}

    // Методы для редактирования свойств
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    void setCategory(const std::string& newCategory) {
        category = newCategory;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    void setAccessLink(const std::string& newLink) {
        access_link = newLink;
    }

    void setViews(int newViews) {
        views = newViews;
    }

    // Методы для получения свойств
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getCategory() const { return category; }
    int getYear() const { return year; }
    std::string getAccessLink() const { return access_link; }
    int getViews() const { return views; }

    // Метод для отображения информации о ресурсе
    void display() const {
        std::cout << "ID: " << id << "\nНазвание: " << title << "\nАвтор: " << author
                  << "\nКатегория: " << category << "\nГод: " << year
                  << "\nСсылка: " << access_link << "\nПросмотры: " << views << "\n";
    }
};

// Функция для создания массива объектов
void createArray(std::vector<Resource>& resources, int n) {
    for (int i = 0; i < n; ++i) {
        int id, year, views;
        std::string title, author, category, access_link;

        std::cout << "Введите данные для ресурса " << i + 1 << " (id, название, автор, категория, год, ссылка, просмотры): ";
        std::cin >> id >> title >> author >> category >> year >> access_link >> views;

        Resource res(id, title, author, category, year, access_link, views);
        resources.push_back(res);
    }
}

// Функция для редактирования объекта
void editResource(Resource& resource) {
    std::string newTitle, newAuthor, newCategory, newLink;
    int newYear, newViews;

    std::cout << "Введите новые данные для ресурса (название, автор, категория, год, ссылка, просмотры): ";
    std::cin >> newTitle >> newAuthor >> newCategory >> newYear >> newLink >> newViews;

    resource.setTitle(newTitle);
    resource.setAuthor(newAuthor);
    resource.setCategory(newCategory);
    resource.setYear(newYear);
    resource.setAccessLink(newLink);
    resource.setViews(newViews);
}

// Функция для обработки массива объектов (подсчет общего числа просмотров)
void processArray(const std::vector<Resource>& resources) {
    int totalViews = 0;
    for (const auto& res : resources) {
        totalViews += res.getViews();
    }
    std::cout << "Общее количество просмотров: " << totalViews << std::endl;
}

int main() {
    std::vector<Resource> resources;

    // Создание объекта с помощью конструктора по умолчанию
    Resource defaultResource;

    // Создание объекта с помощью конструктора с параметрами
    Resource paramResource(1, "Title1", "Author1", "Category1", 2021, "www.example.com", 100);

    // Добавление этих объектов в массив
    resources.push_back(defaultResource);
    resources.push_back(paramResource);

    // Создание массива объектов
    int n;
    std::cout << "Сколько объектов хотите добавить? ";
    std::cin >> n;
    createArray(resources, n);

    // Просмотр всех объектов
    for (const auto& res : resources) {
        res.display();
        std::cout << "============================\n";
    }

    // Редактирование объекта
    int idToEdit;
    std::cout << "Введите ID ресурса для редактирования: ";
    std::cin >> idToEdit;
    if (idToEdit >= 0 && idToEdit < resources.size()) {
        editResource(resources[idToEdit]);
    } else {
        std::cout << "Некорректный ID." << std::endl;
    }

    // Обработка массива объектов (подсчет просмотров)
    processArray(resources);

    return 0;
}

