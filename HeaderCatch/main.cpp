#include <iostream>
#include <cpr/cpr.h>

std::string find_h1(std::string &html)
{
    int start = html.find("<h1>") + 4;
    int length = html.find("</h1>") - start;
    return html.substr(start, length);
}

int main()
{
    cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/html"),
                                      cpr::Header({{"accept", "text/html"}}));
    std::cout << find_h1(response.text) << std::endl;
    return 0;
}
