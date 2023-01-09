#include <string>
#include <unordered_map>

class EventLocation {
  public:
    EventLocation(std::string location, std::unordered_map<std::string, int> zones, int totalCapacity);

    std::string getLocation();
    std::unordered_map<std::string, int> getZones();
    int getTotalCapacity();

  private:
    std::string location_;
    std::unordered_map<std::string, int> zones_;
    int totalCapacity_;
};
