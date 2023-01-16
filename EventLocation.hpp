#include <string>
#include <unordered_map>

class EventLocation {
public:
EventLocation(std::string location, std::unordered_map<std::string, std::string> zones, int totalCapacity) 
: location_(location), zones_(zones), totalCapacity_(totalCapacity) {};
   
   void setLocation(std::string location) {
        location_ = location;
    }

    void setZones(std::unordered_map<std::string, std::string> zones) {
        zones_ = zones;
    }

    void setTotalCapacity(int totalCapacity) {
        totalCapacity_ = totalCapacity;
    }

    std::string getLocation() {
        return location_;
    }

    std::unordered_map<std::string, std::string> getZones() {
        return zones_;
    }

    int getTotalCapacity() {
        return totalCapacity_;
    }

  private:
    std::string location_;
    std::unordered_map<std::string, std::string> zones_;
    int totalCapacity_;
};
