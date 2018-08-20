//
// Created by nimdos on 8/15/18.
//

#pragma once

#include "object.h"
#include <vector>
#include <memory>

namespace DesignPattern {

    class IObjectPool {
        public:
            virtual ~IObjectPool(){}
            virtual auto get() -> std::unique_ptr<Object> = 0;
            virtual auto release(std::unique_ptr<Object> obj) -> void = 0;
        private:
    };

    class ObjectPool : public IObjectPool {
        public:

         std::unique_ptr<Object> get() override {
            if(instances_.empty()){
                return std::make_unique<Object>();

            }
            std::unique_ptr<Object> object = std::move(instances_.front());
            instances_.erase(instances_.begin());
            return object;
        }

        auto release(std::unique_ptr<Object> obj) -> void override {
            // Reset object state
            obj->set_data(0);
            // Insert object
            instances_.push_back(std::move(obj));
        }

        private:
            std::vector<std::unique_ptr<Object>> instances_;
    };
}