/**
 * @file state.hpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <context.hpp>
#include "event.hpp"

namespace protocol::context
{
    class Context;
}

/* Declarações no namespace protocol::state */
namespace protocol::state
{
    /**
     * @brief
     *
     */
    class State
    {
    protected:
        context::Context *context;

    public:
        virtual ~State();
        void SetContext(context::Context *context);
        virtual void Handle(protocol::event::Event event) = 0;
    };

    /**
     * @brief
     *
     */
    class LinkDown : public State
    {
    public:
        void Handle(protocol::event::Event event) override;
    };

    /**
     * @brief
     *
     */
    class SendingStart : public State
    {
    public:
        void Handle(protocol::event::Event event) override;
    };

    /**
     * @brief
     *
     */
    class StartReceivedSendConfiguration : public State
    {
    public:
        void Handle(protocol::event::Event event) override;
    };
    
    /**
     * @brief 
     * 
     */
    class SendingKeepAlive : public protocol::state::State
    {
    public:
        void Handle(protocol::event::Event event) override;
    };

};

#endif //__STATE_H__