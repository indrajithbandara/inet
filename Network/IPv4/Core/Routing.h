//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

#ifndef __ROUTING_H__
#define __ROUTING_H__

#include "QueueWithQoS.h"
#include "RoutingTableAccess.h"
#include "RoutingTable.h"
#include "ICMPAccess.h"


/**
 * Use source routing or look into routing table, and send IP datagram
 * to LocalDeliver, Multicast or Fragmentation, or error to ICMP.
 * More detailed info in NED file.
 */
class Routing : public QueueWithQoS
{
  private:
    RoutingTableAccess routingTableAccess;
    ICMPAccess icmpAccess;
    bool IPForward;

  public:
    Module_Class_Members(Routing, QueueWithQoS, 0);

  protected:
    virtual void initialize();
    virtual void endService(cMessage *msg);
};

#endif
