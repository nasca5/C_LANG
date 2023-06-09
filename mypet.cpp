#include <iostream>
#include <vector>
#include <string>

typedef struct Animal {
  char name[30];
  int age, health, food, clean;
} Animal;

void create_animal(Animal& animal) {
  std::cout << "what's the name? : " << endl;
  std::cin >> animal.name;
  std::cout << "age? : " << endl;
  std::cin >> animal.age;
  std::cout << "health? : " << endl;
  std::cin >> animal.health;
  std::cout << "food? : " << endl;
  std::cin >> animal.food;
  std::cout << "clean? : " << endl;
  std::cin >> animal.clean;
}

void play() {

}

void show_stat() {

}

int main() {
  Animal* list[30];

  create_animal(list[0]);

  return 0;
}