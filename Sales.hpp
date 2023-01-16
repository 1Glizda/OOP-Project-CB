
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>

class Sales {
private:
    std::map<std::string, Ticket> sold_tickets;

public:
    Sales();
    std::string processSale(Ticket& ticket, Event& event, EventLocation& location);
    
std::string processSale(Ticket& ticket, Event& event, EventLocation& location) {
    std::string ticket_id = ticket.getUniqueID();
    if (sold_tickets.count(ticket_id) > 0) {
        return "Ticket already sold.";
    }
    sold_tickets[ticket_id] = ticket;
    std::cout << "Ticket for event: " << event.getName() << " on " << event.getDate() << " at " << location.getName() << " sold for $" << ticket.getPrice() << std::endl;
}

std::string generateQRCode(std::string ticket_id) {
    std::string filename = ticket_id + ".png";
    cv::Mat img(250, 250, CV_8UC3, cv::Scalar(255, 255, 255));

    // Create the QR code image
    cv::QRCode qr = cv::QRCode();
    qr.make(ticket_id);
    qr.render(img);

    // Save the QR code image to a file
    cv::imwrite(filename, img);
    return filename;
}

};