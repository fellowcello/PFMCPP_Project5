/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
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

    CdDrive::CD darkSide;
    darkSide.getScratched();
    darkSide.storeData();
    darkSide.goObsolete();

    KeyboardWrapper keyboardWrapper1(new Keyboard());
    keyboardWrapper1.pointerToKeyboard->outputButtonPress(23);
    keyboardWrapper1.pointerToKeyboard->displayNumLock();
    keyboardWrapper1.pointerToKeyboard->displayCapsLock();
    std::cout << "keyboardWrapper1.buttonColor: " << keyboardWrapper1.pointerToKeyboard->buttonColor << std::endl;
    keyboardWrapper1.pointerToKeyboard->showButtonColor();
    int buttonTime1 = keyboardWrapper1.pointerToKeyboard->buttonPressTime();
    std::cout << "buttonTime1: " << buttonTime1 << std::endl;

    StuffOnMyDeskWrapper stuffOnMyDeskWrapper1(new StuffOnMyDesk());
    int deskThingCount = stuffOnMyDeskWrapper1.pointerToStuffOnMyDesk->countThings();
    std::cout << "deskThingCount: " << deskThingCount << std::endl;
    std::cout << "before clean keyboard color: " << stuffOnMyDeskWrapper1.pointerToStuffOnMyDesk->keyboard.caseColor << std::endl;
    stuffOnMyDeskWrapper1.pointerToStuffOnMyDesk->cleanDesk();
    std::cout << "after clean keyboard color: " << stuffOnMyDeskWrapper1.pointerToStuffOnMyDesk->keyboard.caseColor << std::endl;
    stuffOnMyDeskWrapper1.pointerToStuffOnMyDesk->showKeyboardCaseColor();
   
    ThingsToBuyWrapper thingsToBuyWrapper1(new ThingsToBuy());
    int cdDrivePrice1 = thingsToBuyWrapper1.pointerToThingsToBuy->findCdDrivePrice();
    std::cout << "cdDrivePrice1: " << cdDrivePrice1 << std::endl;
    int keyboardPrice1 = thingsToBuyWrapper1.pointerToThingsToBuy->findKeyboardPrice();
    std::cout << "keyboardPrice1: " << keyboardPrice1 << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
