/**
 * @file state.cpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <state.hpp>
#include <iostream>

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

}

/**
 * @brief 
 * 
 */
void protocol::state::StartReceivedSendConfiguration::Handle(protocol::event::Event event)
{

}

/**
 * @brief 
 * 
 */
void protocol::state::SendingStart::Handle(protocol::event::Event event)
{

}

/**
 * @brief 
 * 
 */
void protocol::state::SendingKeepAlive::Handle(protocol::event::Event event)
{

}