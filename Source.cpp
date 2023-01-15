// Criste Bogdan 1066 CSIE, individual project (Ticketing App)

#include "Event.hpp"
#include "EventLocation.hpp"
#include "Ticket.hpp"
#include <iostream>
#include <string>

int main() {
    Ticket myTicket("Concert", 5, "Early Bird", true, true, 150.0, "VIP", 1);
    std::cout << "Ticket Type: " << myTicket.getType() << std::endl;
    myTicket.setType("Sports");
    std::cout << "Ticket Type: " << myTicket.getType() << std::endl;
    return 0;
}


