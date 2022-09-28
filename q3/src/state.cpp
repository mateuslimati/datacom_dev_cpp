/**
 * @file state.cpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief State class methods.
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "state.hpp"

/**
 * @brief Destroy the protocol::state::State::State object
 *
 */
protocol::state::State::~State()
{
}

/**
 * @brief
 *
 * @param context
 */
void protocol::state::State::SetContext(context::Context *context)
{
    this->context = context;
}

/**
 * @brief
 *
 */
void protocol::state::LinkDown::Handle(protocol::event::Event event)
{
    switch (event)
    {
    case protocol::event::Event::InterfaceOk:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingStart>());
        break;
    case protocol::event::Event::InterfaceNok:
    case protocol::event::Event::OkReceivedPacket:
    case protocol::event::Event::NokReceivedPacket:
    case protocol::event::Event::NotReceivedAnswer:
        this->context->TransitionTo(std::make_unique<protocol::state::LinkDown>());
        break;
    default:
        break;
    }
}

/**
 * @brief
 *
 */
void protocol::state::SendingStart::Handle(protocol::event::Event event)
{
    switch (event)
    {
    case protocol::event::Event::InterfaceNok:
        this->context->TransitionTo(std::make_unique<protocol::state::LinkDown>());
        break;
    case protocol::event::Event::InterfaceOk:
        break;
    case protocol::event::Event::OkReceivedPacket:
        this->context->TransitionTo(std::make_unique<protocol::state::StartReceivedSendConfiguration>());
        break;
    case protocol::event::Event::NokReceivedPacket:
    case protocol::event::Event::NotReceivedAnswer:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingStart>());
        break;
    default:
        break;
    }
}

/**
 * @brief
 *
 */
void protocol::state::StartReceivedSendConfiguration::Handle(protocol::event::Event event)
{
    switch (event)
    {
    case protocol::event::Event::InterfaceNok:
        this->context->TransitionTo(std::make_unique<protocol::state::LinkDown>());
        break;
    case protocol::event::Event::InterfaceOk:
        break;
    case protocol::event::Event::OkReceivedPacket:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingKeepAlive>());
        break;
    case protocol::event::Event::NokReceivedPacket:
        this->context->TransitionTo(std::make_unique<protocol::state::StartReceivedSendConfiguration>());
        break;
    case protocol::event::Event::NotReceivedAnswer:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingStart>());
        break;
    default:
        break;
    }
}

/**
 * @brief
 *
 */
void protocol::state::SendingKeepAlive::Handle(protocol::event::Event event)
{
    switch (event)
    {
    case protocol::event::Event::InterfaceNok:
        this->context->TransitionTo(std::make_unique<protocol::state::LinkDown>());
        break;
    case protocol::event::Event::InterfaceOk:
        break;
    case protocol::event::Event::OkReceivedPacket:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingKeepAlive>());
        break;
    case protocol::event::Event::NokReceivedPacket:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingStart>());
        break;
    case protocol::event::Event::NotReceivedAnswer:
        this->context->TransitionTo(std::make_unique<protocol::state::SendingStart>());
        break;
    default:
        break;
    }
}