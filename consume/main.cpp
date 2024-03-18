#include <src/pugixml.hpp>
#include <iostream>

int main()
{
    std::cout<<"HY CONAN"<<std::endl;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("/home/maanz-ai/Desktop/conan/consume/xgconsole.xml");
    if (!result)
        return -1;
    std::cout<<"Hassan Nawazish\n";    
    for (pugi::xml_node tool: doc.child("Profile").child("Tools").children("Tool"))
    {
        int timeout = tool.attribute("Timeout").as_int();
        
        if (timeout > 0)
            std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
    }
}

