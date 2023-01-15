#include <string>
#include <sstream>
#include <chrono>
#include <thread>

class Ticket {
  public:
    Ticket(std::string type, int days, std::string salePhase, bool isRiskFree, bool isVIP, double price, std::string zone, int seat)
    : type_(type), days_(days), salePhase_(salePhase), isRiskFree_(isRiskFree), isVIP_(isVIP), price_(price), zone_(zone), seat_(seat) {
        // generate a unique ID for the ticket
        std::ostringstream uniqueIDStream;
        uniqueIDStream << std::this_thread::get_id() << std::chrono::system_clock::now().time_since_epoch().count();
        uniqueID_ = uniqueIDStream.str();
    }
    
    void setType(std::string type) {
        type_ = type;
    }

    void setDays(int days) {
        days_ = days;
    }

    void setSalePhase(std::string salePhase) {
        salePhase_ = salePhase;
    }

    void setIsRiskFree(bool isRiskFree) {
        isRiskFree_ = isRiskFree;
    }

    void setIsVIP(bool isVIP) {
        isVIP_ = isVIP;
    }

    void setPrice(double price) {
        price_ = price;
    }

    void setZone(std::string zone) {
        zone_ = zone;
    }

    void setSeat(int seat) {
        seat_ = seat;
    }

    std::string getType() {
        return type_;
    }
  
    int getDays() {
        return days_;
    }

    std::string getSalePhase() {
        return salePhase_;
    }

    bool getIsRiskFree() {
        return isRiskFree_;
    }

    bool getIsVIP() {
        return isVIP_;
    }

    double getPrice() {
        return price_;
    }

    std::string getZone() {
        return zone_;
    }

    int getSeat() {
        return seat_;
    }

    std::string getUniqueID() {
        return uniqueID_;
    }

  private:
    std::string type_;
    int days_;
    std::string salePhase_;
    bool isRiskFree_;
    bool isVIP_;
    double price_;
    std::string zone_;
    int seat_;
    std::string uniqueID_;
};
