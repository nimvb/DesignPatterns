#include <iostream>
#include "object_pool.h"
using namespace DesignPattern;

auto main() -> int {

    auto pool = std::make_unique<ObjectPool>();
    auto obj = pool->get();

    obj->set_data(200);
    std::cout <<"[*] Data is : " << obj->get_data()<<std::endl;
    pool->release(std::move(obj));

    obj = pool->get();
    std::cout <<"[*] Data is : " << obj->get_data()<<std::endl;


    return 0;
}
