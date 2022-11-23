#include <iostream>

enum commands { MOVE = 1, RESIZE, DISPLAY, CLOSE };

class Screen 
{
private:
  const int width = 80;
  const int height = 50;

public:
  int getWidth() { return width; }

  int getHeight() { return height; }
};

class Window 
{
private:
  struct Coordinates 
  {
    int x = 0;
    int y = 0;
  } dot;
  int width;
  int height;

public:
  void setDot(const int newX, const int newY) 
  {
    dot.x = newX;
    dot.y = newY;
  }

  void setWidth(const int &newWidth) { width = newWidth; }

  void setHeight(const int &newHeight) { height = newHeight; }

  void setWindowSize(Screen *monitorScreen) 
  {
    int xDot, yDot;
    std::cout << "Input coordinates of top left border of window (y and x): ";
    std::cin >> yDot >> xDot;
    while ((xDot <= 0 || xDot > monitorScreen->getWidth()) &&
           (yDot <= 0 || yDot > monitorScreen->getHeight())) {
      std::cout
          << "Input is invalid. Your coordinates is out of screen. Try again."
          << std::endl;
      std::cout << "Input values of top left border of window (y and x): ";
      std::cin >> yDot >> xDot;
    }
    setDot(xDot - 1, yDot - 1);
    int heightNew, widthNew;
    std::cout << "Input values of window size (height and width): ";
    std::cin >> heightNew >> widthNew;
    while ((dot.y + heightNew <= 0 ||
            dot.y + heightNew > monitorScreen->getHeight()) &&
           (dot.y + heightNew <= 0 ||
            dot.x + widthNew > monitorScreen->getWidth())) {
      std::cout << "Input is invalid. Your window is out of screen. Try again."
                << std::endl;
      std::cout << "Input values of window size (height and width): ";
      std::cin >> heightNew >> widthNew;
    }
    setWidth(widthNew);
    setHeight(heightNew);
  }

  static void move(Window *usingWindow, Screen *monitorScreen) 
  {
    int xNew, yNew;
    std::cout << "Input values of moving vector (y and x): ";
    std::cin >> yNew >> xNew;
    while (xNew + usingWindow->width > monitorScreen->getWidth() &&
           yNew + usingWindow->height > monitorScreen->getHeight()) {
      std::cout << "Input is invalid. Your window is out of screen. Try again."
                << std::endl;
      std::cout << "Input values of moving vector (y and x): ";
      std::cin >> yNew >> xNew;
    }
    usingWindow->setDot(usingWindow->dot.x + xNew, usingWindow->dot.y + yNew);
    std::cout << "Window's current position: (" << usingWindow->dot.y + 1
              << "; " << usingWindow->dot.x + 1 << ").";
    std::cout << std::endl;
  }

  static void resize(Window *usingWindow, Screen *monitorScreen) 
  {
    int heightNew, widthNew;
    std::cout << "Input values of window size (height and width): ";
    std::cin >> heightNew >> widthNew;
    while ((usingWindow->dot.y + heightNew <= 0 ||
            usingWindow->dot.y + heightNew > monitorScreen->getHeight()) &&
           (usingWindow->dot.x + heightNew <= 0 ||
            usingWindow->dot.x + widthNew > monitorScreen->getWidth())) {
      std::cout << "Input is invalid. Your window is out of screen. Try again."
                << std::endl;
      std::cout << "Input values of window size (height and width): ";
      std::cin >> heightNew >> widthNew;
    }
    usingWindow->width = widthNew;
    usingWindow->height = heightNew;
    std::cout << "Window's current size: ";
    std::cout << "Height: " << usingWindow->height << ";" << std::endl;
    std::cout << "Width: " << usingWindow->width << "." << std::endl;
  }

  static void display(Window *usingWindow, Screen *monitorScreen) 
  {
    int screenHeight = monitorScreen->getHeight();
    int screenWidth = monitorScreen->getWidth();
    int windowWidth = usingWindow->width;
    int windowHeight = usingWindow->height;
    Coordinates windowDot = usingWindow->dot;
    for (int i = 0; i < screenHeight; ++i) {
      for (int j = 0; j < screenWidth; ++j) {
        if (i >= windowDot.y && i < (windowDot.y + windowHeight) &&
            j >= windowDot.x && j < (windowDot.x + windowWidth))
          std::cout << '1';
        else
          std::cout << '0';
      }
      std::cout << std::endl;
    }
  }
};

void instruction() 
{
  std::cout << std::endl;
  std::cout << "------------ How to use it ------------" << std::endl;
  std::cout << "1 - move window;" << std::endl;
  std::cout << "2 - resize window;" << std::endl;
  std::cout << "3 - display screen;" << std::endl;
  std::cout << "4 - exit." << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  std::cout << std::endl;
}

int main() 
{
  Screen *myScreen = new Screen();
  Window *myWindow = new Window();
  myWindow->setWindowSize(myScreen);

  instruction();
  int cmd;
  std::cout << "Input command: ";
  std::cin >> cmd;

  while (cmd != CLOSE) 
  {
    switch (cmd) 
    {
    case MOVE:
      Window::move(myWindow, myScreen);
      break;
    case RESIZE:
      Window::resize(myWindow, myScreen);
      break;
    case DISPLAY:
      Window::display(myWindow, myScreen);
      break;
    default:
      std::cout << "Invalid command." << std::endl;
    }

    instruction();
    std::cout << "Input command: ";
    std::cin >> cmd;
  }

  delete myScreen;
  delete myWindow;
  myWindow = nullptr;
  myScreen = nullptr;
  return 0;
}
