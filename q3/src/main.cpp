/**
 * @file main.cpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <memory.h>
#include "context.hpp"

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[])
{
    std::unique_ptr<protocol::context::Context> context =
        std::make_unique<protocol::context::Context>(std::make_unique<protocol::state::LinkDown>());
    context->Event(protocol::event::Event::InterfaceNok);
    context->Event(protocol::event::Event::InterfaceOk);
    
    return 0;
}
