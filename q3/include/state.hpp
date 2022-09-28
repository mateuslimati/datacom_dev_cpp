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

/* Declarações no namespace protocol::state */
namespace protocol::state
{
    class State
    {
    protected:
        Context *context;

    public:
        virtual ~State()
        {
        }

        void set_context(Context *context)
        {
            this->context_ = context;
        }

        virtual void Handle1() = 0;
        virtual void Handle2() = 0;
    };

};

#endif //__STATE_H__