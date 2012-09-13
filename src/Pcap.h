#ifndef _NODE_PCAP_H
#define _NODE_PCAP_H

#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <pcap/pcap.h>
#include <netinet/in.h>

/**
  \class Pcap "Pcap.h"
  \brief Node bindings for PCAP.
 */
class Pcap : node::ObjectWrap {
public:
  /**
    \brief Actually bind these functions to Node.

    \param[in] target               The superduper binding object to bind the bindings.
   */
  static void Init(v8::Handle<v8::Object> target);


  /**
    \brief A binding for pcap_findalldevs(3).

    The JavaScript object returned has the same structure as the actual result of
    pcap_findalldevs(3).

    \param[in] args                 The arguments passed via Node.
    \retval v8::Handle<v8::Object>  The result of pcap_findalldevs(3).
   */
  static v8::Handle<v8::Value> FindAllDevices(const v8::Arguments& args);


  /**
    \brief A binding for pcap_lib_version(3).

    \param[in] args                 The arguments passed via Node.
    \retval v8::Handle<v8::String>  The result of pcap_lib_version(3).
   */
  static v8::Handle<v8::Value> LibraryVersion(const v8::Arguments& args);

private:
  /**
    \brief Initialise any required attributes.
   */
  Pcap();


  /**
    \brief A reusable wrapper for inet_pton(3).

    \param[in] socketAddress        The internal representation of the socket address.
    \retval v8::String              The string representation of the socket address.
    \retval v8::Undefined()         If the address is not AF_INET(6)? or if inet_pton(3) failed.
   */
  static v8::Handle<v8::Value> NtoP(struct sockaddr *socketAddress);
};

#endif//_NODE_PCAP_H
