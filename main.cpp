/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
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
    };
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


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Mp3Player mp3Player1;
    mp3Player1.loadFile("music/mysong.mp3");
    mp3Player1.displayInfo();
    std::cout << "mp3Player1.onOffSwitchColor: " << mp3Player1.onOffSwitchColor << std::endl;
    
    Mp3Player mp3Player2;
    mp3Player2.playFile();
    int mp3FileCount = mp3Player2.findFiles();
    std::cout << "mp3FileCount: " << mp3FileCount << std::endl;
     
    CdDrive cdDrive1;
    cdDrive1.playCd();
    cdDrive1.playDVD();
    cdDrive1.writeCdr();
    std::cout << "cdDrive1.maxSpeed: " << cdDrive1.maxSpeed << std::endl;
    int cdDriveSpeed = cdDrive1.findSpeed();
    std::cout << "cdDrive1 speed: " << cdDriveSpeed << std::endl;
    
    CdDrive::CD darkSide;
    darkSide.getScratched();
    darkSide.storeData();
    darkSide.goObsolete();
    
    Keyboard keyboard1;
    keyboard1.outputButtonPress(23);
    keyboard1.displayNumLock();
    keyboard1.displayCapsLock();
    std::cout << "keyboard1.buttonColor: " << keyboard1.buttonColor << std::endl;
    int buttonTime1 = keyboard1.buttonPressTime();
    std::cout << "buttonTime1: " << buttonTime1 << std::endl;

    StuffOnMyDesk stuffOnThisDesk;
    int deskThingCount = stuffOnThisDesk.countThings();
    std::cout << "deskThingCount: " << deskThingCount << std::endl;
    std::cout << "before clean keyboard color: " << stuffOnThisDesk.keyboard.caseColor << std::endl;
    stuffOnThisDesk.cleanDesk();
    std::cout << "after clean keyboard color: " << stuffOnThisDesk.keyboard.caseColor << std::endl;

    ThingsToBuy buyTheseThings;
    int cdDrivePrice1 = buyTheseThings.findCdDrivePrice();
    std::cout << "cdDrivePrice1: " << cdDrivePrice1 << std::endl;
    int keyboardPrice1 = buyTheseThings.findKeyboardPrice();
    std::cout << "keyboardPrice1: " << keyboardPrice1 << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
