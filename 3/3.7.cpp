#include <iostream>
#include <queue>
#include <string>

struct Animal {
    std::string name;
    int timestamp;
    Animal(std::string name = "null", int timestamp = -1): name(name), timestamp(timestamp){}
};

class Shelter {
public:
    Animal AdoptAny() {
        if (dogs.empty()) return AdoptCat();
        if (cats.empty()) return AdoptDog();
        if (dogs.front().timestamp < cats.front().timestamp) return AdoptDog();
        else return AdoptCat();
    }

    Animal AdoptCat() {
        if (cats.empty()) return Animal();
        Animal cat = cats.front();
        cats.pop();
        return cat;
    }

    Animal AdoptDog() {
        if (dogs.empty()) return Animal();
        Animal dog = dogs.front();
        dogs.pop();
        return dog;
    }

    void ShelteCat(const Animal &cat) {
        cats.push(Animal(cat.name, ++timestamp));
    }

    void ShelteDog(const Animal &dog) {
        dogs.push(Animal(dog.name, ++timestamp));
    }
private:
    std::queue<Animal> dogs;
    std::queue<Animal> cats;
    static int timestamp;
};

int Shelter::timestamp = 0;

int main() {
    Shelter shelter;
    shelter.ShelteDog(Animal("dog1"));
    shelter.ShelteCat(Animal("cat1"));
    shelter.ShelteDog(Animal("dog2"));
    shelter.ShelteDog(Animal("dog3"));
    shelter.ShelteCat(Animal("cat2"));
    shelter.ShelteDog(Animal("dog4"));
    shelter.ShelteCat(Animal("cat3"));
    shelter.ShelteCat(Animal("cat4"));
    std::cout << shelter.AdoptCat().name << std::endl;
    std::cout << shelter.AdoptAny().name << std::endl;
    std::cout << shelter.AdoptDog().name << std::endl;
    std::cout << shelter.AdoptCat().name << std::endl;
    std::cout << shelter.AdoptAny().name << std::endl;
    std::cout << shelter.AdoptAny().name << std::endl;
    std::cout << shelter.AdoptAny().name << std::endl;
    std::cout << shelter.AdoptAny().name << std::endl;
    std::cout << shelter.AdoptAny().name << std::endl;
    return 0;
}