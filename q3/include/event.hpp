/**
 * @file event.hpp
 * @author Mateus Lima Alves (mateuslima.ti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __EVENT_HPP__
#define __EVENT_HPP__

namespace protocol::event
{
    enum class Event : char
    {
        InterfaceNok,
        InterfaceOk,
        OkReceivedPacket,
        NokReceivedPacket,
        NotReceivedAnswer
    };
}

#endif//__EVENT_HPP__