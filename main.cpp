#include <iostream>
#include "LeakedObjectDetector.h"

/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */



/*
 copied UDT 1:
 */

struct Mp3Player
{
    Mp3Player();

    ~Mp3Player() 
    {
        std::cout << "Mp3Player being destructed!" << std::endl;
    }

    int numberOfButtons;
    std::string onOffSwitchColor { "white" };
    float displayScreenWidth;
    float beltClipDepth;
    int numberOfCardSlots;

    void loadFile(std::string filePath); 
    void playFile(); 
    void displayInfo(); 
    int findFiles();

    void showOnOffSwitchColor();

    JUCE_LEAK_DETECTOR(Mp3Player)
};

Mp3Player::Mp3Player() :
numberOfButtons(5),
displayScreenWidth(1.0f),
beltClipDepth(1.0f),
numberOfCardSlots(1)
{
    std::cout << "Mp3Player being constructed!" << std::endl;
}

void Mp3Player::loadFile(std::string filePath)
{
    std::string newPath { "d:/" + filePath };
    std::cout << "Mp3Player::loadFile()" << newPath << std::endl;
}

void Mp3Player::playFile()
{
    std::cout << "Mp3Player::playFile() numberOfButtons:" << numberOfButtons << " beltClipDepth: " << beltClipDepth << std::endl;
}

void Mp3Player::displayInfo()
{
    std::cout << "Mp3Player::displayInfo() displayScreenWidth:" << displayScreenWidth << std::endl;
}

int Mp3Player::findFiles()
{
    int count = 0;
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "file count: " << i << std::endl;
        count = i;
    }
    return count;
}

void Mp3Player::showOnOffSwitchColor()
{
    std::cout << "Mp3Player::showOnOffSwitchColor: " << this->onOffSwitchColor << std::endl;
}

struct Mp3PlayerWrapper
{
    Mp3PlayerWrapper(Mp3Player* ptr) : pointerToMp3Player(ptr){}
    ~Mp3PlayerWrapper()
    {
        delete pointerToMp3Player;
    }
    Mp3Player* pointerToMp3Player = nullptr;
};


/*
 copied UDT 2:
 */

struct CdDrive
{
    CdDrive();
    ~CdDrive();

    int maxSpeed;
    float discDiameter;
    int numberOfTrays;
    std::string color { "black" };
    int numberOfFormatsSupported = 3;

    void playCd(); 
    void playDVD(); 
    void writeCdr(); 
    int findSpeed();

    void showMaxSpeed();

    struct CD
    {
        ~CD() { std::cout << "CD being destructed!" << std::endl; }
        int maxSpeed = 100;
        float outerDiameter = 5.0f;
        float innerDiameter = 0.5f;
        std::string color { "black" };
        std::string title { "Dark Side Of The Moon" };

        void getScratched(); 
        void storeData(); 
        void goObsolete(); 
        JUCE_LEAK_DETECTOR(CD)
    };

    JUCE_LEAK_DETECTOR(CdDrive)
};

CdDrive::CdDrive() :
maxSpeed(100),
discDiameter(5.0f),
numberOfTrays(1)
{
    std::cout << "CdDrive being constructed!" << std::endl;
}

CdDrive::~CdDrive()
{
    std::cout << "CdDrive being destructed!" << std::endl;
}

void CdDrive::playCd()
{
    std::cout << "CdDrive::playCd() " << color << std::endl;
}

void CdDrive::playDVD()
{
    std::cout << "CdDrive::playDVD() maxSpeed:" << maxSpeed << ", discDiameter: " << discDiameter << std::endl;
}

void CdDrive::writeCdr()
{
    std::cout << "Writing CDr in tray " << numberOfTrays << std::endl;
}

void CdDrive::CD::getScratched()
{
    std::cout << "CD " << title << " is getting scratched." << std::endl;
}

void CdDrive::CD::storeData()
{
    std::cout << "CD is storing data at " << maxSpeed << "rpm." << std::endl;
}

void CdDrive::CD::goObsolete()
{
    std::cout << "CD " << title << " is going obsolete." << std::endl;
}

int CdDrive::findSpeed()
{
    int speed = 0;
    for(int i = 97; i < maxSpeed; ++i)
    {
        speed = i;
    }
    return speed;
}

