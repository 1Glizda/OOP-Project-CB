#include <string>

class Ticket {
  public:
    Ticket(std::string type, int days, std::string salePhase, bool isRiskFree, bool isVIP, double price, std::string zone, int seat);

    std::string getType();
    int getDays();
    std::string getSalePhase();
    bool getIsRiskFree();
    bool getIsVIP();
    double getPrice();
    std::string getZone();
    int getSeat();
    std::string getUniqueID();

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
