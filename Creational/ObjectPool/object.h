//
// Created by nimdos on 8/15/18.
//

#pragma once

#include "base.h"

namespace DesignPattern {

    class Object {
        public:
            auto set_data(int_t data) -> void {
                data_ = data;
            }

            auto get_data() -> int_t {
                return data_;
            }

        private:
            int_t data_;
    };

}
