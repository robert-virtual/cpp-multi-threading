#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

using namespace std::chrono_literals;

void fun1(){
    for(int i = 0; i < 200; i++ )
        std::cout << "-";
}

void fun2(char symbol){
    for(int i = 0; i < 200; i++ )
        std::cout << symbol;
}   




class City{
    public:
        std::string name = "Sin Nombre";
        int temperature = 0;
        City(std::string name_,int temp){
            name = name_;
            temperature = temp;
        }
        void toString(){
            std::cout << name << " " << temperature << std::endl;
        }
};

void refreshForecast(std::map<int,City> forecast){
    while(true){
        for(auto [key,city] : forecast){
            city.temperature++;
            std::cout << city.name;
        }
        std::this_thread::sleep_for(2000ms);

    }


}
int main(){
    City danli("Danli",45);

    std::map<int,City> forcastMap = {
        {1,danli},
        {2,City("Mumbai",20)},
        {3,City("Berlin",18)},
        {4,City("alaska",-45)},
        {5,City("new york",15)}
    };

    std::thread bgworker(refreshForecast,forcastMap);

    bgworker.join();
    for(auto[key, value]:forcastMap){
        std::cout << key << ": ";
        value.toString();

    }

    // std::thread worker1(fun1);
    // std::thread worker2(fun2,'1');

    // worker1.join();
    // worker2.join();

    return 0;
}