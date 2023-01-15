#include <string>

class Event {
  public:
    Event(std::string name, std::string date, int edition)
: name_(name), date_(date), edition_(edition) {}


std::string getName() {
    return name_;
}

std::string getDate() {
    return date_;
}

int getEdition() {
    return edition_;
}

void setName(std::string name) {
    name_ = name;
}

void setDate(std::string date) {
    date_ = date;
}

void setEdition(int edition) {
    edition_ = edition;
}

  private:
    std::string name_;
    std::string date_;
    int edition_;
};
