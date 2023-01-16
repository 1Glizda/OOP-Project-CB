// Criste Bogdan 1066 CSIE, individual project (Ticketing App)

#include "Event.hpp"
#include "EventLocation.hpp"
#include "Ticket.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "qrencode.h"

class Sales {
private:
    std::map<std::string, Ticket> sold_tickets;

public:    
std::string processSale(Ticket& ticket, Event& event, EventLocation& location) {
    std::string ticket_id = ticket.getUniqueID();
    if (sold_tickets.count(ticket_id) > 0) {
        return "Ticket already sold.";
    }
    sold_tickets[ticket_id] = ticket;
    std::cout << "Ticket for event: " << event.getName() << " on " << event.getDate() << " at " << event.getName() << " sold for $" << ticket.getPrice() << std::endl;
}

std::string generateQRCode(std::string ticket_id) {
    QRcode *qr = QRcode_encodeString(ticket_id.c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 0);
    if (!qr) {
        std::cout << "Error: Failed to generate QR code" << std::endl;
        return "";
    }
    std::string filename = ticket_id + ".png";
    std::ofstream out(filename);
    int width = qr->width;
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < width; x++) {
            out << (qr->data[y * width + x] & 1 ? "##" : "  ");
        }
        out << std::endl;
    }
    QRcode_free(qr);
    out.close();
    return filename;
}
};

int main() {
    std::unordered_map <std::string, std::string> zones = { 

        {"Upper deck", "VIP"},
        {"Middle deck", "General Access"},
        {"Lower deck", "General Access"}

        };

    Ticket myTicket("Concert", 5, "Early Bird", true, true, 150.0, "VIP", 1);
    Event myEvent("Concert", "2022-06-12", 1);
    EventLocation myLocation("Madison Square Garden", {"Upper deck", "VIP"} , 35000);

    std::cout << "Ticket Type: " << myTicket.getType() << std::endl;
    myTicket.setType("Sports");

    std::cout << "Ticket Type: " << myTicket.getType() << std::endl;

    Sales sale;
    std::string qr_code = sale.processSale(myTicket, myEvent, myLocation);
    std::cout << "QR code: " << qr_code << std::endl;

    return 0;
}


