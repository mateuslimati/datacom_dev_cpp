/**
 * @file context.cpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <context.hpp>
#include <iostream>

/**
 * @brief Construct a new protocol::context::Context::Context object
 * 
 * @param state 
 */
protocol::context::Context::Context(std::unique_ptr<state::State> state)
{
    this->TransitionTo(std::move(state));
}

/**
 * @brief Destroy the protocol::context::Context::Context object
 * 
 */
protocol::context::Context::~Context()
{
}

/**
 * @brief 
 * 
 * @param state 
 */
void protocol::context::Context::TransitionTo(std::unique_ptr<protocol::state::State> state)
{
    std::cout << "Context: Transition to " << typeid(*state).name() << std::endl;
    this->state = std::move(state);
    this->state->SetContext(this);
}

/**
 * @brief 
 * 
 */
void protocol::context::Context::Event(protocol::event::Event event)
{
    this->state->Handle(event);
}