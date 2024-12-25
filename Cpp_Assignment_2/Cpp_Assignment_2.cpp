#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

// 필수과제
class Animal
{
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "멍멍!" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "야옹~" << endl;
    }
};

class Cow : public Animal
{
public:
    void makeSound() override
    {
        cout << "음머~" << endl;
    }
};

// 도전과제
class Zoo
{
private:
    Animal* animals[10] = { 0 };
    int animalCount;

public:
    Zoo() : animalCount(0) {}
    void addAnimal(Animal* animal)
    {
        if (animalCount < 10)
        {
            animals[animalCount++] = animal;
        }
        else
        {
            cout << "동물원이 꽉 찼습니다." << endl;
        }
    }
    void performActions()
    {
        for (int i = 0; i < animalCount; i++)
        {
            animals[i]->makeSound();
        }
    }
    ~Zoo()
    {
        for (int i = 0; i < animalCount; i++)
        {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal()
{
    int randomNum = rand() % 3;
    if (randomNum == 0)
    {
        return new Dog();
    }
    else if (randomNum == 1)
    {
        return new Cat();
    }
    else if (randomNum == 2)
    {
        return new Cow;
    }
}

int main()
{
    // 필수과제
    cout << "|=== 필수과제 ===|" << endl;
    vector<unique_ptr<Animal>> arr;

    arr.push_back(make_unique<Dog>());
    arr.push_back(make_unique<Cat>());
    arr.push_back(make_unique<Cow>());

    for (const auto& obj : arr)
    {
        obj->makeSound();
    }

    // 도전과제
    cout << "\n|=== 도전과제 ===|" << endl;
    srand((unsigned int)time(NULL));

    Zoo zoo;

    for (int i = 0; i < 12; i++)
    {
        zoo.addAnimal(createRandomAnimal());
    }

    zoo.performActions();
}