void CdDrive::showMaxSpeed()
{
    std::cout << "CdDrive::showMaxSpeed: " << this->maxSpeed << std::endl;
}

struct CdDriveWrapper
{
    CdDriveWrapper(CdDrive* ptr) : pointerToCdDrive(ptr){}
    ~CdDriveWrapper()
    {
        delete pointerToCdDrive;
    }
    CdDrive* pointerToCdDrive = nullptr;
};


/*
 copied UDT 3:
 */

struct Keyboard
{
    Keyboard();

    ~Keyboard()
    {
        std::cout << "Keyboard being destructed!" << std::endl;
    }

    int numberOfKeys;
    int numberOfFunctionKeys;
    std::string caseColor { "black" };
    std::string buttonColor { "gray" };
    float width = 16.0f;

    void outputButtonPress(int buttonCode); 
    void displayNumLock(); 
    void displayCapsLock(); 
    int buttonPressTime();

    void showButtonColor();

    JUCE_LEAK_DETECTOR(Keyboard)
};

Keyboard::Keyboard() :
numberOfKeys(100),
numberOfFunctionKeys(12)
{
    std::cout << "Keyboard being constructed!" << std::endl;
}

void Keyboard::outputButtonPress(int buttonCode)
{
    ++buttonCode;
    std::cout << "Keyboard::outputButtonPress() " << buttonCode << std::endl;
}

void Keyboard::displayNumLock()
{
    std::cout << "Keyboard::displayNumLock() numberOfKeys:" << numberOfKeys << " numberOfFunctionKeys: " << numberOfFunctionKeys << std::endl;
}

void Keyboard::displayCapsLock()
{
    std::cout << "Keyboard::displayCapsLock() width:" << width << std::endl;
}

int Keyboard::buttonPressTime()
{
    int time = 0;
    for(int i = 0;i < 100; ++i)
    {
        time = i;
    }
    return time;
}

void Keyboard::showButtonColor()
{
    std::cout << "Keyboard::showButtonColor: " << this->buttonColor << std::endl;
}

struct KeyboardWrapper
{
    KeyboardWrapper(Keyboard* ptr) : pointerToKeyboard(ptr){}
    ~KeyboardWrapper()
    {
        delete pointerToKeyboard;
    }
    Keyboard* pointerToKeyboard = nullptr;
};


/*
 new UDT 4:
 with 2 member functions
 */

struct StuffOnMyDesk
{
    StuffOnMyDesk();
    ~StuffOnMyDesk();

    Mp3Player mp3Player;
    Keyboard keyboard;

    int countThings();
    void cleanDesk();

    void showKeyboardCaseColor();

    JUCE_LEAK_DETECTOR(StuffOnMyDesk)
};

StuffOnMyDesk::StuffOnMyDesk()
{
    std::cout << "StuffOnMyDesk constructing" << std::endl;
    std::cout << "mp3Player.numberOfCardSlots: " << mp3Player.numberOfCardSlots << std::endl;
}

StuffOnMyDesk::~StuffOnMyDesk()
{
    std::cout << "StuffOnMyDesk destructing" << std::endl;
    std::cout << "keyboard.width: " << keyboard.width << std::endl;
}

int StuffOnMyDesk::countThings()
{
    return mp3Player.numberOfCardSlots + mp3Player.numberOfButtons + keyboard.numberOfFunctionKeys + keyboard.numberOfKeys;
}

void StuffOnMyDesk::cleanDesk()
{
    mp3Player.onOffSwitchColor = "shiny white";
    keyboard.caseColor = "shiny black";
}

void StuffOnMyDesk::showKeyboardCaseColor()
{
    std::cout << "StuffOnMyDesk::showKeyboardCaseColor: " << this->keyboard.caseColor << std::endl;
}

struct StuffOnMyDeskWrapper
{
    StuffOnMyDeskWrapper(StuffOnMyDesk* ptr) : pointerToStuffOnMyDesk(ptr){}
    ~StuffOnMyDeskWrapper()
    {
        delete pointerToStuffOnMyDesk;
    }
    StuffOnMyDesk* pointerToStuffOnMyDesk = nullptr;
};


/*
 new UDT 5:
 with 2 member functions
 */

struct ThingsToBuy
{
    ThingsToBuy();
    ~ThingsToBuy();

    CdDrive cdDrive;
    Keyboard keyboard;

