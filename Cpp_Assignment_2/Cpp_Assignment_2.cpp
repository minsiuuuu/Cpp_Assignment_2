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
}
