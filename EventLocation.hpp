#include <string>
#include <unordered_map>

class EventLocation {
public:

   void setLocation(std::string location) {
        location_ = location;
    }

    void setZones(std::unordered_map<std::string, int> zones) {
        zones_ = zones;
    }

    void setTotalCapacity(int totalCapacity) {
        totalCapacity_ = totalCapacity;
    }

    std::string getLocation() {
        return location_;
    }

    std::unordered_map<std::string, int> getZones() {
        return zones_;
    }

    int getTotalCapacity() {
        return totalCapacity_;
    }

  private:
    std::string location_;
    std::unordered_map<std::string, int> zones_;
    int totalCapacity_;
};
