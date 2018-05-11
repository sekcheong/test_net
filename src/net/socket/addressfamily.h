#ifndef _NET_ADDRESSFAMILY_H_
#define _NET_ADDRESSFAMILY_H_

namespace msv {
namespace net {
namespace sockets {

enum class address_family {
  Unknown = -1,           // Unknown
  Unspecified = 0,        // unspecified
  Unix = 1,               // local to host (pipes, portals)
  InterNetwork = 2,       // internetwork: UDP, TCP, etc.
//  ImpLink = 3,            // arpanet imp addresses
//  Pup = 4,                // pup protocols: e.g. BSP
//  Chaos = 5,              // mit CHAOS protocols
//  NS = 6,                 // XEROX NS protocols
//  Ipx = NS,               // IPX and SPX
//  Iso = 7,                // ISO protocols
//  Osi = Iso,              // OSI is ISO
//  Ecma = 8,               // european computer manufacturers
//  DataKit = 9,            // datakit protocols
//  Ccitt = 10,             // CCITT protocols, X.25 etc
//  Sna = 11,               // IBM SNA
//  DecNet = 12,            // DECnet
//  DataLink = 13,          // Direct data link interface
//  Lat = 14,               // LAT
//  HyperChannel = 15,      // NSC Hyperchannel
//  AppleTalk = 16,         // AppleTalk
//  NetBios = 17,           // NetBios-style addresses
//  VoiceView = 18,         // VoiceView
//  FireFox = 19,           // FireFox
//  Banyan = 21,            // Banyan
//  Atm = 22,               // Native ATM Services
//  InterNetworkV6 = 23,    // Internetwork Version 6
//  Cluster = 24,           // Microsoft Wolfpack
//  Ieee12844 = 25,         // IEEE 1284.4 WG AF
//  Irda = 26,              // IrDA
//  NetworkDesigners = 28,  // Network Designers OSI & gateway enabled protocols
//  Max = 29,               // Max
};


}
}
}

#endif
