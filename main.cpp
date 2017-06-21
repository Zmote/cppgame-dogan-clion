#include "SetView.h"
#include <windows.h>

int main() {
    BOOST_LOG_TRIVIAL(info)<< "Application started";
    SetView::setDefaultHeight(500);
    SetView::setDefaultWidth(800);
    SetView {};
}