    int findCdDrivePrice();
    int findKeyboardPrice();

    JUCE_LEAK_DETECTOR(ThingsToBuy)
};

ThingsToBuy::ThingsToBuy()
{
    std::cout << "ThingsToBuy constructing" << std::endl;
}

ThingsToBuy::~ThingsToBuy()
{
    std::cout << "ThingsToBuy destructing" << std::endl;
    keyboard.buttonPressTime();
}
    
int ThingsToBuy::findCdDrivePrice()
{
    if (cdDrive.maxSpeed > 50)
    {
        return 100;
    }
    return 75;
}

int ThingsToBuy::findKeyboardPrice()
{
    if (keyboard.numberOfKeys < 50)
    {
        return 25;
    }
    return 50;
}

struct ThingsToBuyWrapper
{
    ThingsToBuyWrapper(ThingsToBuy* ptr) : pointerToThingsToBuy(ptr){}
    ~ThingsToBuyWrapper()
    {
        delete pointerToThingsToBuy;
    }
    ThingsToBuy* pointerToThingsToBuy = nullptr;
};


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */



int main()
{
    
    Mp3PlayerWrapper mp3PlayerWrapper1(new Mp3Player());
    mp3PlayerWrapper1.pointerToMp3Player->loadFile("music/mysong.mp3");
    mp3PlayerWrapper1.pointerToMp3Player->displayInfo();
    std::cout << "mp3PlayerWrapper1.onOffSwitchColor: " << mp3PlayerWrapper1.pointerToMp3Player->onOffSwitchColor << std::endl;
    mp3PlayerWrapper1.pointerToMp3Player->showOnOffSwitchColor();

    Mp3PlayerWrapper mp3PlayerWrapper2(new Mp3Player());
    mp3PlayerWrapper2.pointerToMp3Player->playFile();
    int mp3FileCount = mp3PlayerWrapper2.pointerToMp3Player->findFiles();
    std::cout << "mp3FileCount: " << mp3FileCount << std::endl;

    CdDriveWrapper cdDriveWrapper1(new CdDrive());
    cdDriveWrapper1.pointerToCdDrive->playCd();
    cdDriveWrapper1.pointerToCdDrive->playDVD();
    cdDriveWrapper1.pointerToCdDrive->writeCdr();
    std::cout << "cdDriveWrapper1.pointerToCdDrive->maxSpeed: " << cdDriveWrapper1.pointerToCdDrive->maxSpeed << std::endl;
    cdDriveWrapper1.pointerToCdDrive->showMaxSpeed();
    int cdDriveSpeed = cdDriveWrapper1.pointerToCdDrive->findSpeed();
    std::cout << "cdDriveWrapper1.pointerToCdDrive-> speed: " << cdDriveSpeed << std::endl;


    //0---------------------------------------------------------------------------------------------------------
    CdDrive::CD darkSide;
    darkSide.getScratched();
    darkSide.storeData();
    darkSide.goObsolete();
    
    Keyboard keyboard1;
    keyboard1.outputButtonPress(23);
    keyboard1.displayNumLock();
    keyboard1.displayCapsLock();
    std::cout << "keyboard1.buttonColor: " << keyboard1.buttonColor << std::endl;
    keyboard1.showButtonColor();
    int buttonTime1 = keyboard1.buttonPressTime();
    std::cout << "buttonTime1: " << buttonTime1 << std::endl;

    StuffOnMyDesk stuffOnThisDesk;
    int deskThingCount = stuffOnThisDesk.countThings();
    std::cout << "deskThingCount: " << deskThingCount << std::endl;
    std::cout << "before clean keyboard color: " << stuffOnThisDesk.keyboard.caseColor << std::endl;
    stuffOnThisDesk.cleanDesk();
    std::cout << "after clean keyboard color: " << stuffOnThisDesk.keyboard.caseColor << std::endl;
    stuffOnThisDesk.showKeyboardCaseColor();
    
    ThingsToBuy buyTheseThings;
    int cdDrivePrice1 = buyTheseThings.findCdDrivePrice();
    std::cout << "cdDrivePrice1: " << cdDrivePrice1 << std::endl;
    int keyboardPrice1 = buyTheseThings.findKeyboardPrice();
    std::cout << "keyboardPrice1: " << keyboardPrice1 << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
