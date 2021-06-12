// view.h
// https://helloacm.com/model-view-controller-explained-in-c/
#pragma once
#include <iostream>                  
#include "model.h"                                               
// View is responsible to present data to users
class View {
public:
    View(const Model& model) {
        this->model = model;
    }
    View() {}
    void SetModel(const Model& model) {
        this->model = model;
    }
    void Render() {
        std::cout << "Model Data = " << model.getData() << std::endl;
    }
private:
    Model model;
}; 

