/**
 * @file main.cpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief Service main file
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <memory.h>

#include "context.hpp"
#include "state.hpp"

/**
 * @brief service main function.
 *
 * @param[in] argc argument count
 * @param[in] argv argument vector
 * @return int
 */
int main(int argc, char const *argv[])
{
    /**
     * @brief Start the context setting the machine to state LinkDown.
     *
     */
    std::unique_ptr<protocol::context::Context> context =
        std::make_unique<protocol::context::Context>(std::make_unique<protocol::state::LinkDown>());
    /**
     * @brief Set the associated event to InterfaceOk.
     *        After that the machine state change to SendingStart.
     */
    context->Event(protocol::event::Event::InterfaceOk);
    /**
     * @brief Set the associated event to OkReceivedPacket.
     *        After that the machine state change to StartReceivedSendConfiguration.
     */
    context->Event(protocol::event::Event::OkReceivedPacket);
    /**
     * @brief Set the associated event to OkReceivedPacket.
     *        After that the machine state change to SendingKeepAlive.
     */
    context->Event(protocol::event::Event::OkReceivedPacket);

    return EXIT_SUCCESS;
}
