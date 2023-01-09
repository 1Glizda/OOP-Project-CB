#include <string>

class Event {
  public:
    Event(std::string name, std::string date, int edition);

    std::string getName();
    std::string getDate();
    int getEdition();

  private:
    std::string name_;
    std::string date_;
    int edition_;
};
