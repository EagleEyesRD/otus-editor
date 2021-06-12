#include "view.h"
#include "model.h"
#include "controller.h"
#include <iostream>
#include <memory>
#include <fstream>

void DataChange(std::string data) {
    std::cout << "Data Changes: " << data << std::endl;
}

std::ostream& operator << (std::ostream& stream, Model m)
{
    stream << m.getData();

    return stream;
}

class Editor
{
public:
	Editor();
	~Editor();
    void Open(std::string pathDoc);
    void Modify(std::string data);
    void Save(std::string pathDoc);
private:
    std::unique_ptr<Controller> base;
};

Editor::Editor()
{
    Model model("Model");
    View view(model);
    model.RegisterDataChangeHandler(&DataChange);
    base = std::make_unique<Controller>(model, view);
    base->OnLoad();
}

Editor::~Editor()
{
}

void Editor::Open(std::string pathDoc) {
    std::ifstream in_data(pathDoc);
    if (in_data.is_open()) {
        std::string line;
        std::getline(in_data, line);
        if (line.length() > 0) {
            Model model = Model(line);
            base->SetModel(model);
            
        }
        in_data.close();
    }
    base->OnLoad();
}

void Editor::Modify(std::string data) { base->SetModel( Model(data)); }

void Editor::Save(std::string pathDoc) {
    std::ofstream out_data(pathDoc,std::ios_base::app);
    if (out_data.is_open()) {
        out_data << base->GetModel();
        out_data.close();
    }
}
