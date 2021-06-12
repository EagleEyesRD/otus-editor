#pragma once
#include <string>
#include <vector>

typedef void (*DataChangeHandler)(std::string newData);

class Model {
public:
    Model(const std::string& data) {
        this->SetData(data);
    }
    
    Model() {}

    std::string getData() const { return data;}

    void SetData(const std::string& data) {
        this->data = data;
        if (this->event != nullptr) { 
            this->event(data);
        }
    }
    
    void RegisterDataChangeHandler(DataChangeHandler handler) {
        this->event = handler;
    }
 
private:
    std::string data = "";
    DataChangeHandler event = nullptr;
}; 

