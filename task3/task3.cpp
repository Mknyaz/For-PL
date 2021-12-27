#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace nlohmann;
using namespace std;

void replace(json& tests, json& values) {
    for (auto& t : tests) {
        for (auto& v : values) {
            if (t["id"] == v["id"])
                t["value"] = v["value"];
            if (t["values"] != detail::value_t::null) // если в values есть вложенные значения
                replace(t["values"], values);
        }
    }
}

int main()
{
    json tests, values;
    ifstream src1("tests.json");
    src1 >> tests;
    ifstream src2("values.json");
    src2 >> values;
    src1.close();
    src2.close();
    ofstream foo("report.json");
    replace(tests["tests"], values["values"]);
    foo << tests;
    foo.close();
}
