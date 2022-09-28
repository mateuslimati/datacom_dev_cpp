/**
 * @file context.hpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __CONTEXT_HPP__
#define __CONTEXT_HPP__

#include <state.hpp>
#include <memory>
#include "event.hpp"

namespace protocol::state {
    class State;
}

/* Declarações no namespace protocol::state */
namespace protocol::context
{
    class Context
    {
    private:
        std::unique_ptr<protocol::state::State> state;

    public:
        Context(std::unique_ptr<protocol::state::State> state);
        ~Context();
        void TransitionTo(std::unique_ptr<protocol::state::State> state);
        void Event(protocol::event::Event event);
    };
};

#endif //__CONTEXT_HPP__