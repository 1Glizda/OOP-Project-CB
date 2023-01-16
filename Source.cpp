// Criste Bogdan 1066 CSIE, individual project (Ticketing App)

#include "Event.hpp"
#include "EventLocation.hpp"
#include "Ticket.hpp"
#include "Sales.hpp"
#include <iostream>
#include <string>

int main() {
    Ticket myTicket("Concert", 5, "Early Bird", true, true, 150.0, "VIP", 1);
    Event myEvent("Concert", "2022-06-12", 1);
    EventLocation myLocation("Madison Square Garden", "New York");

    std::cout << "Ticket Type: " << myTicket.getType() << std::endl;
    myTicket.setType("Sports");
    std::cout << "Ticket Type: " << myTicket.getType() << std::endl;

    Sales sale;
    std::string qr_code = sale.processSale(myTicket, myEvent, myLocation);
    std::cout << "QR code: " << qr_code << std::endl;

    return 0;
}


