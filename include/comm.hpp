#ifndef __COMM_H
#define __COMM_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <zmq.hpp>
#include <openenclave/host.h>

#include "capsule.pb.h"
#include "config.h"

class Comm
{
public:
    Comm(oe_enclave_t *enclave);

    void run_dc_proxy_listen_write_req_and_join_mcast();
    void run_dc_proxy_listen_ack();

    void host_dc_proxy_send_ack_to_replyaddr(std::string &out_msg, const std::string &replyaddr);

private:
    std::string m_join_mcast_port;
    std::string m_write_port;
    std::string m_ack_port;

    zmq::context_t m_context;
    oe_enclave_t *m_enclave;
    std::unordered_map<std::string, zmq::socket_t *> m_multicast_dc_server_addrs;
    std::unordered_map<std::string, zmq::socket_t *> m_send_ack_to_client_map;

    zmq::message_t string_to_message(const std::string &s)
    {
        zmq::message_t msg(s.size());
        memcpy(msg.data(), s.c_str(), s.size());
        return msg;
    }

    std::string message_to_string(const zmq::message_t &message)
    {
        return std::string(static_cast<const char *>(message.data()), message.size());
    }
    std::string recv_string(zmq::socket_t *socket)
    {
        zmq::message_t message;
        socket->recv(&message);
        return this->message_to_string(message);
    }
    void send_string(const std::string &s, zmq::socket_t *socket)
    {
        socket->send(string_to_message(s));
    }
};

#endif // __COMM_H