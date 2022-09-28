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

/* Declarações no namespace protocol::state */
namespace protocol::context
{
    class Context
    {
        /**
         * @var State A reference to the current state of the Context.
         */
    private:
        protocol::state::State *state;

    public:
        Context(protocol::state::State *state) : state(nullptr)
        {
            this->TransitionTo(state);
        }
        ~Context()
        {
            delete state;
        }
        /**
         * The Context allows changing the State object at runtime.
         */
        void TransitionTo(protocol::state::State *state)
        {
            if (this->state != nullptr)
                delete this->state;
            this->state = state;
            this->state->set_context(this);
        }
    };
};  

#endif //__CONTEXT_HPP__