#include <AppCUI/include/AppCUI.hpp>

using namespace AppCUI;
using namespace AppCUI::Application;
using namespace AppCUI::Controls;

class SimpleWin : public AppCUI::Controls::Window
{
    Reference<Label> l1;
    Reference<Label> b1;

public:
    SimpleWin() : Window("Caption", "d:c", WindowFlags::Maximized)
    {
        l1 = Factory::Label::Create(
            this,
            "This is a simple Window example that creates a 40x20 fixed window that  will close if you click on the "
            "[X]  button from the bottom-top corner.",
            "x:1,y:1,w:36,h:5");

        b1 = Factory::Label::Create(
            this,
            "X",
            "x:20,y:5,w:5,h:5");
    }
    bool OnEvent(Reference<Control> sender, Event eventType, int controlID) override
    {
        if (eventType == Event::WindowClose)
        {
            Application::Close();
            return true;
        }
        return false;
    }

    bool OnKeyEvent(Input::Key keyCode, char16 UnicodeChar) override
    {
        constexpr int size_to_move = 2;
        switch (keyCode)
        {
        case  Input::Key::Left:
            b1->MoveTo(b1->GetX() - size_to_move, b1->GetY());
            break;
        case  Input::Key::Right:
            b1->MoveTo(b1->GetX() + size_to_move, b1->GetY());
            break;
        case  Input::Key::Up:
            b1->MoveTo(b1->GetX(), b1->GetY() - size_to_move);
            break;
        case  Input::Key::Down:
            b1->MoveTo(b1->GetX(), b1->GetY() + size_to_move);
            break;
        default:
            return false;
        }

        return true;
    }
};
int main()
{
    if (!Application::Init())
        return 1;
    ItemHandle itemHandle = 0;
    Application::AddWindow(std::make_unique<SimpleWin>(), itemHandle);
    Application::Run();
    return 0;
}
